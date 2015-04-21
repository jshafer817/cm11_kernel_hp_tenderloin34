#include <mach/msm_memtypes.h>

#define	GPIO(X)		(X)
#ifndef __ARCH_ARM_MACH_MSM_BOARD_OPERAUL_H__
#define __ARCH_ARM_MACH_MSM_BOARD_OPERAUL_H__


#define MSM_LCD_TE				GPIO(0)
#define MSM_WIFI_SHUTDOWNz			GPIO(1)
#define MSM_RAW_1V2_EN				GPIO(2)
#define MSM_AUD_HP_EN				GPIO(3)
#define MSM_CAM2_MCLK				GPIO(4)
#define MSM_RAW_MCLK				GPIO(5)
#define MSM_WW_IRQ				GPIO(6)
#define MSM_TP_ATTz				GPIO(7)
#define MSM_LCMIO_1V8_EN			GPIO(8)
#define MSM_HAPTIC_EN				GPIO(9)
#define MSM_SDC3_CDz				GPIO(10)
#define MSM_AUD_REMO_PRESz			GPIO(11)
#define MSM_TP_3V3_EN				GPIO(12)
#define MSM_V_HAPTIC_3V3_EN			GPIO(13)
#define MSM_AUD_REMO_TX				GPIO(14)
#define MSM_AUD_REMO_RX				GPIO(15)
#define MSM_TW_I2C_SDA				GPIO(16)
#define MSM_TW_I2C_SCL				GPIO(17)
#define MSM_AUD_HSMIC_2V85_EN			GPIO(18)
#define MSM_USB_ID1				GPIO(19)
#define MSM_CAM_I2C_SDA				GPIO(20)
#define MSM_CAM_I2C_SCL				GPIO(21)
#define MSM_RST_CLRz				GPIO(22)
#define MSM_PS_INTz				GPIO(23)
#define MSM_NFC_DL_MODE				GPIO(24)
#define MSM_NFC_VENz				GPIO(25)
#define MSM_BT_TX				GPIO(26)
#define MSM_BT_RX				GPIO(27)
#define MSM_BT_CTSz				GPIO(28)
#define MSM_BT_RTSz				GPIO(29)
#define MSM_SIM_IO				GPIO(30)
#define MSM_SIM_CLK				GPIO(31)
#define MSM_SIM_RST				GPIO(32)
#define MSM_FLASH_EN				GPIO(33)
#define MSM_AP_DEBUG_TX				GPIO(34)
#define MSM_AP_DEBUG_RX				GPIO(35)
#define MSM_CAM_PWDN				GPIO(36)
#define MSM_CAMIO_1V8_EN			GPIO(37)
#define MSM_SPI_DO				GPIO(38)
#define MSM_AUD_HP_DETz				GPIO(39)
#define MSM_SPI_CS0				GPIO(40)
#define MSM_SPI_CLK				GPIO(41)
#define MSM_AUD_WCD_RESET_N			GPIO(42)
#define MSM_VOL_DOWNz				GPIO(43)
#define MSM_SR_I2C_SDA				GPIO(44)
#define MSM_SR_I2C_SCL				GPIO(45)
#define MSM_AP_KPDPWRz 				GPIO(46)
#define MSM_AUD_SPK_I2S_WS			GPIO(47)
#define MSM_AUD_SPK_I2S_BCLK			GPIO(48)
#define MSM_AUD_SPK_I2S_DO			GPIO(49)
#define MSM_RAW_INTR1				GPIO(50)
#define MSM_RAW_RSTz				GPIO(51)
#define MSM_AUD_SPK_I2S_DI			GPIO(52)
#define MSM_CAM1_VCM_PD				GPIO(53)
#define MSM_REGION_ID				GPIO(54)
#define MSM_AUD_FM_I2SBCLK			GPIO(55)
#define MSM_AUD_FM_I2SSYNC			GPIO(56)
#define MSM_AUD_FM_I2SDIN			GPIO(57)
#define MSM_LCD_RSTz				GPIO(58)
#define MSM_AUD_WCD_MCLK			GPIO(59)
#define MSM_AUD_WCD_SB_CLK			GPIO(60)
#define MSM_AUD_WCD_SB_DATA			GPIO(61)
#define MSM_AUD_WCD_INTR_OUT			GPIO(62)
#define MSM_AUD_BTPCM_IN			GPIO(63)
#define MSM_AUD_BTPCM_OUT			GPIO(64)
#define MSM_AUD_BTPCM_SYNC			GPIO(65)
#define MSM_AUD_BTPCM_CLK			GPIO(66)
#define MSM_G_MOT				GPIO(67)
#define MSM_FRONT_CAM_RSTz			GPIO(68)
#define MSM_RAW_INTR0				GPIO(69)
#define MSM_COMPASS_INT				GPIO(70)
#define MSM_MCAM_SPI_DO				GPIO(71)
#define MSM_MCAM_SPI_DI				GPIO(72)
#define MSM_MCAM_SPI_CS0			GPIO(73)
#define MSM_MCAM_SPI_CLK			GPIO(74)
#define MSM_AUD_SPK_SDz				GPIO(75)
#define MSM_BT_SHUTDOWNz			GPIO(76)
#define MSM_CAM_D1V8_EN				GPIO(77)
#define MSM_VOL_UPz				GPIO(78)
#define MSM_BT_WAKE				GPIO(79)
#define MSM_AUD_UART_OEz			GPIO(80)
#define MSM_TP_RSTz				GPIO(81)
#define MSM_CAM1_ID				GPIO(82)
#define MSM_WIFI_SD_D3				GPIO(83)
#define MSM_WIFI_SD_D2				GPIO(84)
#define MSM_WIFI_SD_D1				GPIO(85)
#define MSM_WIFI_SD_D0				GPIO(86)
#define MSM_WIFI_SD_CMD				GPIO(87)
#define MSM_WCN_CMD_CLK				GPIO(88)
#define MSM_CAM2_STANDBY			GPIO(89)
#define MSM_LCD_ID0				GPIO(90)
#define MSM_TORCH_FLASHz			GPIO(91)
#define MSM_BT_HOST_WAKE			GPIO(92)
#define MSM_NC_GPIO_93				GPIO(93)
#define MSM_MBAT_IN				GPIO(94)
#define MSM_NFC_I2C_SDA				GPIO(95)
#define MSM_NFC_I2C_SCL				GPIO(96)
#define MSM_WL_DEV_WAKE				GPIO(97)
#define MSM_BATT_ALARM				GPIO(98)
#define MSM_HW_RST_CLRz				GPIO(99)
#define MSM_NC_GPIO_100				GPIO(100)
#define MSM_NC_GPIO_101				GPIO(101)
#define MSM_CHG_WDT_EN				GPIO(102)
#define MSM_PM_SEC_INTz				GPIO(103)
#define MSM_PM_USR_INTz				GPIO(104)
#define MSM_PM_MSM_INTz				GPIO(105)
#define MSM_NFC_IRQ				GPIO(106)
#define MSM_SIM_DETz				GPIO(107)
#define MSM_JTAG_PS_HOLD			GPIO(108)
#define MSM_NC_GPIO_109				GPIO(109)
#define MSM_NC_GPIO_110				GPIO(110)
#define MSM_PRX_LB_SW_SEL			GPIO(111)
#define MSM_BOOT_CONFIG_6			GPIO(112)
#define MSM_W_DRX_MODE_SEL2			GPIO(113)
#define MSM_W_DRX_MODE_SEL1			GPIO(114)
#define MSM_W_DRX_MODE_SEL0			GPIO(115)
#define MSM_W_ANT_SW_SEL3			GPIO(116)
#define MSM_W_ANT_SW_SEL2			GPIO(117)
#define MSM_W_ANT_SW_SEL1			GPIO(118)
#define MSM_W_ANT_SW_SEL0			GPIO(119)
#define MSM_NC_GPIO_120				GPIO(120)
#define MSM_NC_GPIO_121				GPIO(121)
#define MSM_W_PA0_R0				GPIO(122)
#define MSM_W_PA0_R1				GPIO(123)
#define MSM_NC_GPIO_124				GPIO(124)
#define MSM_W_WTR_RF_ON				GPIO(125)
#define MSM_W_WTR_RX_ON				GPIO(126)
#define MSM_APT0_VCON_CPU			GPIO(127)
#define MSM_NC_GPIO_128				GPIO(128)
#define MSM_W_PA_ON7_B4_B7_EN			GPIO(129)
#define MSM_W_PA_ON6_B2_EN			GPIO(130)
#define MSM_W_PA_ON5_B8_EN			GPIO(131)
#define MSM_W_PA_ON4_B17_B20_EN			GPIO(132)
#define MSM_W_PA_ON3_MODE			GPIO(133)
#define MSM_W_PA_ON2_HB				GPIO(134)
#define MSM_NC_GPIO_135				GPIO(135)
#define MSM_W_PA_ON0				GPIO(136)
#define MSM_W_GPS_LNA_EN			GPIO(137)
#define MSM_V_3G_PA0_EN				GPIO(138)
#define MSM_NC_GPIO_139				GPIO(139)
#define MSM_NC_GPIO_140				GPIO(140)
#define MSM_NC_GPIO_141				GPIO(141)
#define MSM_W_WTR_SSBI_PRX_DRX			GPIO(142)
#define MSM_W_WTR_SSBI_TX_GNSS			GPIO(143)
#define MSM_NC_GPIO_144				GPIO(144)
#define MSM_NC_GPIO_145				GPIO(145)
#define MSM_W_GP_DATA2				GPIO(146)
#define MSM_W_GP_DATA1				GPIO(147)
#define MSM_W_GP_DATA0				GPIO(148)
#define MSM_NC_GPIO_149				GPIO(149)
#define MSM_NC_GPIO_150				GPIO(150)
#define MSM_NC_GPIO_151				GPIO(151)

