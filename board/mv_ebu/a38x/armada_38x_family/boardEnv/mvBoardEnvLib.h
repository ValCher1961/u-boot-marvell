/*******************************************************************************
   Copyright (C) Marvell International Ltd. and its affiliates

   This software file (the "File") is owned and distributed by Marvell
   International Ltd. and/or its affiliates ("Marvell") under the following
   alternative licensing terms.  Once you have made an election to distribute the
   File under one of the following license alternatives, please (i) delete this
   introductory statement regarding license alternatives, (ii) delete the two
   license alternatives that you have not elected to use and (iii) preserve the
   Marvell copyright notice above.

********************************************************************************
   Marvell Commercial License Option

   If you received this File from Marvell and you have entered into a commercial
   license agreement (a "Commercial License") with Marvell, the File is licensed
   to you under the terms of the applicable Commercial License.

********************************************************************************
   Marvell GPL License Option

   If you received this File from Marvell, you may opt to use, redistribute and/or
   modify this File in accordance with the terms and conditions of the General
   Public License Version 2, June 1991 (the "GPL License"), a copy of which is
   available along with the File in the license.txt file or by writing to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 or
   on the worldwide web at http://www.gnu.org/licenses/gpl.txt.

   THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE IMPLIED
   WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY
   DISCLAIMED.  The GPL License provides additional details about this warranty
   disclaimer.
********************************************************************************
   Marvell BSD License Option

   If you received this File from Marvell, you may opt to use, redistribute and/or
   modify this File under the following licensing terms.
   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:

*   Redistributions of source code must retain the above copyright notice,
            this list of conditions and the following disclaimer.

*   Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

*   Neither the name of Marvell nor the names of its contributors may be
        used to endorse or promote products derived from this software without
        specific prior written permission.

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

#ifndef __INCmvBoardEnvLibh
#define __INCmvBoardEnvLibh

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines */
/* The below constant macros defines the board I2C EEPROM data offsets */

#include "ctrlEnv/mvCtrlEnvLib.h"
#include "mvSysHwConfig.h"
#include "boardEnv/mvBoardEnvSpec.h"
#include "twsi/mvTwsi.h"
#include "nfc/mvNfc.h"

#ifdef CONFIG_ARMADA_38X
#include "boardEnv/mvBoardEnvLib38x.h"
#elif defined CONFIG_ARMADA_39X
#include "boardEnv/mvBoardEnvLib39x.h"
#endif

#define ARRSZ(x)                (sizeof(x) / sizeof(x[0]))
#define BOARD_ETH_SWITCH_PORT_NUM       7
#define BOARD_ETH_SWITCH_SMI_SCAN_MODE	1	/* Use manual scanning mode */
#define MV_BOARD_MAX_MPP                59       /* number of MPP conf registers */
#define MV_BOARD_MAX_MPP_GROUPS         9
#define MV_BOARD_MPP_GROUPS_MAX_TYPES   8
#define MV_BOARD_NAME_LEN               0x20
#define MV_A38X_Z_REV_BOARDID_I2C_ADDR	0x50

typedef enum _devBoardOtherTypeClass {
	MV_BOARD_NONE		= 0x00000000,
	MV_BOARD_SPDIF		= 0x00000001,
	MV_BOARD_I2S		= 0x00000002,
	MV_BOARD_TDM		= 0x00000004,
	MV_BOARD_MII		= 0x00000008,
	MV_BOARD_SGMII		= 0x00000010,
	MV_BOARD_SERDES_MUX	= 0x00000020,
	MV_BOARD_NOR		= 0x00000040,
	MV_BOARD_NAND16BIT	= 0x00000080,
	MV_BOARD_SDIO4BIT	= 0x00000100,
	MV_BOARD_UNKNOWN	= 0x80000000
} MV_BOARD_OTHER_TYPE_CLASS;


typedef enum _devBoardClass {
	BOARD_DEV_NOR_FLASH,
	BOARD_DEV_NAND_FLASH,
	BOARD_DEV_SEVEN_SEG,
	BOARD_DEV_FPGA,
	BOARD_DEV_SRAM,
	BOARD_DEV_SPI_FLASH,
	BOARD_DEV_OTHER
} MV_BOARD_DEV_CLASS;

typedef enum _devTwsiBoardClass {
	BOARD_DEV_TWSI_SATR,
	BOARD_TWSI_MODULE_DETECT,
	BOARD_TWSI_IO_EXPANDER,
	BOARD_DEV_TWSI_EEPROM,
	BOARD_TWSI_OTHER
} MV_BOARD_TWSI_CLASS;

