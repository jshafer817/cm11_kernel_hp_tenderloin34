/* Copyright (c) 2009, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#include "mt9m113.h"

struct mt9m113_i2c_reg_conf const
preview_snapshot_mode_reg_tbl[] = {

//[Default]
//STATE = Sensor Reset, 1  // hard reset
//DELAY=10
//STATE = Sensor Reset, 0  // hard reset
//DELAY=10	      
{0x001C, 0xFFFF, 0x0001, WORD_LEN, 0 }, 	// MCU_BOOT_MODE
//Enlarge MCU_MODE/PLL/MCU_DATA delay by 20 ms to optimize "black screen issue"--0126
{0x001C, 0xFFFF, 0x0000, WORD_LEN, 30}, 	// MCU_BOOT_MODEDELAY=30
{0x0016, 0xFFFF, 0x00FF, WORD_LEN, 0 }, 	// CLOCKS_CONTROL
{0x0018, 0xFFFF, 0x0028, WORD_LEN, 0 }, 	// STANDBY_CONTROL
{0x0014, 0xFFFF, 0x2145, WORD_LEN, 0 }, 	// PLL_CONTROL
{0x0014, 0xFFFF, 0x2145, WORD_LEN, 0 }, 	// PLL_CONTROL
{0x0014, 0xFFFF, 0x2145, WORD_LEN, 0 }, 	// PLL_CONTROL
{0x0010, 0xFFFF, 0x0114, WORD_LEN, 0 }, 	// PLL_DIVIDERSAF
{0x0012, 0xFFFF, 0x00F1, WORD_LEN, 0 }, 	// PLL_P_DIVIDERS
{0x0014, 0xFFFF, 0x2545, WORD_LEN, 0 }, 	// PLL_CONTROL
{0x0014, 0xFFFF, 0x2547, WORD_LEN, 0 }, 	// PLL_CONTROL
{0x0014, 0xFFFF, 0x3447, WORD_LEN, 20}, 	// PLL_CONTROL//DELAY = 20 // Allow PLL to lock
{0x0014, 0xFFFF, 0x3047, WORD_LEN, 0 }, 	// PLL_CONTROL
{0x0014, 0xFFFF, 0x3046, WORD_LEN, 0 }, 	// PLL_CONTROL
{0x001A, 0xFFFF, 0x0218, WORD_LEN, 0 }, 	// RESET_AND_MISC_CONTROL
{0x0018, 0xFFFF, 0x002A, WORD_LEN, 0 }, 	// STANDBY_CONTROL
{0x321C, 0xFFFF, 0x0003, WORD_LEN, 0 }, 	// OFIFO_CONTROL_STATUS
{0x098C, 0xFFFF, 0x2703, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_OUTPUT_WIDTH_A] = 640
{0x0990, 0xFFFF, 0x0280, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2705, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_OUTPUT_HEIGHT_A] = 480
{0x0990, 0xFFFF, 0x01E0, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2707, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_OUTPUT_WIDTH_B] = 1280
{0x0990, 0xFFFF, 0x0500, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2709, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_OUTPUT_HEIGHT_B] = 1024
{0x0990, 0xFFFF, 0x0400, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x270D, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_ROW_START_A] = 0
{0x0990, 0xFFFF, 0x0000, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x270F, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_COL_START_A] = 0
{0x0990, 0xFFFF, 0x0000, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2711, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_ROW_END_A] = 973
{0x0990, 0xFFFF, 0x03CD, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2713, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_COL_END_A] = 1293
{0x0990, 0xFFFF, 0x050D, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2715, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_ROW_SPEED_A] =  8465
{0x0990, 0xFFFF, 0x2111, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2717, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_READ_MODE_A]
{0x0990, 0xFFFF, 0x046C, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2719, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FINE_CORRECTION_A] = 172
{0x0990, 0xFFFF, 0x00AC, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x271B, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FINE_IT_MIN_A] = 497
{0x0990, 0xFFFF, 0x01F1, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x271D, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FINE_IT_MAX_MARGIN_A] = 319
{0x0990, 0xFFFF, 0x013F, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x271F, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FRAME_LENGTH_A] = 814
{0x0990, 0xFFFF, 0x032E, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2721, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_LINE_LENGTH_PCK_A] = 1228
{0x0990, 0xFFFF, 0x04CC, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2723, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_ROW_START_B]
{0x0990, 0xFFFF, 0x0004, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2725, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_COL_START_B]
{0x0990, 0xFFFF, 0x0004, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2727, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_ROW_END_B] =
{0x0990, 0xFFFF, 0x040B, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2729, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_COL_END_B]
{0x0990, 0xFFFF, 0x050B, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x272B, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_ROW_SPEED_B]
{0x0990, 0xFFFF, 0x2111, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x272D, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_READ_MODE_B]
{0x0990, 0xFFFF, 0x0024, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x272F, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FINE_CORRECTION_B]
{0x0990, 0xFFFF, 0x004C, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2731, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FINE_IT_MIN_B]
{0x0990, 0xFFFF, 0x00F9, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2733, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FINE_IT_MAX_MARGIN_B]
{0x0990, 0xFFFF, 0x00A7, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2735, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FRAME_LENGTH_B]
{0x0990, 0xFFFF, 0x0559, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2737, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_LINE_LENGTH_PCK_B]
{0x0990, 0xFFFF, 0x0722, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2739, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_CROP_X0_A]
{0x0990, 0xFFFF, 0x0000, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x273B, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_CROP_X1_A]
{0x0990, 0xFFFF, 0x027F, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x273D, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_CROP_Y0_A]
{0x0990, 0xFFFF, 0x0000, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x273F, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_CROP_Y1_A]
{0x0990, 0xFFFF, 0x01DF, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2747, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_CROP_X0_B]
{0x0990, 0xFFFF, 0x0000, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2749, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_CROP_X1_B]
{0x0990, 0xFFFF, 0x04FF, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x274B, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_CROP_Y0_B]
{0x0990, 0xFFFF, 0x0000, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x274D, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_CROP_Y1_B]
{0x0990, 0xFFFF, 0x03FF, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x222D, WORD_LEN, 0 }, 	// MCU_ADDRESS [AE_R9_STEP ????]
{0x0990, 0xFFFF, 0x00CC, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA404, WORD_LEN, 0 }, 	// MCU_ADDRESS [FD_MODE]
{0x0990, 0xFFFF, 0x0010, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA408, WORD_LEN, 0 }, 	// MCU_ADDRESS [FD_SEARCH_F1_50]
{0x0990, 0xFFFF, 0x0032, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA409, WORD_LEN, 0 }, 	// MCU_ADDRESS [FD_SEARCH_F2_50]
{0x0990, 0xFFFF, 0x0034, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA40A, WORD_LEN, 0 }, 	// MCU_ADDRESS [FD_SEARCH_F1_60]
{0x0990, 0xFFFF, 0x003C, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA40B, WORD_LEN, 0 }, 	// MCU_ADDRESS [FD_SEARCH_F2_60]
{0x0990, 0xFFFF, 0x003E, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2411, WORD_LEN, 0 }, 	// MCU_ADDRESS [FD_R9_STEP_F60_A]
{0x0990, 0xFFFF, 0x00CC, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2413, WORD_LEN, 0 }, 	// MCU_ADDRESS [FD_R9_STEP_F50_A]
{0x0990, 0xFFFF, 0x00F4, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2415, WORD_LEN, 0 }, 	// MCU_ADDRESS [FD_R9_STEP_F60_B]
{0x0990, 0xFFFF, 0x0089, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2417, WORD_LEN, 0 }, 	// MCU_ADDRESS [FD_R9_STEP_F50_B]
{0x0990, 0xFFFF, 0x00A4, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA40D, WORD_LEN, 0 }, 	// MCU_ADDRESS [FD_STAT_MIN]
{0x0990, 0xFFFF, 0x0002, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA40E, WORD_LEN, 0 }, 	// MCU_ADDRESS [FD_STAT_MAX]
{0x0990, 0xFFFF, 0x0003, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA410, WORD_LEN, 0 }, 	// MCU_ADDRESS [FD_MIN_AMPLITUDE]
{0x0990, 0xFFFF, 0x000A, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x3044, 0xFFFF, 0x0504, WORD_LEN, 0 }, 	// RESERVED_CORE_3044
{0x3086, 0xFFFF, 0x24F7, WORD_LEN, 0 }, 	// RESERVED_CORE_3086
{0x3088, 0xFFFF, 0xF059, WORD_LEN, 0 }, 	// RESERVED_CORE_3088
{0x3090, 0xFFFF, 0x0716, WORD_LEN, 0 }, 	// RESERVED_CORE_3090
{0x3092, 0xFFFF, 0xAB1F, WORD_LEN, 0 }, 	// RESERVED_CORE_3092
{0x30D4, 0xFFFF, 0x9020, WORD_LEN, 0 }, 	// RESERVED_CORE_30D4
{0x30E2, 0xFFFF, 0x6645, WORD_LEN, 0 }, 	// RESERVED_CORE_30E2
{0x30E4, 0xFFFF, 0x7A66, WORD_LEN, 0 }, 	// RESERVED_CORE_30E4
{0x30E6, 0xFFFF, 0x6652, WORD_LEN, 0 }, 	// RESERVED_CORE_30E6
{0x30E8, 0xFFFF, 0x7766, WORD_LEN, 0 }, 	// RESERVED_CORE_30E8
{0x30EA, 0xFFFF, 0x2E03, WORD_LEN, 0 }, 	// RESERVED_CORE_30EA
{0x30EC, 0xFFFF, 0x452E, WORD_LEN, 0 }, 	// RESERVED_CORE_30EC
{0x30EE, 0xFFFF, 0x2E17, WORD_LEN, 0 }, 	// RESERVED_CORE_30EE
{0x30F0, 0xFFFF, 0x452E, WORD_LEN, 0 }, 	// RESERVED_CORE_30F0
{0x30F6, 0xFFFF, 0x0501, WORD_LEN, 0 }, 	// RESERVED_CORE_30F6
{0x30F8, 0xFFFF, 0x0501, WORD_LEN, 0 }, 	// RESERVED_CORE_30F8
{0x30FA, 0xFFFF, 0x0401, WORD_LEN, 0 }, 	// RESERVED_CORE_30FA
{0x30FC, 0xFFFF, 0x0401, WORD_LEN, 0 }, 	// RESERVED_CORE_30FC
{0x30FE, 0xFFFF, 0x5145, WORD_LEN, 0 }, 	// RESERVED_CORE_30FE
{0x3100, 0xFFFF, 0x4F45, WORD_LEN, 0 }, 	// RESERVED_CORE_3100
{0x3102, 0xFFFF, 0x652E, WORD_LEN, 0 }, 	// RESERVED_CORE_3102
{0x3104, 0xFFFF, 0x7552, WORD_LEN, 0 }, 	// RESERVED_CORE_3104
{0x3106, 0xFFFF, 0x2D05, WORD_LEN, 0 }, 	// RESERVED_CORE_3106
{0x3108, 0xFFFF, 0x4405, WORD_LEN, 0 }, 	// RESERVED_CORE_3108
{0x311A, 0xFFFF, 0x5045, WORD_LEN, 0 }, 	// RESERVED_CORE_311A
{0x311E, 0xFFFF, 0x0601, WORD_LEN, 0 }, 	// RESERVED_CORE_311E
{0x3122, 0xFFFF, 0x0601, WORD_LEN, 0 }, 	// RESERVED_CORE_3122
{0x316C, 0xFFFF, 0x8406, WORD_LEN, 0 }, 	// RESERVED_CORE_316C
{0x098C, 0xFFFF, 0xAB2D, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_NR_START_G]
{0x0990, 0xFFFF, 0x002A, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB31, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_NR_STOP_G]
{0x0990, 0xFFFF, 0x002E, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2B28, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_LL_BRIGHTNESSSTART]
{0x0990, 0xFFFF, 0x1F40, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2B2A, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_LL_BRIGHTNESSSTOP]
{0x0990, 0xFFFF, 0x3A98, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2B38, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMASTARTMORPH]
{0x0990, 0xFFFF, 0x1F40, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2B3A, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMASTOPMORPH]
{0x0990, 0xFFFF, 0x3A98, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2257, WORD_LEN, 0 }, 	// MCU_ADDRESS [RESERVED_AE_57]
{0x0990, 0xFFFF, 0x2710, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2250, WORD_LEN, 0 }, 	// MCU_ADDRESS [RESERVED_AE_50]
{0x0990, 0xFFFF, 0x1B58, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2252, WORD_LEN, 0 }, 	// MCU_ADDRESS [RESERVED_AE_52]
{0x0990, 0xFFFF, 0x32C8, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA24B, WORD_LEN, 0 }, 	// MCU_ADDRESS [AE_TARGETMAX]
{0x0990, 0xFFFF, 0x0082, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x326C, 0xFFFF, 0x0C00, WORD_LEN, 0 }, 	// APERTURE_PARAMETERS
{0x098C, 0xFFFF, 0x2717, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_READ_MODE_A]
{0x0990, 0xFFFF, 0x046C, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2719, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FINE_CORRECTION_A]
{0x0990, 0xFFFF, 0x00AC, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x271B, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FINE_IT_MIN_A]
{0x0990, 0xFFFF, 0x01F1, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x271D, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FINE_IT_MAX_MARGIN_A]
{0x0990, 0xFFFF, 0x013F, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x271F, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FRAME_LENGTH_A]
{0x0990, 0xFFFF, 0x032E, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2721, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_LINE_LENGTH_PCK_A]
{0x0990, 0xFFFF, 0x04CC, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x275F, WORD_LEN, 0 }, 	// MCU_ADDRESS [RESERVED_MODE_5F]
{0x0990, 0xFFFF, 0x0596, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2761, WORD_LEN, 0 }, 	// MCU_ADDRESS [RESERVED_MODE_61]
{0x0990, 0xFFFF, 0x0094, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x364E, 0xFFFF, 0x07B0, WORD_LEN, 0 }, 	// P_GR_P0Q0
{0x3650, 0xFFFF, 0x7E0E, WORD_LEN, 0 }, 	// P_GR_P0Q1
{0x3652, 0xFFFF, 0x3D31, WORD_LEN, 0 }, 	// P_GR_P0Q2
{0x3654, 0xFFFF, 0x80AE, WORD_LEN, 0 }, 	// P_GR_P0Q3
{0x3656, 0xFFFF, 0xE131, WORD_LEN, 0 }, 	// P_GR_P0Q4
{0x3658, 0xFFFF, 0x01B0, WORD_LEN, 0 }, 	// P_RD_P0Q0
{0x365A, 0xFFFF, 0x878D, WORD_LEN, 0 }, 	// P_RD_P0Q1
{0x365C, 0xFFFF, 0x2671, WORD_LEN, 0 }, 	// P_RD_P0Q2
{0x365E, 0xFFFF, 0x7D2D, WORD_LEN, 0 }, 	// P_RD_P0Q3
{0x3660, 0xFFFF, 0xA5D1, WORD_LEN, 0 }, 	// P_RD_P0Q4
{0x3662, 0xFFFF, 0x03B0, WORD_LEN, 0 }, 	// P_BL_P0Q0
{0x3664, 0xFFFF, 0x5A0E, WORD_LEN, 0 }, 	// P_BL_P0Q1
{0x3666, 0xFFFF, 0x0E71, WORD_LEN, 0 }, 	// P_BL_P0Q2
{0x3668, 0xFFFF, 0x99EE, WORD_LEN, 0 }, 	// P_BL_P0Q3
{0x366A, 0xFFFF, 0xA671, WORD_LEN, 0 }, 	// P_BL_P0Q4
{0x366C, 0xFFFF, 0x0170, WORD_LEN, 0 }, 	// P_GB_P0Q0
{0x366E, 0xFFFF, 0xF44D, WORD_LEN, 0 }, 	// P_GB_P0Q1
{0x3670, 0xFFFF, 0x2971, WORD_LEN, 0 }, 	// P_GB_P0Q2
{0x3672, 0xFFFF, 0x2D4A, WORD_LEN, 0 }, 	// P_GB_P0Q3
{0x3674, 0xFFFF, 0xD671, WORD_LEN, 0 }, 	// P_GB_P0Q4
{0x3676, 0xFFFF, 0x674C, WORD_LEN, 0 }, 	// P_GR_P1Q0
{0x3678, 0xFFFF, 0x748D, WORD_LEN, 0 }, 	// P_GR_P1Q1
{0x367A, 0xFFFF, 0x3FEE, WORD_LEN, 0 }, 	// P_GR_P1Q2
{0x367C, 0xFFFF, 0x89AE, WORD_LEN, 0 }, 	// P_GR_P1Q3
{0x367E, 0xFFFF, 0xB410, WORD_LEN, 0 }, 	// P_GR_P1Q4
{0x3680, 0xFFFF, 0x168C, WORD_LEN, 0 }, 	// P_RD_P1Q0
{0x3682, 0xFFFF, 0xC56D, WORD_LEN, 0 }, 	// P_RD_P1Q1
{0x3684, 0xFFFF, 0x7CAC, WORD_LEN, 0 }, 	// P_RD_P1Q2
{0x3686, 0xFFFF, 0x038F, WORD_LEN, 0 }, 	// P_RD_P1Q3
{0x3688, 0xFFFF, 0xA86F, WORD_LEN, 0 }, 	// P_RD_P1Q4
{0x368A, 0xFFFF, 0xDB6B, WORD_LEN, 0 }, 	// P_BL_P1Q0
{0x368C, 0xFFFF, 0xA2AE, WORD_LEN, 0 }, 	// P_BL_P1Q1
{0x368E, 0xFFFF, 0xFA8D, WORD_LEN, 0 }, 	// P_BL_P1Q2
{0x3690, 0xFFFF, 0x5C8E, WORD_LEN, 0 }, 	// P_BL_P1Q3
{0x3692, 0xFFFF, 0x740C, WORD_LEN, 0 }, 	// P_BL_P1Q4
{0x3694, 0xFFFF, 0x9F4B, WORD_LEN, 0 }, 	// P_GB_P1Q0
{0x3696, 0xFFFF, 0x1C4D, WORD_LEN, 0 }, 	// P_GB_P1Q1
{0x3698, 0xFFFF, 0x978D, WORD_LEN, 0 }, 	// P_GB_P1Q2
{0x369A, 0xFFFF, 0x21EC, WORD_LEN, 0 }, 	// P_GB_P1Q3
{0x369C, 0xFFFF, 0xF5AD, WORD_LEN, 0 }, 	// P_GB_P1Q4
{0x369E, 0xFFFF, 0x7D10, WORD_LEN, 0 }, 	// P_GR_P2Q0
{0x36A0, 0xFFFF, 0x3E2E, WORD_LEN, 0 }, 	// P_GR_P2Q1
{0x36A2, 0xFFFF, 0x8953, WORD_LEN, 0 }, 	// P_GR_P2Q2
{0x36A4, 0xFFFF, 0xD910, WORD_LEN, 0 }, 	// P_GR_P2Q3
{0x36A6, 0xFFFF, 0x3033, WORD_LEN, 0 }, 	// P_GR_P2Q4
{0x36A8, 0xFFFF, 0x06D1, WORD_LEN, 0 }, 	// P_RD_P2Q0
{0x36AA, 0xFFFF, 0xAD4E, WORD_LEN, 0 }, 	// P_RD_P2Q1
{0x36AC, 0xFFFF, 0xD2D2, WORD_LEN, 0 }, 	// P_RD_P2Q2
{0x36AE, 0xFFFF, 0x5CCE, WORD_LEN, 0 }, 	// P_RD_P2Q3
{0x36B0, 0xFFFF, 0x3B93, WORD_LEN, 0 }, 	// P_RD_P2Q4
{0x36B2, 0xFFFF, 0x50D0, WORD_LEN, 0 }, 	// P_BL_P2Q0
{0x36B4, 0xFFFF, 0x79AD, WORD_LEN, 0 }, 	// P_BL_P2Q1
{0x36B6, 0xFFFF, 0xDFF2, WORD_LEN, 0 }, 	// P_BL_P2Q2
{0x36B8, 0xFFFF, 0x88AF, WORD_LEN, 0 }, 	// P_BL_P2Q3
{0x36BA, 0xFFFF, 0x2453, WORD_LEN, 0 }, 	// P_BL_P2Q4
{0x36BC, 0xFFFF, 0x0051, WORD_LEN, 0 }, 	// P_GB_P2Q0
{0x36BE, 0xFFFF, 0x81CF, WORD_LEN, 0 }, 	// P_GB_P2Q1
{0x36C0, 0xFFFF, 0x8313, WORD_LEN, 0 }, 	// P_GB_P2Q2
{0x36C2, 0xFFFF, 0x2250, WORD_LEN, 0 }, 	// P_GB_P2Q3
{0x36C4, 0xFFFF, 0x4A53, WORD_LEN, 0 }, 	// P_GB_P2Q4
{0x36C6, 0xFFFF, 0x0C8D, WORD_LEN, 0 }, 	// P_GR_P3Q0
{0x36C8, 0xFFFF, 0x362B, WORD_LEN, 0 }, 	// P_GR_P3Q1
{0x36CA, 0xFFFF, 0xAD51, WORD_LEN, 0 }, 	// P_GR_P3Q2
{0x36CC, 0xFFFF, 0xA470, WORD_LEN, 0 }, 	// P_GR_P3Q3
{0x36CE, 0xFFFF, 0x3DD2, WORD_LEN, 0 }, 	// P_GR_P3Q4
{0x36D0, 0xFFFF, 0x174C, WORD_LEN, 0 }, 	// P_RD_P3Q0
{0x36D2, 0xFFFF, 0x152F, WORD_LEN, 0 }, 	// P_RD_P3Q1
{0x36D4, 0xFFFF, 0x82F1, WORD_LEN, 0 }, 	// P_RD_P3Q2
{0x36D6, 0xFFFF, 0xDED0, WORD_LEN, 0 }, 	// P_RD_P3Q3
{0x36D8, 0xFFFF, 0x6F12, WORD_LEN, 0 }, 	// P_RD_P3Q4
{0x36DA, 0xFFFF, 0xD36C, WORD_LEN, 0 }, 	// P_BL_P3Q0
{0x36DC, 0xFFFF, 0x51AE, WORD_LEN, 0 }, 	// P_BL_P3Q1
{0x36DE, 0xFFFF, 0xD0AE, WORD_LEN, 0 }, 	// P_BL_P3Q2
{0x36E0, 0xFFFF, 0x274E, WORD_LEN, 0 }, 	// P_BL_P3Q3
{0x36E2, 0xFFFF, 0x25F2, WORD_LEN, 0 }, 	// P_BL_P3Q4
{0x36E4, 0xFFFF, 0xDCCA, WORD_LEN, 0 }, 	// P_GB_P3Q0
{0x36E6, 0xFFFF, 0x438E, WORD_LEN, 0 }, 	// P_GB_P3Q1
{0x36E8, 0xFFFF, 0xD64E, WORD_LEN, 0 }, 	// P_GB_P3Q2
{0x36EA, 0xFFFF, 0x8A71, WORD_LEN, 0 }, 	// P_GB_P3Q3
{0x36EC, 0xFFFF, 0x1492, WORD_LEN, 0 }, 	// P_GB_P3Q4
{0x36EE, 0xFFFF, 0xD5B1, WORD_LEN, 0 }, 	// P_GR_P4Q0
{0x36F0, 0xFFFF, 0xEBF0, WORD_LEN, 0 }, 	// P_GR_P4Q1
{0x36F2, 0xFFFF, 0x53F3, WORD_LEN, 0 }, 	// P_GR_P4Q2
{0x36F4, 0xFFFF, 0x3492, WORD_LEN, 0 }, 	// P_GR_P4Q3
{0x36F6, 0xFFFF, 0x9AF4, WORD_LEN, 0 }, 	// P_GR_P4Q4
{0x36F8, 0xFFFF, 0x8BF1, WORD_LEN, 0 }, 	// P_RD_P4Q0
{0x36FA, 0xFFFF, 0x204F, WORD_LEN, 0 }, 	// P_RD_P4Q1
{0x36FC, 0xFFFF, 0x3A93, WORD_LEN, 0 }, 	// P_RD_P4Q2
{0x36FE, 0xFFFF, 0xB551, WORD_LEN, 0 }, 	// P_RD_P4Q3
{0x3700, 0xFFFF, 0xE214, WORD_LEN, 0 }, 	// P_RD_P4Q4
{0x3702, 0xFFFF, 0xF2B0, WORD_LEN, 0 }, 	// P_BL_P4Q0
{0x3704, 0xFFFF, 0x8C30, WORD_LEN, 0 }, 	// P_BL_P4Q1
{0x3706, 0xFFFF, 0x3053, WORD_LEN, 0 }, 	// P_BL_P4Q2
{0x3708, 0xFFFF, 0x64F0, WORD_LEN, 0 }, 	// P_BL_P4Q3
{0x370A, 0xFFFF, 0xFC73, WORD_LEN, 0 }, 	// P_BL_P4Q4
{0x370C, 0xFFFF, 0xD311, WORD_LEN, 0 }, 	// P_GB_P4Q0
{0x370E, 0xFFFF, 0x336F, WORD_LEN, 0 }, 	// P_GB_P4Q1
{0x3710, 0xFFFF, 0x5AF3, WORD_LEN, 0 }, 	// P_GB_P4Q2
{0x3712, 0xFFFF, 0x4EAF, WORD_LEN, 0 }, 	// P_GB_P4Q3
{0x3714, 0xFFFF, 0xDBD4, WORD_LEN, 0 }, 	// P_GB_P4Q4
{0x3644, 0xFFFF, 0x02A0, WORD_LEN, 0 }, 	// POLY_ORIGIN_C
{0x3642, 0xFFFF, 0x01FC, WORD_LEN, 0 }, 	// POLY_ORIGIN_R
{0x3210, 0xFFFF, 0x01B8, WORD_LEN, 0 }, 	// COLOR_PIPELINE_CONTROL
{0x098C, 0xFFFF, 0x2306, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_L_0]
{0x0990, 0xFFFF, 0x0233, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2308, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_L_1]
{0x0990, 0xFFFF, 0xFF0B, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x230A, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_L_2]
{0x0990, 0xFFFF, 0x0024, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x230C, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_L_3]
{0x0990, 0xFFFF, 0xFFC8, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x230E, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_L_4]
{0x0990, 0xFFFF, 0x01DE, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2310, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_L_5]
{0x0990, 0xFFFF, 0xFFBD, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2312, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_L_6]
{0x0990, 0xFFFF, 0x0019, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2314, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_L_7]
{0x0990, 0xFFFF, 0xFF2B, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2316, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_L_8]
{0x0990, 0xFFFF, 0x01E8, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2318, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_L_9]
{0x0990, 0xFFFF, 0x0024, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x231A, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_L_10]
{0x0990, 0xFFFF, 0x0030, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x231C, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_RL_0]
{0x0990, 0xFFFF, 0xFF7D, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x231E, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_RL_1]
{0x0990, 0xFFFF, 0x002C, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2320, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_RL_2]
{0x0990, 0xFFFF, 0x002C, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2322, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_RL_3]
{0x0990, 0xFFFF, 0x0006, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2324, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_RL_4]
{0x0990, 0xFFFF, 0x00A3, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2326, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_RL_5]
{0x0990, 0xFFFF, 0xFF75, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2328, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_RL_6]
{0x0990, 0xFFFF, 0xFFF4, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x232A, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_RL_7]
{0x0990, 0xFFFF, 0x00AC, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x232C, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_RL_8]
{0x0990, 0xFFFF, 0xFF75, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x232E, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_RL_9]
{0x0990, 0xFFFF, 0x0010, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2330, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_RL_10]
{0x0990, 0xFFFF, 0xFFF4, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA348, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_GAIN_BUFFER_SPEED]
{0x0990, 0xFFFF, 0x0008, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA349, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_JUMP_DIVISOR]
{0x0990, 0xFFFF, 0x0002, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA34A, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_GAIN_MIN]
{0x0990, 0xFFFF, 0x0059, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA34B, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_GAIN_MAX]
{0x0990, 0xFFFF, 0x00A6, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA351, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_POSITION_MIN]
{0x0990, 0xFFFF, 0x0000, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA352, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_CCM_POSITION_MAX]
{0x0990, 0xFFFF, 0x007F, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA35D, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_STEADY_BGAIN_OUT_MIN]
{0x0990, 0xFFFF, 0x0078, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA35E, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_STEADY_BGAIN_OUT_MAX]
{0x0990, 0xFFFF, 0x0086, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA35F, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_STEADY_BGAIN_IN_MIN]
{0x0990, 0xFFFF, 0x007E, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA360, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_STEADY_BGAIN_IN_MAX]
{0x0990, 0xFFFF, 0x0082, WORD_LEN, 0 }, 	// MCU_DATA_0// new 20110121 add for cold color
{0x098C, 0xFFFF, 0xA369, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_KR_R]
{0x0990, 0xFFFF, 0x0097, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA36A, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_KG_R]
{0x0990, 0xFFFF, 0x008C, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA36B, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_KB_R]
{0x0990, 0xFFFF, 0x0080, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA302, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_WINDOW_POS]
{0x0990, 0xFFFF, 0x0000, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA303, WORD_LEN, 0 }, 	// MCU_ADDRESS [AWB_WINDOW_SIZE]
{0x0990, 0xFFFF, 0x00FF, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA11D, WORD_LEN, 0 }, 	// MCU_ADDRESS [SEQ_PREVIEW_1_AE]
{0x0990, 0xFFFF, 0x0002, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x271F, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_FRAME_LENGTH_A]
{0x0990, 0xFFFF, 0x032E, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2721, WORD_LEN, 0 }, 	// MCU_ADDRESS [MODE_SENSOR_LINE_LENGTH_PCK_A]
{0x0990, 0xFFFF, 0x04CC, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA216, WORD_LEN, 0 }, 	// MCU_ADDRESS [AE_MAXGAIN23]
{0x0990, 0xFFFF, 0x0060, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA215, WORD_LEN, 0 }, 	// MCU_ADDRESS [AE_INDEX_TH23]
{0x0990, 0xFFFF, 0x000A, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA20C, WORD_LEN, 0 }, 	// MCU_ADDRESS [AE_MAX_INDEX]
{0x0990, 0xFFFF, 0x0028, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA24F, WORD_LEN, 0 }, 	// MCU_ADDRESS [AE_BASETARGET]
{0x0990, 0xFFFF, 0x0042, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA20E, WORD_LEN, 0 }, 	// MCU_ADDRESS [AE_MAX_VIRTGAIN]
{0x0990, 0xFFFF, 0x0060, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA202, WORD_LEN, 0 }, 	// MCU_ADDRESS [AE_WINDOW_POS]
{0x0990, 0xFFFF, 0x0000, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA203, WORD_LEN, 0 }, 	// MCU_ADDRESS [AE_WINDOW_SIZE]
{0x0990, 0xFFFF, 0x00FF, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA207, WORD_LEN, 0 }, 	// MCU_ADDRESS [AE_GATE]
{0x0990, 0xFFFF, 0x0004, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB37, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_MORPH_CTRL]
{0x0990, 0xFFFF, 0x0003, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2B38, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMASTARTMORPH]
{0x0990, 0xFFFF, 0x3A98, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x2B3A, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMASTOPMORPH]
{0x0990, 0xFFFF, 0x5000, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB20, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_LL_SAT1]
{0x0990, 0xFFFF, 0x0023, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB24, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_LL_SAT2]
{0x0990, 0xFFFF, 0x0010, WORD_LEN, 0 }, 	// MCU_DATA_0//gamma a
//Commands to speed up AE speed. Begin--0308
{0x098C, 0xFFFF, 0xA109, WORD_LEN, 0 }, 	// MCU_ADDRESS [SEQ_AE_FASTBUFF]
{0x0990, 0xFFFF, 0x0020, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xA10A, WORD_LEN, 0 }, 	// MCU_ADDRESS [SEQ_AE_FASTSTEP]
{0x0990, 0xFFFF, 0x0002, WORD_LEN, 0 }, 	// MCU_DATA_0
//Commands to speed up AE speed. End--0308
{0x098C, 0xFFFF, 0xAB3C, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_0]
{0x0990, 0xFFFF, 0x0000, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB3D, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_1]
{0x0990, 0xFFFF, 0x0006, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB3E, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_2]
{0x0990, 0xFFFF, 0x0014, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB3F, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_3]
{0x0990, 0xFFFF, 0x0038, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB40, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_4]
{0x0990, 0xFFFF, 0x005F, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB41, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_5]
{0x0990, 0xFFFF, 0x0079, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB42, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_6]
{0x0990, 0xFFFF, 0x008D, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB43, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_7]
{0x0990, 0xFFFF, 0x009E, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB44, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_8]
{0x0990, 0xFFFF, 0x00AC, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB45, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_9]
{0x0990, 0xFFFF, 0x00B8, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB46, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_10]
{0x0990, 0xFFFF, 0x00C3, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB47, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_11]
{0x0990, 0xFFFF, 0x00CD, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB48, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_12]
{0x0990, 0xFFFF, 0x00D5, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB49, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_13]
{0x0990, 0xFFFF, 0x00DE, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB4A, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_14]
{0x0990, 0xFFFF, 0x00E5, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB4B, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_15]
{0x0990, 0xFFFF, 0x00EC, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB4C, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_16]
{0x0990, 0xFFFF, 0x00F3, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB4D, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_17]
{0x0990, 0xFFFF, 0x00F9, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB4E, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_18]
{0x0990, 0xFFFF, 0x00FF, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB2C, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_NR_START_R]
{0x0990, 0xFFFF, 0x0010, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB2D, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_NR_START_G]
{0x0990, 0xFFFF, 0x002A, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB2E, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_NR_START_B]
{0x0990, 0xFFFF, 0x0010, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB2F, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_NR_START_OL]
{0x0990, 0xFFFF, 0x0010, WORD_LEN, 0 }, 	// MCU_DATA_0// new gamma B
{0x098C, 0xFFFF, 0xAB4F, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_0]
{0x0990, 0xFFFF, 0x0000, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB50, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_1]
{0x0990, 0xFFFF, 0x0004, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB51, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_2]
{0x0990, 0xFFFF, 0x000D, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB52, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_3]
{0x0990, 0xFFFF, 0x0028, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB53, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_4]
{0x0990, 0xFFFF, 0x0053, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB54, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_5]
{0x0990, 0xFFFF, 0x0075, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB55, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_6]
{0x0990, 0xFFFF, 0x0092, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB56, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_7]
{0x0990, 0xFFFF, 0x00A7, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB57, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_8]
{0x0990, 0xFFFF, 0x00B7, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB58, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_9]
{0x0990, 0xFFFF, 0x00C4, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB59, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_10]
{0x0990, 0xFFFF, 0x00CF, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB5A, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_11]
{0x0990, 0xFFFF, 0x00D8, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB5B, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_12]
{0x0990, 0xFFFF, 0x00DF, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB5C, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_13]
{0x0990, 0xFFFF, 0x00E6, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB5D, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_14]
{0x0990, 0xFFFF, 0x00EC, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB5E, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_15]
{0x0990, 0xFFFF, 0x00F2, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB5F, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_16]
{0x0990, 0xFFFF, 0x00F6, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB60, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_17]
{0x0990, 0xFFFF, 0x00FB, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0xAB61, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_B_18]
{0x0990, 0xFFFF, 0x00FF, WORD_LEN, 0 }, 	// MCU_DATA_0//
//Normal data readout, no mirror no flip --Begin
{0x098C, 0xFFFF, 0x2717, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_18]
{0x0990, 0xFFFF, 0x046C, WORD_LEN, 0 }, 	// MCU_DATA_0
{0x098C, 0xFFFF, 0x272D, WORD_LEN, 0 }, 	// MCU_ADDRESS [HG_GAMMA_TABLE_A_18]
{0x0990, 0xFFFF, 0x0024, WORD_LEN, 0 }, 	// MCU_DATA_0
//Normal data readout, no mirror no flip --End
//Move RESET command here to resolve abnormal preview color issue. --0126
{0x001A, 0xFFFF, 0x021C, WORD_LEN, 0 }, 	// RESET_AND_MISC_CONTROL
{0x098C, 0xFFFF, 0xA103, WORD_LEN, 0 }, 	// MCU_ADDRESS
//{0x0990, 0xFFFF, 0x0006, WORD_LEN, 120}, 	// MCU_DATA_0 //DELAY= 120
//Here will use polling instead of delay to avoid "black screen issue"--0129
{0x0990, 0xFFFF, 0x0006, WORD_LEN, 0 }, 	// MCU_DATA_0 //DELAY= 120
//Settings below will be applied in codes.-- 0129
//{0x098C, 0xFFFF, 0xA103, WORD_LEN, 0 }, 	// MCU_ADDRESS
//{0x0990, 0xFFFF, 0x0005, WORD_LEN, 120}, 	// MCU_DATA_0 //DELAY= 120
//{0x001A, 0xFFFF, 0x021C, WORD_LEN, 0 }, 	// RESET_AND_MISC_CONTROL
//{0x3400, 0xFFFF, 0x7A08, WORD_LEN, 0 }, 	// MIPI_CONTROL

};

static const struct mt9m113_i2c_reg_conf const pll_setup_tbl[] = {
	{0x0014, 0x0001, 0x0001, WORD_LEN, 0},  // Bypass PLL
	{0x0014, 0x0002, 0x0000, WORD_LEN, 0},  // Power-down PLL
	{0x0014, 0xFFFF, 0x2145, WORD_LEN, 0},	//PLL control: BYPASS PLL = 8517
	{0x0010, 0xFFFF, 0x0A6E, WORD_LEN, 0},	//PLL Dividers = 2670
	{0x0012, 0xFFFF, 0x00F1, WORD_LEN, 0},	//PLL P Dividers = 241
	{0x0014, 0xFFFF, 0x2545, WORD_LEN, 0},	//PLL control: TEST_BYPASS on = 9541
	{0x0014, 0xFFFF, 0x2547, WORD_LEN, 0},	//PLL control: PLL_ENABLE on = 9543
	{0x0014, 0xFFFF, 0x3447, WORD_LEN, 1},	//PLL control: SEL_LOCK_DET on = 13383
	{0x0014, 0xFFFF, 0x3047, WORD_LEN, 0},	//PLL control: TEST_BYPASS off = 12359
	{0x0014, 0xFFFF, 0x3046, WORD_LEN, 0},	//PLL control: PLL_BYPASS off = 12358
	{0x001A, 0x0008, 0x0001, WORD_LEN, 0},	//PLL Reset Control: OUTPUT, bits 0x0008 = 1
	{0x0018, 0x0001, 0x0000, WORD_LEN, 0},	//PLL Standby: Out of Standby, bits 0x0001 = 0
};

/* Refresh Sequencer */
static const struct mt9m113_i2c_reg_conf const sequencer_tbl[] = {
	{ 0x098C, 0xFFFF, 0xA103, WORD_LEN, 0},
	{ 0x0990, 0xFFFF, 0x0005, WORD_LEN, 5},
	{ 0x098C, 0xFFFF, 0xA103, WORD_LEN, 0},
	{ 0x0990, 0xFFFF, 0x0006, WORD_LEN, 5}
};

struct mt9m113_reg mt9m113_regs = {
	.prev_snap_reg_tbl = &preview_snapshot_mode_reg_tbl[0],
	.prev_snap_reg_tbl_size = 
		ARRAY_SIZE( preview_snapshot_mode_reg_tbl),
	.plltbl = pll_setup_tbl,
	.plltbl_size = ARRAY_SIZE(pll_setup_tbl),
	.stbl = sequencer_tbl,
	.stbl_size = ARRAY_SIZE(sequencer_tbl),
};


