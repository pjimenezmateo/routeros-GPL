#ifndef __ASM_ARCH_MSM_IRQS_H
#define __ASM_ARCH_MSM_IRQS_H

#define NR_IRQS	16

#define NR_MSM_IRQS 288
#define NR_GPIO_IRQS 152
#define NR_PM8921_IRQS 256
#define NR_PM8821_IRQS 112
#define NR_WCD9XXX_IRQS 49
#define NR_TABLA_IRQS NR_WCD9XXX_IRQS
#define NR_GPIO_EXPANDER_IRQS 64
#define MSM_NUM_PCIE 3
#define NR_PCIE_MSI_IRQS (256 * MSM_NUM_PCIE)
#define NR_BOARD_IRQS (NR_PM8921_IRQS + NR_PM8821_IRQS + \
                NR_WCD9XXX_IRQS + NR_GPIO_EXPANDER_IRQS + NR_PCIE_MSI_IRQS)

#define GIC_PPI_START 16
#define INT_DEBUG_TIMER_EXP	(GIC_PPI_START + 1)
#define INT_GP_TIMER_EXP	(GIC_PPI_START + 2)
#define GIC_SPI_START 32

#define RPM_APCC_CPU0_GP_HIGH_IRQ	(GIC_SPI_START + 19)
#define RPM_APCC_CPU0_GP_MEDIUM_IRQ	(GIC_SPI_START + 20)
#define RPM_APCC_CPU0_GP_LOW_IRQ	(GIC_SPI_START + 21)
#define RPM_APCC_CPU0_WAKE_UP_IRQ	(GIC_SPI_START + 22)

#define RPM_APCC_CPU1_GP_HIGH_IRQ	(GIC_SPI_START + 23)
#define RPM_APCC_CPU1_GP_MEDIUM_IRQ	(GIC_SPI_START + 24)
#define RPM_APCC_CPU1_GP_LOW_IRQ	(GIC_SPI_START + 25)
#define RPM_APCC_CPU1_WAKE_UP_IRQ	(GIC_SPI_START + 26)

#define PM8821_SEC_IRQ_N	(GIC_SPI_START + 15)
#define TLMM_SCSS_SUMMARY_IRQ	(GIC_SPI_START + 16)
#define TLMM_MSM_SUMMARY_IRQ	(GIC_SPI_START + 16)
#define PCIE20_INT_MSI		(GIC_SPI_START + 35)
#define PCIE20_INTA		(GIC_SPI_START + 36)
#define PCIE20_1_INT_MSI	(GIC_SPI_START + 57)
#define PCIE20_1_INTA		(GIC_SPI_START + 58)
#define PCIE20_2_INT_MSI	(GIC_SPI_START + 71)
#define PCIE20_2_INTA		(GIC_SPI_START + 72)
#define LPASS_DML_IRQ		(GIC_SPI_START + 88)
#define LPASS_SPDIFTX_IRQ	(GIC_SPI_START + 89)
#define LPASS_SCSS_GP_HIGH_IRQ	(GIC_SPI_START + 90)
#define USB30_EE1_IRQ_1		(GIC_SPI_START + 110)
#define SPS_MTI_30		(GIC_SPI_START + 137)
#define SPS_MTI_31		(GIC_SPI_START + 138)
#define GSBI5_QUP_IRQ		(GIC_SPI_START + 155)
#define GSBI2_QUP_IRQ		(GIC_SPI_START + 196)
#define ADM_0_SCSS_0_IRQ	(GIC_SPI_START + 170)
#define USB1_HS_IRQ		(GIC_SPI_START + 100)
#define USB3_HS_IRQ		(GIC_SPI_START + 188)
#define USB30_EE1_IRQ		(GIC_SPI_START + 205)
#define USB4_HS_IRQ		(GIC_SPI_START + 215)

#define MSM_PCIE_MSI_INT(n) (NR_MSM_IRQS + NR_GPIO_IRQS + NR_PM8921_IRQS +  \
                NR_PM8821_IRQS + NR_TABLA_IRQS + NR_GPIO_EXPANDER_IRQS + (n))
#define MSM_GPIO_TO_INT(n) (NR_MSM_IRQS + (n))

#endif