typedef enum _devGppBoardClass {
	BOARD_GPP_RTC,
	BOARD_GPP_MV_SWITCH,
	BOARD_GPP_USB_VBUS,
	BOARD_GPP_USB_VBUS_EN,
	BOARD_GPP_USB_OC,
	BOARD_GPP_USB_HOST_DEVICE,
	BOARD_GPP_REF_CLCK,
	BOARD_GPP_VOIP_SLIC,
	BOARD_GPP_LIFELINE,
	BOARD_GPP_BUTTON,
	BOARD_GPP_TS_BUTTON_C,
	BOARD_GPP_TS_BUTTON_U,
	BOARD_GPP_TS_BUTTON_D,
	BOARD_GPP_TS_BUTTON_L,
	BOARD_GPP_TS_BUTTON_R,
	BOARD_GPP_POWER_BUTTON,
	BOARD_GPP_RESTOR_BUTTON,
	BOARD_GPP_WPS_BUTTON,
	BOARD_GPP_HDD0_POWER,
	BOARD_GPP_HDD1_POWER,
	BOARD_GPP_FAN_POWER,
	BOARD_GPP_RESET,
	BOARD_GPP_POWER_ON_LED,
	BOARD_GPP_HDD_POWER,
	BOARD_GPP_SDIO_POWER,
	BOARD_GPP_SDIO_DETECT,
	BOARD_GPP_SDIO_WP,
	BOARD_GPP_SWITCH_PHY_INT,
	BOARD_GPP_TSU_DIRCTION,
	BOARD_GPP_PEX_RESET,
	BOARD_GPP_CONF,
	BOARD_GPP_PON_XVR_TX,
	BOARD_GPP_SYS_LED,
	BOARD_GPP_PON_LED,
	BOARD_GPP_OTHER
} MV_BOARD_GPP_CLASS;

typedef enum _mvModuleTypeID {
	MV_MODULE_NO_MODULE			= 0x000,	/* MII board SLM 1362	*/
	MV_MODULE_MII				= BIT0,	/* MII board SLM 1362	*/
	MV_MODULE_SLIC_TDM_DEVICE		= BIT1,	/* TDM board SLM 1360	*/
	MV_MODULE_I2S_DEVICE			= BIT2,	/* I2S board SLM 1360	*/
	MV_MODULE_SPDIF_DEVICE			= BIT3,	/* SPDIF board SLM 1360	*/
	MV_MODULE_NOR				= BIT4,	/* NOR board SLM 1361	*/
	MV_MODULE_NAND				= BIT5,	/* NAND board SLM 1361	*/
	MV_MODULE_SDIO				= BIT6,	/* SDIO board SLM 1361	*/
	MV_MODULE_SGMII				= BIT7,	/* SGMII board SLM 1364	*/
	MV_MODULE_DB381_SGMII			= BIT8,	/* DB-381 SGMII SLM 1426 */
	MV_MODULE_SWITCH			= BIT9,/* SWITCH board SLM 1375	*/
	MV_MODULE_NAND_ON_BOARD			= BIT10,	/* ON board nand - detected via S@R bootsrc */
	MV_MODULE_DB381_MMC_8BIT_ON_BOARD	= BIT11,/* ON board MMC 8bit - detected via S@R bootsrc */
	MV_MODULE_TYPE_MAX_MODULE		= 10,
	MV_MODULE_TYPE_MAX_OPTION		= 11
} MV_MODULE_TYPE_ID;

typedef struct _devCsInfo {
	MV_U8 deviceCS;
	MV_U32 params;
	MV_U32 devClass;        /* MV_BOARD_DEV_CLASS */
	MV_U8 devWidth;
	MV_U8 busWidth;
	MV_U8 busNum;
	MV_BOOL active;
} MV_DEV_CS_INFO;

struct MV_BOARD_SWITCH_INFO {
	MV_BOOL isEnabled;
	MV_BOOL isCpuPortRgmii;
	MV_32 switchIrq;
	MV_32 switchPort[BOARD_ETH_SWITCH_PORT_NUM];
	MV_32 cpuPort;
	MV_32 connectedPort[MV_ETH_MAX_PORTS];
	MV_32 smiScanMode;
	MV_32 quadPhyAddr;
	MV_U32 forceLinkMask; /* Bitmask of switch ports to have force link (1Gbps) */
};

typedef enum _SatRstatus {
	SATR_READ_ONLY = 0x01,
	SATR_SWAP_BIT  = 0x02,
} MV_BOARD_SATR_STATUS;