#define MSM_XB_WIFI_FEM_DETECT			GPIO(9)
#define MSM_XB_GYRO_INT				GPIO(10)
#define MSM_XB_AP_UART_SEL			GPIO(13)
#define MSM_XB_SR_I2C_SEL			GPIO(22)
#define MSM_XB_HW_ID0				GPIO(38)
#define MSM_XB_HW_ID1				GPIO(40)
#define MSM_XB_HW_ID2				GPIO(41)
#define MSM_XB_NC_GPIO_55			GPIO(55)
#define MSM_XB_NC_GPIO_56			GPIO(56)
#define MSM_XB_NC_GPIO_57			GPIO(57)
#define MSM_XB_HW_ID3				GPIO(75)
#define MSM_XB_LCD_ID1				GPIO(89)
#define MSM_XB_CAM_SEL				GPIO(93)
#define MSM_XB_AUD_I2C_SDA			GPIO(95)
#define MSM_XB_AUD_I2C_SCL			GPIO(96)
#define MSM_XB_COMPASS_RSTz			GPIO(97)
#define MSM_XB_USB_ID_ADC			GPIO(99)
#define MSM_XB_FRONT_CAM_ID			GPIO(100)
#define MSM_XB_CAPSENSOR_XRES			GPIO(101)
#define MSM_XB_CAPSENSOR_INTz			GPIO(102)
#define MSM_XB_WDOG_DISABLE			GPIO(111)
#define MSM_XB_MSM8930_GPIO150			GPIO(150)
#define MSM_XB_MSM8930_GPIO151			GPIO(151)

