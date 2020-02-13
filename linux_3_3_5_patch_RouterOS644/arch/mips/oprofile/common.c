/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2004, 2005 Ralf Baechle
 * Copyright (C) 2005 MIPS Technologies, Inc.
 */
#include <linux/compiler.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/oprofile.h>
#include <linux/smp.h>
#include <asm/ptrace.h>
#include <asm/cpu-info.h>
#include <asm/rb/boards.h>

#include "op_impl.h"

extern int __init rb100_oprofile_init(struct oprofile_operations *ops);
extern int __init rb500_oprofile_init(struct oprofile_operations *ops);
extern int __init hrtimer_oprofile_init(struct oprofile_operations *);

extern struct op_mips_model op_model_mipsxx_ops __weak;
extern struct op_mips_model op_model_rm9000_ops __weak;
extern struct op_mips_model op_model_loongson2_ops __weak;

static struct op_mips_model *model;

static struct op_counter_config ctr[20];

static int op_mips_setup(void)
{
	/* Pre-compute the values to stuff in the hardware registers.  */
	model->reg_setup(ctr);

	/* Configure the registers on all cpus.  */
	on_each_cpu(model->cpu_setup, NULL, 1);

        return 0;
}

static int op_mips_create_files(struct super_block *sb, struct dentry *root)
{
	int i;

	for (i = 0; i < model->num_counters; ++i) {
		struct dentry *dir;
		char buf[4];

		snprintf(buf, sizeof buf, "%d", i);
		dir = oprofilefs_mkdir(sb, root, buf);

		oprofilefs_create_ulong(sb, dir, "enabled", &ctr[i].enabled);
		oprofilefs_create_ulong(sb, dir, "event", &ctr[i].event);
		oprofilefs_create_ulong(sb, dir, "count", &ctr[i].count);
		oprofilefs_create_ulong(sb, dir, "kernel", &ctr[i].kernel);
		oprofilefs_create_ulong(sb, dir, "user", &ctr[i].user);
		oprofilefs_create_ulong(sb, dir, "exl", &ctr[i].exl);
		/* Dummy.  */
		oprofilefs_create_ulong(sb, dir, "unit_mask", &ctr[i].unit_mask);
	}

	return 0;
}

static int op_mips_start(void)
{
	on_each_cpu(model->cpu_start, NULL, 1);

	return 0;
}

static void op_mips_stop(void)
{
	/* Disable performance monitoring for all counters.  */
	on_each_cpu(model->cpu_stop, NULL, 1);
}

void mt_op_mips_backtrace(struct pt_regs * const regs, unsigned int depth)
{
	unsigned long ra = regs->regs[31];
	unsigned long pc = regs->cp0_epc;
	unsigned long sp = regs->regs[29];
	int usermode = user_mode(regs);

	while (depth-- && pc) {
	    pc = find_prev_frame(pc, ra, &sp, usermode);
	    if (pc) oprofile_add_trace((unsigned long) pc);
	    ra = 0;
	}
}

int __init oprofile_arch_init(struct oprofile_operations *ops)
{
	struct op_mips_model *lmodel = NULL;
	int res;

	ops->backtrace = mt_op_mips_backtrace;

	if (hrtimer_oprofile_init(ops) == 0)
		return 0;

#ifdef CONFIG_MIPS_MIKROTIK
	switch (mips_machgroup) {
	case MACH_GROUP_MT_RB100:
		return rb100_oprofile_init(ops);
	case MACH_GROUP_MT_RB500:
		return rb500_oprofile_init(ops);
	}
#endif

	switch (current_cpu_type()) {
	case CPU_5KC:
	case CPU_20KC:
	case CPU_24K:
	case CPU_25KF:
	case CPU_34K:
	case CPU_1004K:
	case CPU_74K:
	case CPU_SB1:
	case CPU_SB1A:
	case CPU_R10000:
	case CPU_R12000:
	case CPU_R14000:
		lmodel = &op_model_mipsxx_ops;
		break;

	case CPU_RM9000:
		lmodel = &op_model_rm9000_ops;
		break;
	case CPU_LOONGSON2:
		lmodel = &op_model_loongson2_ops;
		break;
	};

	if (!lmodel)
		return -ENODEV;

	res = lmodel->init();
	if (res)
		return res;

	model = lmodel;

	ops->create_files	= op_mips_create_files;
	ops->setup		= op_mips_setup;
	//ops->shutdown         = op_mips_shutdown;
	ops->start		= op_mips_start;
	ops->stop		= op_mips_stop;
	ops->cpu_type		= lmodel->cpu_type;
	ops->backtrace		= op_mips_backtrace;

	printk(KERN_INFO "oprofile: using %s performance monitoring.\n",
	       lmodel->cpu_type);

	return 0;
}

void oprofile_arch_exit(void)
{
	if (model)
		model->exit();
}