typedef struct _boardLedInfo {
	MV_U8 activeLedsNumber;
	MV_U8 ledsPolarity;     /* '0' or '1' to turn on led */
	MV_U8 *gppPinNum;       /* Pointer to GPP values */
} MV_BOARD_LED_INFO;

typedef struct _boardGppInfo {
	MV_BOARD_GPP_CLASS devClass;
	MV_U8 gppPinNum;
} MV_BOARD_GPP_INFO;

typedef enum _mvIoExpanderTypeID {
	MV_IO_EXPANDER_USB_VBUS,
	MV_IO_EXPANDER_MAX_OPTION
} MV_IO_EXPANDER_TYPE_ID;

typedef struct _boardIoExapnderTypesInfo {
	MV_IO_EXPANDER_TYPE_ID ioFieldid;
	MV_U32 offset;
	MV_U32 expanderNum;
	MV_U32 regNum;
} MV_BOARD_IO_EXPANDER_TYPE_INFO;

typedef struct _boardTwsiInfo {
	MV_BOARD_TWSI_CLASS devClass;
	MV_U8 devClassId;
	MV_U8 twsiDevAddr;
	MV_U8 twsiDevAddrType;
	MV_U8 moreThen256;
} MV_BOARD_TWSI_INFO;

typedef struct _boardSatrInfo {
	char name[20];
	MV_SATR_TYPE_ID satrId;
	MV_U32 mask;
	MV_U32 bitOffset;
	MV_U32 devClassId;
	MV_U32 regOffset;
	MV_U32 isActiveForBoard[MV_MARVELL_BOARD_NUM];
	MV_BOARD_SATR_STATUS status;
} MV_BOARD_SATR_INFO;

typedef struct _moudleTypesInfo {
	MV_MODULE_TYPE_ID configId;
	MV_U32 twsiAddr;
	MV_U32 offset;
	MV_U32 twsiId;
	MV_U32 isActiveForBoard[MV_MARVELL_BOARD_NUM];
} MV_MODULE_TYPE_INFO;


typedef struct _boardMppInfo {
	MV_U32 mppGroup[MV_BOARD_MAX_MPP];
} MV_BOARD_MPP_INFO;

typedef struct _boardNetComplexInfo {
	MV_U32 netComplexOpt;
} MV_BOARD_NET_COMPLEX_INFO;

typedef enum {
	BOARD_EPON_CONFIG,
	BOARD_GPON_CONFIG,
	BOARD_PON_NONE,
	BOARD_PON_AUTO
} MV_BOARD_PON_CONFIG;

typedef struct {
	MV_U8 spiCs;
} MV_BOARD_TDM_INFO;

typedef struct _boardPexInfo {
	MV_PEXIF_INDX	pexMapping[MV_PEX_MAX_IF];
	MV_PEX_UNIT_CFG	pexUnitCfg[MV_PEX_MAX_UNIT];
	MV_U32		boardPexIfNum;
} MV_BOARD_PEX_INFO;

typedef enum _devBoardSlicType {
	MV_BOARD_SLIC_DISABLED,
	MV_BOARD_SLIC_SSI_ID, /* Lantiq Integrated SLIC */
	MV_BOARD_SLIC_ISI_ID, /* Silicon Labs ISI Bus */
	MV_BOARD_SLIC_ZSI_ID, /* Zarlink ZSI Bus */
	MV_BOARD_SLIC_EXTERNAL_ID /* Cross vendor external SLIC */
} MV_BOARD_SLIC_TYPE;

typedef struct {
	MV_U8 spiId;
} MV_BOARD_TDM_SPI_INFO;

typedef enum {
	BOARD_SLIC_880 = 0,
	BOARD_SLIC_792,
	BOARD_SLIC_SSI,
	BOARD_SLIC_ISI,
	BOARD_SLIC_ZSI,
	BOARD_TDM_SLIC_COUNT
} MV_BOARD_TDM_SLIC_TYPE;

/* Board specific initialization. Performed before initializing the SoC. */
typedef struct {
	MV_U32 reg;
	MV_U32 mask;
	MV_U32 val;
} MV_BOARD_SPEC_INIT;

struct MV_BOARD_IO_EXPANDER {
	MV_U8 addr;
	MV_U8 offset;
	MV_U8 val;
};

typedef enum {
	NAND_IF_NFC,
	NAND_IF_SPI,
	NAND_IF_NONE
} MV_NAND_IF_MODE;

