/*******************************************************************************
Copyright (C) 2013 Annapurna Labs Ltd.

This file may be licensed under the terms of the Annapurna Labs Commercial
License Agreement.

Alternatively, this file can be distributed under the terms of the GNU General
Public License V2 as published by the Free Software Foundation and can be
found at http://www.gnu.org/licenses/gpl-2.0.html

Alternatively, redistribution and use in source and binary forms, with or
without modification, are permitted provided that the following conditions are
met:

    *     Redistributions of source code must retain the above copyright notice,
	  this list of conditions and the following disclaimer.

    *     Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in
	  the documentation and/or other materials provided with the
	  distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/

/**
 * @file   al_hal_udma_regs_gen.h
 *
 * @brief C Header file for the UDMA general registers
 *
 */

#ifndef __AL_HAL_UDMA_GEN_REG_H
#define __AL_HAL_UDMA_GEN_REG_H

#include "al_hal_udma_iofic_regs.h"

#ifdef __cplusplus
extern "C" {
#endif
/*
* Unit Registers
*/

struct udma_gen_dma_misc {
	/* [0x0] Reserved register for the interrupt controller */
	uint32_t int_cfg;
	/* [0x4] Revision register */
	uint32_t revision;
	/* [0x8] Reserved for future use */
	uint32_t general_cfg_1;
	/* [0xc] Reserved for future use */
	uint32_t general_cfg_2;
	/* [0x10] Reserved for future use */
	uint32_t general_cfg_3;
	/* [0x14] Reserved for future use */
	uint32_t general_cfg_4;
	/* [0x18] General timer configuration */
	uint32_t general_cfg_5;
	uint32_t rsrvd[57];
};

struct udma_gen_mailbox {
	/* [0x0] Mailbox interrupt generator */
	uint32_t interrupt;
	/* [0x4] Mailbox message data out */
	uint32_t msg_out;
	/* [0x8] Mailbox message data in */
	uint32_t msg_in;
	uint32_t rsrvd[13];
};

struct udma_gen_axi {
	/* [0x0] Configuration of the AXI masters */
	uint32_t cfg_1;
	/* [0x4] Configuration of the AXI masters */
	uint32_t cfg_2;
	/* [0x8] Configuration of the AXI masters */
	uint32_t endian_cfg;
	uint32_t rsrvd[61];
};

struct udma_gen_sram_ctrl {
	/* [0x0] Timing configuration */
	uint32_t timing;
};

struct udma_gen_vmid {
	/* [0x0] VMID control */
	uint32_t cfg_vmid_0;
	/* [0x4] TX queue 0/1 VMID */
	uint32_t cfg_vmid_1;
	/* [0x8] TX queue 2/3 VMID */
	uint32_t cfg_vmid_2;
	/* [0xc] RX queue 0/1 VMID */
	uint32_t cfg_vmid_3;
	/* [0x10] RX queue 2/3 VMID */
	uint32_t cfg_vmid_4;
};

struct udma_gen_regs {
	struct udma_iofic_regs interrupt_regs;					/* [0x0000] */
	struct udma_gen_dma_misc dma_misc;                   /* [0x2080] */
	struct udma_gen_mailbox mailbox[4];                  /* [0x2180] */
	struct udma_gen_axi axi;                             /* [0x2280] */
	struct udma_gen_sram_ctrl sram_ctrl[25];             /* [0x2380] */
	uint32_t rsrvd_1[2];
	struct udma_gen_vmid vmid;                           /* [0x23ec] */
};


/*
* Registers Fields
*/


/**** int_cfg register ****/
/* MSIX data width
1 - 64 bit
0 – 32 bit */
#define UDMA_GEN_DMA_MISC_INT_CFG_MSIX_64 (1 << 0)
/* General configuration */
#define UDMA_GEN_DMA_MISC_INT_CFG_RESERVED_3_1_MASK 0x0000000E
#define UDMA_GEN_DMA_MISC_INT_CFG_RESERVED_3_1_SHIFT 1
/* MSIx AXI QoS */
#define UDMA_GEN_DMA_MISC_INT_CFG_MSIX_AXI_QOS_MASK 0x00000070
#define UDMA_GEN_DMA_MISC_INT_CFG_MSIX_AXI_QOS_SHIFT 4

#define UDMA_GEN_DMA_MISC_INT_CFG_RESERVED_31_7_MASK 0xFFFFFF80
#define UDMA_GEN_DMA_MISC_INT_CFG_RESERVED_31_7_SHIFT 7

/**** revision register ****/
/* Design programming interface  revision ID */
#define UDMA_GEN_DMA_MISC_REVISION_PROGRAMMING_ID_MASK 0x00000FFF
#define UDMA_GEN_DMA_MISC_REVISION_PROGRAMMING_ID_SHIFT 0
/* Design minor revision ID */
#define UDMA_GEN_DMA_MISC_REVISION_MINOR_ID_MASK 0x00FFF000
#define UDMA_GEN_DMA_MISC_REVISION_MINOR_ID_SHIFT 12
/* Design major revision ID */
#define UDMA_GEN_DMA_MISC_REVISION_MAJOR_ID_MASK 0xFF000000
#define UDMA_GEN_DMA_MISC_REVISION_MAJOR_ID_SHIFT 24

/**** Interrupt register ****/
/* Generate interrupt to another DMA */
#define UDMA_GEN_MAILBOX_INTERRUPT_SET   (1 << 0)

/**** cfg_2 register ****/
/* Enable arbitration promotion */
#define UDMA_GEN_AXI_CFG_2_ARB_PROMOTION_MASK 0x0000000F
#define UDMA_GEN_AXI_CFG_2_ARB_PROMOTION_SHIFT 0

/**** endian_cfg register ****/
/* Swap M2S descriptor read and completion descriptor write.  */
#define UDMA_GEN_AXI_ENDIAN_CFG_SWAP_M2S_DESC (1 << 0)
/* Swap M2S data read. */
#define UDMA_GEN_AXI_ENDIAN_CFG_SWAP_M2S_DATA (1 << 1)
/* Swap S2M descriptor read and completion descriptor write.  */
#define UDMA_GEN_AXI_ENDIAN_CFG_SWAP_S2M_DESC (1 << 2)
/* Swap S2M data write. */
#define UDMA_GEN_AXI_ENDIAN_CFG_SWAP_S2M_DATA (1 << 3)
/* Swap 32 or 64 bit mode:0 - Swap groups of 4 bytes1 - Swap gro ... */
#define UDMA_GEN_AXI_ENDIAN_CFG_SWAP_64B_EN (1 << 4)

/**** timing register ****/
/* Write margin */
#define UDMA_GEN_SRAM_CTRL_TIMING_RMA_MASK 0x0000000F
#define UDMA_GEN_SRAM_CTRL_TIMING_RMA_SHIFT 0
/* Write margin enable */
#define UDMA_GEN_SRAM_CTRL_TIMING_RMEA   (1 << 8)
/* Read margin */
#define UDMA_GEN_SRAM_CTRL_TIMING_RMB_MASK 0x000F0000
#define UDMA_GEN_SRAM_CTRL_TIMING_RMB_SHIFT 16
/* Read margin enable */
#define UDMA_GEN_SRAM_CTRL_TIMING_RMEB   (1 << 24)

/**** cfg_vmid_0 register ****/
/* For M2S queues 3:0, enable usage of the VMID from the buffer  ... */
#define UDMA_GEN_VMID_CFG_VMID_0_TX_Q_VMID_DESC_EN_MASK 0x0000000F
#define UDMA_GEN_VMID_CFG_VMID_0_TX_Q_VMID_DESC_EN_SHIFT 0
/* For M2S queues 3:0, enable usage of the VMID from the configu ... */
#define UDMA_GEN_VMID_CFG_VMID_0_TX_Q_VMID_QUEUE_EN_MASK 0x000000F0
#define UDMA_GEN_VMID_CFG_VMID_0_TX_Q_VMID_QUEUE_EN_SHIFT 4
/* use VMID_n [7:0] from MSI-X Controller for MSI-X message  */
#define UDMA_GEN_VMID_CFG_VMID_0_MSIX_VMID_SEL (1 << 8)
/* Enable write to all VMID_n registers in the MSI-X Controller */
#define UDMA_GEN_VMID_CFG_VMID_0_MSIX_VMID_ACCESS_EN (1 << 9)
/* For S2M queues 3:0, enable usage of the VMID from the buffer  ... */
#define UDMA_GEN_VMID_CFG_VMID_0_RX_Q_VMID_DESC_EN_MASK 0x000F0000
#define UDMA_GEN_VMID_CFG_VMID_0_RX_Q_VMID_DESC_EN_SHIFT 16
/* For MS2M queues 3:0, enable usage of the VMID from the config ... */
#define UDMA_GEN_VMID_CFG_VMID_0_RX_Q_VMID_QUEUE_EN_MASK 0x00F00000
#define UDMA_GEN_VMID_CFG_VMID_0_RX_Q_VMID_QUEUE_EN_SHIFT 20

/**** cfg_vmid_1 register ****/
/* TX queue 0 VMID value */
#define UDMA_GEN_VMID_CFG_VMID_1_TX_Q_0_VMID_MASK 0x0000FFFF
#define UDMA_GEN_VMID_CFG_VMID_1_TX_Q_0_VMID_SHIFT 0
/* TX queue 1 VMID value */
#define UDMA_GEN_VMID_CFG_VMID_1_TX_Q_1_VMID_MASK 0xFFFF0000
#define UDMA_GEN_VMID_CFG_VMID_1_TX_Q_1_VMID_SHIFT 16

/**** cfg_vmid_2 register ****/
/* TX queue 2 VMID value */
#define UDMA_GEN_VMID_CFG_VMID_2_TX_Q_2_VMID_MASK 0x0000FFFF
#define UDMA_GEN_VMID_CFG_VMID_2_TX_Q_2_VMID_SHIFT 0
/* TX queue 3 VMID value */
#define UDMA_GEN_VMID_CFG_VMID_2_TX_Q_3_VMID_MASK 0xFFFF0000
#define UDMA_GEN_VMID_CFG_VMID_2_TX_Q_3_VMID_SHIFT 16

/**** cfg_vmid_3 register ****/
/* RX queue 0 VMID value */
#define UDMA_GEN_VMID_CFG_VMID_3_RX_Q_0_VMID_MASK 0x0000FFFF
#define UDMA_GEN_VMID_CFG_VMID_3_RX_Q_0_VMID_SHIFT 0
/* RX queue 1 VMID value */
#define UDMA_GEN_VMID_CFG_VMID_3_RX_Q_1_VMID_MASK 0xFFFF0000
#define UDMA_GEN_VMID_CFG_VMID_3_RX_Q_1_VMID_SHIFT 16

/**** cfg_vmid_4 register ****/
/* RX queue 2 VMID value */
#define UDMA_GEN_VMID_CFG_VMID_4_RX_Q_2_VMID_MASK 0x0000FFFF
#define UDMA_GEN_VMID_CFG_VMID_4_RX_Q_2_VMID_SHIFT 0
/* RX queue 3 VMID value */
#define UDMA_GEN_VMID_CFG_VMID_4_RX_Q_3_VMID_MASK 0xFFFF0000
#define UDMA_GEN_VMID_CFG_VMID_4_RX_Q_3_VMID_SHIFT 16

#ifdef __cplusplus
}
#endif

#endif /* __AL_HAL_UDMA_GEN_REG_H */