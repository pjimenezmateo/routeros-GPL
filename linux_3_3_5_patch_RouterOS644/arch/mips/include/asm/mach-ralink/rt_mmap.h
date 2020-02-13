/**************************************************************************
 *
 *  BRIEF MODULE DESCRIPTION
 *     register definition for Ralink RT-series SoC
 *
 *  Copyright 2007 Ralink Inc.
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 *  THIS  SOFTWARE  IS PROVIDED   ``AS  IS'' AND   ANY  EXPRESS OR IMPLIED
 *  WARRANTIES,   INCLUDING, BUT NOT  LIMITED  TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 *  NO  EVENT  SHALL   THE AUTHOR  BE    LIABLE FOR ANY   DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *  NOT LIMITED   TO, PROCUREMENT OF  SUBSTITUTE GOODS  OR SERVICES; LOSS OF
 *  USE, DATA,  OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN  CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 *  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  You should have received a copy of the  GNU General Public License along
 *  with this program; if not, write  to the Free Software Foundation, Inc.,
 *  675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *
 **************************************************************************
 */

#ifndef __RALINK_MMAP__
#define __RALINK_MMAP__

#if defined (CONFIG_RALINK_MT7621)

#define RALINK_SYSCTL_BASE		0xBE000000
#define RALINK_TIMER_BASE		0xBE000100
#define RALINK_INTCL_BASE		0xBE000200
#define RALINK_RBUS_MATRIXCTL_BASE	0xBE000400
#define RALINK_MIPS_CNT_BASE		0x1E000500
#define RALINK_PIO_BASE			0xBE000600
#define RALINK_SPDIF_BASE		0xBE000700
#define RALINK_I2C_BASE			0xBE000900
#define RALINK_I2S_BASE			0xBE000A00
#define RALINK_SPI_BASE			0xBE000B00
#define RALINK_UART_LITE1_BASE		0x1E000C00
#define RALINK_UART_LITE_BASE		RALINK_UART_LITE1_BASE
#define RALINK_UART_LITE2_BASE		0x1E000D00
#define RALINK_UART_BASE		RALINK_UART_LITE2_BASE
#define RALINK_UART_LITE3_BASE		0x1E000E00
#define RALINK_ANA_CTRL_BASE		0xBE000F00
#define RALINK_PCM_BASE			0xBE002000
#define RALINK_GDMA_BASE		0xBE002800
#define RALINK_NAND_CTRL_BASE		0xBE003000
#define RALINK_NANDECC_CTRL_BASE	0xBE003800
#define RALINK_CRYPTO_ENGINE_BASE	0xBE004000
#define RALINK_MEMCTRL_BASE		0xBE005000
#define RALINK_EXT_MC_ARB_BASE		0xBE006000
#define RALINK_HS_DMA_BASE		0xBE007000
#define RALINK_FE_BASE			0xBE100000
#define RALINK_PPE_BASE			0xBE100C00
#define RALINK_ETH_SW_BASE		0xBE110000
#define RALINK_ROM_BASE			0xBE118000
#define RALINK_MSDC_BASE		0xBE130000
#define RALINK_PCI_BASE                 0xBE140000
#define RALINK_USB_HOST_BASE		0x1E1C0000
#define RALINK_11N_MAC_BASE		0xBE180000 //Unused

#define RALINK_MCNT_CFG			0xBE000500
#define RALINK_COMPARE			0xBE000504
#define RALINK_COUNT			0xBE000508

//Interrupt Controller
#define RALINK_INTCTL_FE		(1<<3)
#define RALINK_INTCTL_PCIE0		(1<<4)
#define RALINK_INTCTL_SYSCTL		(1<<6)
#define RALINK_INTCTL_I2C		(1<<8)
#define RALINK_INTCTL_DRAMC		(1<<9)
#define RALINK_INTCTL_PCM		(1<<10)
#define RALINK_INTCTL_HSDMA		(1<<11)
#define RALINK_INTCTL_PIO		(1<<12)
#define RALINK_INTCTL_DMA		(1<<13)
#define RALINK_INTCTL_NFI		(1<<14)
#define RALINK_INTCTL_NFIECC		(1<<15)
#define RALINK_INTCTL_I2S		(1<<16)
#define RALINK_INTCTL_SPI		(1<<17)
#define RALINK_INTCTL_SPDIF		(1<<18)
#define RALINK_INTCTL_CRYPTO		(1<<19)
#define RALINK_INTCTL_SDXC		(1<<20)
#define RALINK_INTCTL_PCTRL		(1<<21)
#define RALINK_INTCTL_USB		(1<<22)
#define RALINK_INTCTL_SWITCH		(1<<23)
#define RALINK_INTCTL_PCIE1		(1<<24)
#define RALINK_INTCTL_PCIE2		(1<<25)
#define RALINK_INTCTL_UART1		(1<<26)
#define RALINK_INTCTL_UART2		(1<<27)
#define RALINK_INTCTL_UART3		(1<<28)
#define RALINK_INTCTL_WDTIMER		(1<<29)
#define RALINK_INTCTL_TIMER0		(1<<30)
#define RALINK_INTCTL_TIMER1		(1<<31)


//Reset Control Register
#define RALINK_SYS_RST			(1<<0)
#define RALINK_MCM_RST			(1<<1)
#define RALINK_HSDMA_RST		(1<<2)
#define RALINK_FE_RST			(1<<6)
#define RALINK_SPDIF_RST		(1<<7)
#define RALINK_TIMER_RST		(1<<8)
#define RALINK_INTC_RST			(1<<9)
#define RALINK_MC_RST			(1<<10)
#define RALINK_PCM_RST			(1<<11)
#define RALINK_PIO_RST			(1<<13)
#define RALINK_DMA_RST			(1<<14)
#define RALINK_NAND_RST			(1<<15)
#define RALINK_I2C_RST			(1<<16)
#define RALINK_I2S_RST			(1<<17)
#define RALINK_SPI_RST			(1<<18)
#define RALINK_UART1_RST		(1<<19)
#define RALINK_UART2_RST		(1<<20)
#define RALINK_UART3_RST		(1<<21)
#define RALINK_ETH_RST			(1<<23)
#define RALINK_PCIE0_RST		(1<<24)
#define RALINK_PCIE1_RST		(1<<25)
#define RALINK_PCIE2_RST		(1<<26)
#define RALINK_AUX_STCK_RST		(1<<28)
#define RALINK_CRYPTO_RST		(1<<29)
#define RALINK_SDXC_RST			(1<<30)
#define RALINK_PPE_RST			(1<<31)

//Clock Conf Register
#define RALINK_PCIE0_CLK_EN		(1<<24)
#define RALINK_PCIE1_CLK_EN		(1<<25)
#define RALINK_PCIE2_CLK_EN		(1<<26)
//#define RALINK_UPHY0_CLK_EN		(1<<27)
//#define RALINK_UPHY1_CLK_EN		(1<<28)

//CPU PLL CFG Register
#define CPLL_SW_CONFIG                  (0x1UL << 31)
#define CPLL_MULT_RATIO_SHIFT           16
#define CPLL_MULT_RATIO                 (0x7UL << CPLL_MULT_RATIO_SHIFT)
#define CPLL_DIV_RATIO_SHIFT            10
#define CPLL_DIV_RATIO                  (0x3UL << CPLL_DIV_RATIO_SHIFT)
#define BASE_CLOCK                      40      /* Mhz */

#define RALINK_TESTSTAT			0xBE000018
#define RALINK_TESTSTAT2		0xBE00001C

#endif
#endif