typedef struct {
	MV_UNIT_ID usbType;
	MV_U8 usbPortNum;
	MV_BOOL isActive;
} MV_BOARD_USB_INFO;

typedef struct _boardInfo {
	char boardName[MV_BOARD_NAME_LEN];
	char compatibleDTName[MV_BOARD_NAME_LEN]; /* string for LSP Device Tree usage */
	MV_U8 numBoardNetComplexValue;
	MV_BOARD_NET_COMPLEX_INFO *pBoardNetComplexInfo;
	MV_U8 numBoardMppConfigValue;
	MV_BOARD_MPP_INFO *pBoardMppConfigValue;
	MV_U32 intsGppMaskLow;
	MV_U32 intsGppMaskMid;
	MV_U32 intsGppMaskHigh;
	MV_U8 numBoardDeviceIf;
	MV_DEV_CS_INFO *pDevCsInfo;
	MV_U8 numBoardTwsiDev;
	MV_BOARD_TWSI_INFO *pBoardTwsiDev;
	MV_U8 numBoardMacInfo;
	MV_BOARD_MAC_INFO *pBoardMacInfo;
	MV_U8 numBoardGppInfo;
	MV_BOARD_GPP_INFO *pBoardGppInfo;
	MV_U8 numBoardIoExpPinInfo;
	MV_BOARD_IO_EXPANDER_TYPE_INFO *pBoardIoExpPinInfo;

	MV_U8 activeLedsNumber;
	MV_U8 *pLedGppPin;
	MV_U8 ledsPolarity;     /* '0' or '1' to turn on led */

	MV_U8 pmuPwrUpPolarity;
	MV_U32 pmuPwrUpDelay;
	/* GPP values */
	MV_U32 gppOutEnValLow;
	MV_U32 gppOutEnValMid;
	MV_U32 gppOutEnValHigh;
	MV_U32 gppOutValLow;
	MV_U32 gppOutValMid;
	MV_U32 gppOutValHigh;
	MV_U32 gppPolarityValLow;
	MV_U32 gppPolarityValMid;
	MV_U32 gppPolarityValHigh;
	MV_VOID (*gppPostConfigCallBack) (struct _boardInfo *);

	MV_BOARD_USB_INFO *pBoardUsbInfo;	/* usb2.0 and usb3.0 physical port mapping on board */
	MV_U8 numBoardUsbInfo;

	/* PON configuration. */
	MV_BOARD_PON_CONFIG ponConfigValue;
	/* TDM configuration:
	 * We hold a different configuration array for each possible slic that
	 * can be connected to board.
	 * When modules are scanned, then we select the index of the relevant
	 * slic's information array.
	 * For RD and Customers boards we only need to initialize a single
	 * entry of the arrays below, and set the boardTdmInfoIndex to 0.
	 */
	MV_U8 numBoardTdmInfo[BOARD_TDM_SLIC_COUNT];
	MV_BOARD_TDM_INFO *pBoardTdmInt2CsInfo[BOARD_TDM_SLIC_COUNT];
	MV_16 boardTdmInfoIndex;

	/* Board specific initialization. Performed before initializing the SoC. */
	MV_BOARD_SPEC_INIT      *pBoardSpecInit;
	/* Deep-Idle power up delay */
	MV_U32 deepIdlePwrUpDelay;

	/* NAND init params */
	MV_U32 nandFlashReadParams;
	MV_U32 nandFlashWriteParams;
	MV_U32 nandFlashControl;
	MV_NAND_IF_MODE nandIfMode;

	MV_BOARD_TDM_SPI_INFO *pBoardTdmSpiInfo;
	MV_BOARD_PEX_INFO boardPexInfo;         /* filled in runtime */
	MV_U32 norFlashReadParams;
	MV_U32 norFlashWriteParams;

	MV_BOOL isSdMmcConnected;	/* indicate SD/MMC card reader on board */
	MV_BOOL isSdMmc_1_8v_Connected;	/* indicate SD/MMC card reader connected to 1.8v power supply on board */

	MV_U8 *picGpioInfo;			/* integer array to indicate PIC MPP numbers */
	MV_U8 numPicGpioInfo;

	/* Indicates if auto-detection of modules is enabled on this board. */
	/* Set to MV_FALSE for any board that is not a DB. */
	MV_BOOL configAutoDetect;
	MV_U32	numIoExp;
	struct MV_BOARD_IO_EXPANDER *pIoExp;
	MV_U32  boardOptionsModule;
	MV_BOOL isAmc;			/* AMC active: used for DT update & switching services */
	MV_BOOL isAudioConnected;	/* indicates if SPDIF/I2S is connected */
	MV_BOOL isTdmConnected;		/* indicates if TDM module is connected */
	/* External Switch Configuration */
	struct MV_BOARD_SWITCH_INFO *pSwitchInfo;
	MV_U32 switchInfoNum;
} MV_BOARD_INFO;