#define MSM_XB_MSM8930_GPIO56			GPIO(56)

#define MSM_XE_CAB_INz				GPIO(55)
#define RESET_EN_CLRz				GPIO(99)

#define PM_AP_BL_LED				PMGPIO(1)
#define PM_HAPTIC_PWM				PMGPIO(2)
#define PM_NC_GPIO_3				PMGPIO(3)
#define PM_SSBI_PMIC_FCLK			PMGPIO(4)
#define PM_NC_GPIO_5				PMGPIO(5)
#define PM_NC_GPIO_6				PMGPIO(6)
#define PM_NC_GPIO_7				PMGPIO(7)
#define PM_BCM_SLEEP_CLK			PMGPIO(8)
#define PM_BATT_ALARM				PMGPIO(9)
#define PM_NC_GPIO_10				PMGPIO(10)
#define PM_NC_GPIO_11				PMGPIO(11)
#define PM_NC_GPIO_12				PMGPIO(12)

#define PM_XB_NC_GPIO_2				PMGPIO(2)
#define PM_XB_CHARGER_STAT			PMGPIO(12)

#define PM_XC_BAT_ID_HIGH			PMGPIO(12)

#define PM_XE_AMBER_LED				PMGPIO(1)
#define PM_XE_GREEN_LED				PMGPIO(2)

#endif 

extern int panel_type;
extern struct msm_camera_board_info operaul_camera_board_info;
extern struct platform_device operaul_msm_rawchip_device;

int __init operaul_gpiomux_init(void);
int __init operaul_init_keypad(void);
void operaul_allocate_fb_region(void);
void operaul_mdp_writeback(struct memtype_reserve* reserve_table);
int __init operaul_init_mmc(void);
int __init operaul_wifi_init(void);
void __init operaul_init_cam(void);
void operaul_init_fb(void);
void operaul_init_gpu(void);