struct _mvBoardMppModule {
	MV_U32 group;
	MV_U32 mppValue;
};


#define MPP_MII_MODULE		{ {0, 0x10111111}, {1, 0x11111111}, {2, 0x11211111} }
#define MPP_TDM_MODULE		{ {6, 0x55333333}, {7, 0x00004444} }
#define MPP_AUDIO_MODULE	{6, 0x55444444}
#define MPP_NOR_MODULE		{ {0, 0x55111111}, {1, 0x15555555}, {2, 0x55566011}, \
				  {3, 0x55555055}, {4, 0x55555555}, {5, 0x40045525 } }
#define MPP_NAND_MODULE		{ {0, 0x55111111}, {1, 0x15555555}, {2, 0x55266011}, \
				  {3, 0x25255051}, {4, 0x25555555}, {5, 0x40042555 } }
#define MPP_SDIO_MODULE		{ {2, 0x11466011}, {3, 0x22242011}, {4, 0x44400002}, {5, 0x40042024 } }
#define MPP_NAND_ON_BOARD	{ {2, 0x55266011}, {3, 0x25252051}, {4, 0x25255555}, {5, 0x40042565 } }
#define MPP_GP_MINI_PCIE0	{2, 0x11240011}
#define MPP_GP_MINI_PCIE1	{2, 0x11204011}
#define MPP_GP_MINI_PCIE0_PCIE1	{2, 0x11200011}
#define MPP_MMC_DB381_MODULE	{3, 0x00044444}

/* Boot device bus width */
#define MSAR_0_BOOT_DEV_BUS_WIDTH_OFFS          3
/* Bus width field meaning for NOR/NAND */
#define MSAR_0_BOOT_DEV_BUS_WIDTH_8BIT          (0x0 << MSAR_0_BOOT_DEV_BUS_WIDTH_OFFS)
#define MSAR_0_BOOT_DEV_BUS_WIDTH_16BIT         (0x1 << MSAR_0_BOOT_DEV_BUS_WIDTH_OFFS)
#define MSAR_0_BOOT_DEV_BUS_WIDTH_32BIT         (0x2 << MSAR_0_BOOT_DEV_BUS_WIDTH_OFFS)
/* Bus width field meaning for SPI */
#define MSAR_0_BOOT_DEV_BUS_WIDTH_SPI_24BIT		(0x1 << MSAR_0_BOOT_DEV_BUS_WIDTH_OFFS)
#define MSAR_0_BOOT_DEV_BUS_WIDTH_SPI_32BIT     (0x0 << MSAR_0_BOOT_DEV_BUS_WIDTH_OFFS)

/* NAND page size */
#define MSAR_0_NAND_PAGE_SZ_OFFS                11
#define MSAR_0_NAND_PAGE_SZ_512B                (0x0 << MSAR_0_NAND_PAGE_SZ_OFFS)
#define MSAR_0_NAND_PAGE_SZ_2KB                 (0x1 << MSAR_0_NAND_PAGE_SZ_OFFS)
#define MSAR_0_NAND_PAGE_SZ_4KB                 (0x2 << MSAR_0_NAND_PAGE_SZ_OFFS)
#define MSAR_0_NAND_PAGE_SZ_8KB                 (0x3 << MSAR_0_NAND_PAGE_SZ_OFFS)

/* NAND ECC */
#define MSAR_0_NAND_ECC_OFFS                    14
#define MSAR_0_NAND_ECC_4BIT                    (0x0 << MSAR_0_NAND_ECC_OFFS)
#define MSAR_0_NAND_ECC_8BIT                    (0x1 << MSAR_0_NAND_ECC_OFFS)
#define MSAR_0_NAND_ECC_12BIT                   (0x2 << MSAR_0_NAND_ECC_OFFS)
#define MSAR_0_NAND_ECC_16BIT                   (0x3 << MSAR_0_NAND_ECC_OFFS)

#define MSAR_0_SPI0                             0
#define MSAR_0_SPI1                             1

/* definition for switch device scan mode */
#define MV_SWITCH_SMI_AUTO_SCAN_MODE         0    /* Scan 0 or 0x10 base address to find the QD */
#define MV_SWITCH_SMI_MANUAL_MODE            1    /* Use QD located at manually defined base addr */
#define MV_SWITCH_SMI_MULTI_ADDR_MODE        2    /* Use QD at base addr and use indirect access */

MV_VOID mvBoardEnvInit(MV_VOID);
MV_U16 mvBoardModelGet(MV_VOID);
MV_U32 mvBoardRevGet(MV_VOID);
MV_STATUS mvBoardNameGet(char *pNameBuff, MV_U32 size);
MV_BOARD_SPEC_INIT *mvBoardSpecInitGet(MV_VOID);
MV_U32 mvBoardPortTypeGet(MV_U32 ethPortNum);
MV_BOOL mvBoardIsPortInSgmii(MV_U32 ethPortNum);
MV_BOOL mvBoardIsPortInGmii(MV_U32 ethPortNum);
MV_BOOL mvBoardIsPortInMii(MV_U32 ethPortNum);
MV_BOOL mvBoardIsPortInRgmii(MV_U32 ethPortNum);
MV_BOOL mvBoardIsPortLoopback(MV_U32 ethPortNum);
MV_VOID mvBoardModuleConfigSet(MV_U32 newCfg);
MV_32 mvBoardModuleConfigGet(MV_VOID);
MV_32 mvBoardPhyAddrGet(MV_U32 ethPortNum);
MV_VOID mvBoardPhyAddrSet(MV_U32 ethPortNum, MV_U32 smiAddr);
MV_32 mvBoardQuadPhyAddr0Get(MV_U32 ethPortNum);
MV_VOID mvBoardQuadPhyAddr0Set(MV_U32 ethPortNum, MV_U32 smiAddr);
MV_STATUS mvBoardSatrInfoConfig(MV_SATR_TYPE_ID satrClass, MV_BOARD_SATR_INFO *satrInfo);
MV_STATUS mvBoardModuleTypeGet(MV_MODULE_TYPE_ID configClass, MV_MODULE_TYPE_INFO *configInfo);
MV_STATUS mvBoardExtPhyBufferSelect(MV_BOOL enable);
MV_STATUS mvBoardSgmiiSfp0TxSet(MV_BOOL enable);
MV_U32 mvBoardTclkGet(MV_VOID);
MV_U32 mvBoardL2ClkGetRaw(MV_VOID);
MV_U32 mvBoardSysClkGet(MV_VOID);
MV_U32 mvBoardDebugLedNumGet(MV_U32 boardId);
MV_VOID mvBoardDebugLed(MV_U32 hexNum);
MV_32 mvBoarGpioPinNumGet(MV_BOARD_GPP_CLASS class, MV_U32 index);
MV_VOID mvBoardReset(MV_VOID);
MV_BOARD_PEX_INFO *mvBoardPexInfoGet(void);
MV_32 mvBoardResetGpioPinGet(MV_VOID);
#ifdef MV_USB_VBUS_CYCLE
MV_32 mvBoardUSBVbusGpioPinGet(MV_32 devId);
MV_STATUS mvBoardIoExpanderTypeGet(MV_IO_EXPANDER_TYPE_ID ioClass, MV_BOARD_IO_EXPANDER_TYPE_INFO *ioInfo);
MV_VOID mvBoardUsbVbusSet(int dev);
#endif
MV_BOOL mvBoardIsOurPciSlot(MV_U32 busNum, MV_U32 slotNum);
MV_U32 mvBoardGpioIntMaskGet(MV_U32 gppGrp);
MV_U32 mvBoardSlicUnitTypeGet(MV_VOID);
MV_VOID mvBoardSlicUnitTypeSet(MV_U32 slicType);
MV_32 mvBoardMppGet(MV_U32 mppGroupNum);
MV_VOID mvBoardMppSet(MV_U32 mppGroupNum, MV_U32 mppValue);
MV_U8 mvBoardTdmSpiIdGet(MV_VOID);
MV_VOID mvBoardConfigurationPrint(MV_VOID);
MV_BOOL mvBoardIsGbEPortConnected(MV_U32 ethPortNum);
MV_32 mvBoardGetDevicesNumber(MV_BOARD_DEV_CLASS devClass);
MV_32 mvBoardGetDeviceBaseAddr(MV_32 devNum, MV_BOARD_DEV_CLASS devClass);
MV_32 mvBoardGetDeviceBusWidth(MV_32 devNum, MV_BOARD_DEV_CLASS devClass);
MV_32 mvBoardGetDeviceWinSize(MV_32 devNum, MV_BOARD_DEV_CLASS devClass);
MV_U32 mvBoardGetDevCSNum(MV_32 devNum, MV_BOARD_DEV_CLASS devClass);
MV_U32 mvBoardGetDevBusNum(MV_32 devNum, MV_BOARD_DEV_CLASS devClass);
MV_BOOL mvBoardGetDevState(MV_32 devNum, MV_BOARD_DEV_CLASS devClass);
MV_STATUS mvBoardSetDevState(MV_32 devNum, MV_BOARD_DEV_CLASS devClass, MV_BOOL newState);
MV_U8 mvBoardTwsiAddrTypeGet(MV_BOARD_TWSI_CLASS twsiClass, MV_U32 index);
MV_U8 mvBoardTwsiAddrGet(MV_BOARD_TWSI_CLASS twsiClass, MV_U32 index);
MV_VOID mvBoardTwsiAddrSet(MV_BOARD_TWSI_CLASS twsiClass, MV_U32 index, MV_U8 address);
MV_U8 mvBoardTwsiIsMore256Get(MV_BOARD_TWSI_CLASS twsiClass, MV_U32 index);
MV_U32 mvBoardNetComplexConfigGet(MV_VOID);
MV_VOID mvBoardNetComplexConfigSet(MV_U32 ethConfig);
MV_U32 mvBoardIdIndexGet(MV_U32 boardId);
MV_U32 mvBoardIdGet(MV_VOID);
MV_VOID mvBoardSet(MV_U32 boardId);
MV_U32 mvBoardSledCpuNumGet(MV_VOID);
MV_VOID mvBoardFlashDeviceUpdate(MV_VOID);
MV_VOID mvBoardInfoUpdate(MV_VOID);
MV_VOID mvBoardVerifySerdesCofig(MV_VOID);
MV_VOID mvBoardMppIdUpdate(MV_VOID);
MV_STATUS mvBoardNetComplexInfoUpdate(MV_VOID);
MV_VOID mvBoardConfigWrite(MV_VOID);
MV_BOARD_BOOT_SRC mvBoardBootDeviceGroupSet(MV_VOID);
MV_BOARD_BOOT_SRC mvBoardBootDeviceGet(MV_VOID);
MV_U32 mvBoardBootAttrGet(MV_U32 satrBootDeviceValue, MV_U8 attrNum);
MV_U32 mvBoardSpiBusGet(MV_VOID);
MV_STATUS mvBoardTwsiGet(MV_BOARD_TWSI_CLASS twsiClass, MV_U8 devNum, MV_U8 regNum, MV_U8 *pData, MV_U32 len);
MV_STATUS mvBoardTwsiSet(MV_BOARD_TWSI_CLASS twsiClass, MV_U8 devNum, MV_U8 regNum, MV_U8 *regVal, MV_U32 len);
MV_U8 mvBoardCpuFreqGet(MV_VOID);
MV_STATUS mvBoardCpuFreqSet(MV_U8 freqVal);
MV_STATUS mvBoardIsSwitchConnected(void);
MV_U32 mvBoardSwitchPortForceLinkGet(MV_U32 switchIdx);
MV_U32 mvBoardFreqModesNumGet(void);
MV_32 mvBoardSmiScanModeGet(MV_U32 switchIdx);
MV_BOARD_MAC_SPEED mvBoardMacSpeedGet(MV_U32 ethPortNum);
MV_VOID mvBoardMacSpeedSet(MV_U32 ethPortNum, MV_BOARD_MAC_SPEED speed);
MV_VOID mvBoardMacSpeedSet(MV_U32 ethPortNum, MV_BOARD_MAC_SPEED macSpeed);
MV_U32 mvBoardSwitchCpuPortGet(MV_U32 switchIdx);
MV_32 mvBoardSwitchPhyAddrGet(MV_U32 switchIdx);
MV_32 mvBoardSwitchConnectedPortGet(MV_U32 ethPort);
MV_BOOL mvBoardSwitchCpuPortIsRgmii(MV_U32 switchIdx);
MV_VOID mvBoardModuleSwitchInfoUpdate(MV_BOOL switchDetected);
MV_U32 mvBoardMacCpuPortGet(MV_VOID);
MV_BOOL mvBoardIsEthConnected(MV_U32 ethNum);
MV_BOOL mvBoardIsEthActive(MV_U32 ethNum);
MV_32 mvBoardSwitchIrqGet(MV_VOID);
MV_U32 mvBoardSwitchPortsMaskGet(MV_U32 switchIdx);
MV_BOOL mvBoardConfigAutoDetectEnabled(void);
MV_32 mvBoardSmiScanModeGet(MV_U32 switchIdx);
MV_STATUS mvBoardConfIdSet(MV_U16 conf);
MV_U16 mvBoardPexModeGet(MV_VOID);
MV_STATUS mvBoardPexModeSet(MV_U16 conf);
MV_BOOL mvBoardIsLcdDviModuleConnected(void);
MV_BOOL mvBoardIsPexModuleConnected(void);
MV_BOOL mvBoardIsLvdsModuleConnected(void);
MV_BOOL mvBoardIsSetmModuleConnected(void);
MV_U8 mvBoardCpuCoresNumGet(MV_VOID);
MV_VOID mvBoardMppModuleTypePrint(MV_VOID);
MV_VOID mvBoardOtherModuleTypePrint(MV_VOID);
MV_BOOL mvBoardIsModuleConnected(MV_U32 ModuleID);
MV_STATUS mvBoardIoExpanderUpdate(MV_VOID);
MV_U8 mvBoardPICGpioGet(MV_U32 *picGpioMppInfo);
MV_STATUS mvBoardTwsiSatRGet(MV_U8 devNum, MV_U8 regNum, MV_U8 *pData);
MV_STATUS mvBoardTwsiSatRSet(MV_U8 devNum, MV_U8 regNum, MV_U8 regVal);
MV_U32 mvBoardSatRRead(MV_SATR_TYPE_ID satrField);
MV_STATUS mvBoardSatRWrite(MV_SATR_TYPE_ID satrWriteField, MV_U8 val);
MV_STATUS mvBoardIoExpanderGet(MV_U8 addr, MV_U8 offs, MV_U8 *pVal);
MV_STATUS mvBoardIoExpanderSet(MV_U8 addr, MV_U8 offs, MV_U8 val);
int mvBoardNorFlashConnect(void);
MV_NFC_ECC_MODE mvBoardNandECCModeGet(void);
MV_U8 mvBoardCompatibleNameGet(char *pNameBuff);

#ifdef CONFIG_CMD_BOARDCFG
typedef struct _boardConfigTypesInfo {
	MV_CONFIG_TYPE_ID configId;
	MV_U8 mask;
	MV_U8 offset;
	MV_U32 byteNum;
	MV_U32 isActiveForBoard[MV_MARVELL_BOARD_NUM];
} MV_BOARD_CONFIG_TYPE_INFO;

MV_U32 mvBoardDefaultValueGet(int option);
MV_STATUS mvBoardEepromWriteDefaultCfg(void);
MV_STATUS mvBoardEepromInit(void);
MV_BOOL mvBoardConfigTypeGet(MV_CONFIG_TYPE_ID configClass, MV_BOARD_CONFIG_TYPE_INFO *configInfo);
MV_STATUS mvBoardConfigGet(MV_U32 *config);
MV_VOID mvBoardSysConfigInit(void);
MV_BOOL mvBoardIsEepromEnabled(void);
MV_STATUS mvBoardEepromWrite(MV_CONFIG_TYPE_ID configType, MV_U8 value);
MV_STATUS mvBoardConfigVerify(MV_CONFIG_TYPE_ID field, MV_U8 writeVal);
MV_U32 mvBoardSysConfigGet(MV_CONFIG_TYPE_ID configField);
MV_STATUS mvBoardSysConfigSet(MV_CONFIG_TYPE_ID configField, MV_U8 value);
void mvBoardEepromValidSet(void);
#endif /* CONFIG_CMD_BOARDCFG */
MV_BOOL mvBoardIsTdmConnected(void);
void mvBoardTdmConnectionSet(MV_BOOL isConnected);
MV_NAND_IF_MODE mvBoardNandIfGet(void);
MV_BOOL mvBoardisSdioConnected(void);
MV_VOID mvBoardSdioConnectionSet(MV_BOOL status);
MV_BOOL mvBoardIsUsbPortConnected(MV_UNIT_ID usbTypeID, MV_U8 usbPortNumber);
MV_BOARD_INFO *mvBoardInfoStructureGet(MV_VOID);
MV_BOOL mvBoardIsAudioConnected(void);
void mvBoardAudioConnectionSet(MV_BOOL isConnected);
MV_BOOL mvBoardIsUsb3PortDevice(MV_U32 port);

#ifdef CONFIG_SWITCHING_SERVICES
MV_BOOL mvBoardisAmc(void);
#endif

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __INCmvBoardEnvLibh */
