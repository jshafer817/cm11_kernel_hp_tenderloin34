/* linux/arch/arm/mach-msm/devices.c
 *
 * Copyright (C) 2008 Google, Inc.
 * Copyright (C) 2007-2009 HTC Corporation.
 * Author: Thomas Tsai <thomas_tsai@htc.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <asm/setup.h>
#include <mach/board.h>
#include <mach/msm_iomap.h>
#include <linux/mtd/nand.h>
#include <linux/module.h>

#define MFG_GPIO_TABLE_MAX_SIZE        0x400
static unsigned char mfg_gpio_table[MFG_GPIO_TABLE_MAX_SIZE];

#define ATAG_MEMSIZE 0x5441001e
unsigned memory_size;
int __init parse_tag_memsize(const struct tag *tags)
{
	int mem_size = 0, find = 0;
	struct tag *t = (struct tag *)tags;

	for (; t->hdr.size; t = tag_next(t)) {
		if (t->hdr.tag == ATAG_MEMSIZE) {
			printk(KERN_DEBUG "find the memsize tag\n");
			find = 1;
			break;
		}
	}

	if (find) {
		memory_size = t->u.revision.rev;
		mem_size = t->u.revision.rev;
	}
	printk(KERN_DEBUG "parse_tag_memsize: %d\n", memory_size);
	return mem_size;
}
__tagtable(ATAG_MEMSIZE, parse_tag_memsize);

#define ATAG_SMI 0x4d534D71
/* setup calls mach->fixup, then parse_tags, parse_cmdline
 * We need to setup meminfo in mach->fixup, so this function
 * will need to traverse each tag to find smi tag.
 */
int __init parse_tag_smi(const struct tag *tags)
{
	int smi_sz = 0, find = 0;
	struct tag *t = (struct tag *)tags;

	for (; t->hdr.size; t = tag_next(t)) {
		if (t->hdr.tag == ATAG_SMI) {
			printk(KERN_DEBUG "find the smi tag\n");
			find = 1;
			break;
		}
	}
	if (!find)
		return -1;

	printk(KERN_DEBUG "parse_tag_smi: smi size = %d\n", t->u.mem.size);
	smi_sz = t->u.mem.size;
	return smi_sz;
}
__tagtable(ATAG_SMI, parse_tag_smi);


#define ATAG_HWID 0x4d534D72
int __init parse_tag_hwid(const struct tag *tags)
{
	int hwid = 0, find = 0;
	struct tag *t = (struct tag *)tags;

	for (; t->hdr.size; t = tag_next(t)) {
		if (t->hdr.tag == ATAG_HWID) {
			printk(KERN_DEBUG "find the hwid tag\n");
			find = 1;
			break;
		}
	}

	if (find)
		hwid = t->u.revision.rev;
	printk(KERN_DEBUG "parse_tag_hwid: hwid = 0x%x\n", hwid);
	return hwid;
}
__tagtable(ATAG_HWID, parse_tag_hwid);

#define ATAG_SKUID 0x4d534D73
int __init parse_tag_skuid(const struct tag *tags)
{
	int skuid = 0, find = 0;
	struct tag *t = (struct tag *)tags;

	for (; t->hdr.size; t = tag_next(t)) {
		if (t->hdr.tag == ATAG_SKUID) {
			printk(KERN_DEBUG "find the skuid tag\n");
			find = 1;
			break;
		}
	}

	if (find)
		skuid = t->u.revision.rev;
	printk(KERN_DEBUG "parse_tag_skuid: hwid = 0x%x\n", skuid);
	return skuid;
}
__tagtable(ATAG_SKUID, parse_tag_skuid);

/* Proximity sensor calibration values */

unsigned int als_kadc;
EXPORT_SYMBOL(als_kadc);
static int __init parse_tag_als_calibration(const struct tag *tag)
{
	als_kadc = tag->u.als_kadc.kadc;

	return 0;
}

__tagtable(ATAG_ALS, parse_tag_als_calibration);

#define ATAG_WS		0x54410023

unsigned int ws_kadc;
EXPORT_SYMBOL(ws_kadc);
static int __init parse_tag_ws_calibration(const struct tag *tag)
{
	ws_kadc = tag->u.als_kadc.kadc;

	return 0;
}

__tagtable(ATAG_WS, parse_tag_ws_calibration);

/* SMLOG values */
#define ATAG_SMLOG     0x54410023

int __init parse_tag_smlog(const struct tag *tags)
{
	int smlog_flag = 0, find = 0;
	struct tag *t = (struct tag *)tags;

	for (; t->hdr.size; t = tag_next(t)) {
		if (t->hdr.tag == ATAG_SMLOG) {
			printk(KERN_DEBUG "[K] find the smlog tag\n");
			find = 1;
			break;
		}
	}

	if (find) {
		smlog_flag = t->u.revision.rev;
	}

	printk(KERN_DEBUG "[K] parse_tag_smlog: %d\n", smlog_flag);
	return smlog_flag;
}
__tagtable(ATAG_SMLOG, parse_tag_smlog);

#define ATAG_ENGINEERID 0x4d534D75
unsigned engineerid;
EXPORT_SYMBOL(engineerid);
int __init parse_tag_engineerid(const struct tag *tags)
{
	int find = 0;
	struct tag *t = (struct tag *)tags;

	for (; t->hdr.size; t = tag_next(t)) {
		if (t->hdr.tag == ATAG_ENGINEERID) {
			printk(KERN_DEBUG "find the engineer tag\n");
			find = 1;
			break;
		}
	}

	if (find)
		engineerid = t->u.revision.rev;
	printk(KERN_DEBUG "parse_tag_engineerid: hwid = 0x%x\n", engineerid);
	return engineerid;
}
__tagtable(ATAG_ENGINEERID, parse_tag_engineerid);


/* G-Sensor calibration value */
#define ATAG_GS         0x5441001d

unsigned int gs_kvalue;
EXPORT_SYMBOL(gs_kvalue);

static int __init parse_tag_gs_calibration(const struct tag *tag)
{
	gs_kvalue = tag->u.revision.rev;
	printk(KERN_DEBUG "%s: gs_kvalue = 0x%x\n", __func__, gs_kvalue);
	return 0;
}

__tagtable(ATAG_GS, parse_tag_gs_calibration);

/* Proximity sensor calibration values */
#define ATAG_PS         0x5441001c

unsigned int ps_kparam1;
EXPORT_SYMBOL(ps_kparam1);

unsigned int ps_kparam2;
EXPORT_SYMBOL(ps_kparam2);

static int __init parse_tag_ps_calibration(const struct tag *tag)
{
	ps_kparam1 = tag->u.serialnr.low;
	ps_kparam2 = tag->u.serialnr.high;

	printk(KERN_INFO "%s: ps_kparam1 = 0x%x, ps_kparam2 = 0x%x\n",
		__func__, ps_kparam1, ps_kparam2);

	return 0;
}

__tagtable(ATAG_PS, parse_tag_ps_calibration);

/* camera values */
#define ATAG_CAM	0x54410021

int __init parse_tag_cam(const struct tag *tags)
{
	int mem_size = 0, find = 0;
	struct tag *t = (struct tag *)tags;

	for (; t->hdr.size; t = tag_next(t)) {
		if (t->hdr.tag == ATAG_CAM) {
			printk(KERN_DEBUG "find the memsize tag\n");
			find = 1;
			break;
		}
	}

	if (find)
		mem_size = t->u.revision.rev;
	printk(KERN_DEBUG "parse_tag_memsize: %d\n", mem_size);
	return mem_size;
}
__tagtable(ATAG_CAM, parse_tag_cam);

int batt_stored_magic_num;
int batt_stored_soc;
int batt_stored_ocv_uv;
int batt_stored_cc_uv;
unsigned long batt_stored_time_ms;

static int __init parse_tag_stored_batt_data(const struct tag *tags)
{
	int find = 0;
	struct tag *t = (struct tag *)tags;

	for (; t->hdr.size; t = tag_next(t)) {
		if (t->hdr.tag == ATAG_BATT_DATA) {
			printk(KERN_DEBUG "find the stored batt data tag\n");
			find = 1;
			break;
		}
	}

	if (find) {
		batt_stored_magic_num = t->u.batt_data.magic_num;
		batt_stored_soc = t->u.batt_data.soc;
		batt_stored_ocv_uv = t->u.batt_data.ocv;
		batt_stored_cc_uv = t->u.batt_data.cc;
		batt_stored_time_ms = t->u.batt_data.currtime;
		printk(KERN_INFO "batt_data: magic_num=%x, soc=%d, "
			"ocv_uv=%x, cc_uv=%x, stored_time=%ld\n",
			batt_stored_magic_num, batt_stored_soc, batt_stored_ocv_uv,
			batt_stored_cc_uv, batt_stored_time_ms);
	}
	return 0;
}
__tagtable(ATAG_BATT_DATA, parse_tag_stored_batt_data);

/* Gyro/G-senosr calibration values */
#define ATAG_GRYO_GSENSOR	0x54410020
unsigned char gyro_gsensor_kvalue[37];
EXPORT_SYMBOL(gyro_gsensor_kvalue);

static int __init parse_tag_gyro_gsensor_calibration(const struct tag *tag)
{
	int i;
	unsigned char *ptr = (unsigned char *)&tag->u;
	memcpy(&gyro_gsensor_kvalue[0], ptr, sizeof(gyro_gsensor_kvalue));

	printk(KERN_DEBUG "gyro_gs data\n");
	for (i = 0; i < sizeof(gyro_gsensor_kvalue); i++)
		printk(KERN_DEBUG "[%d]:0x%x", i, gyro_gsensor_kvalue[i]);

	return 0;
}
__tagtable(ATAG_GRYO_GSENSOR, parse_tag_gyro_gsensor_calibration);

BLOCKING_NOTIFIER_HEAD(psensor_notifier_list);
int register_notifier_by_psensor(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&psensor_notifier_list, nb);
}

int unregister_notifier_by_psensor(struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&psensor_notifier_list, nb);
}

#if defined(CONFIG_TOUCH_KEY_FILTER)
BLOCKING_NOTIFIER_HEAD(touchkey_notifier_list);
int register_notifier_by_touchkey(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&touchkey_notifier_list, nb);
}

int unregister_notifier_by_touchkey(struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&touchkey_notifier_list, nb);
}
#endif

#define ATAG_HERO_PANEL_TYPE 0x4d534D74
int panel_type;
int __init tag_panel_parsing(const struct tag *tags)
{
	panel_type = tags->u.revision.rev;

	printk(KERN_DEBUG "%s: panel type = %d\n", __func__,
		panel_type);

	return panel_type;
}
__tagtable(ATAG_HERO_PANEL_TYPE, tag_panel_parsing);

#define ATAG_MFG_GPIO_TABLE 0x59504551
int __init parse_tag_mfg_gpio_table(const struct tag *tags)
{
       unsigned char *dptr = (unsigned char *)(&tags->u);
       __u32 size;

       size = min((__u32)(tags->hdr.size - 2) * sizeof(__u32), (__u32)MFG_GPIO_TABLE_MAX_SIZE);
       memcpy(mfg_gpio_table, dptr, size);
       return 0;
}
__tagtable(ATAG_MFG_GPIO_TABLE, parse_tag_mfg_gpio_table);

char *board_get_mfg_sleep_gpio_table(void)
{
	return mfg_gpio_table;
}
EXPORT_SYMBOL(board_get_mfg_sleep_gpio_table);
static int mfg_mode;
static int fullramdump_flag;
int __init board_mfg_mode_init(char *s)
{
	if (!strcmp(s, "normal"))
		mfg_mode = 0;
	else if (!strcmp(s, "factory2"))
		mfg_mode = 1;
	else if (!strcmp(s, "recovery"))
		mfg_mode = 2;
	else if (!strcmp(s, "charge"))
		mfg_mode = 3;
	else if (!strcmp(s, "power_test"))
		mfg_mode = 4;
	else if (!strcmp(s, "offmode_charging"))
		mfg_mode = 5;
	else if (!strcmp(s, "mfgkernel:diag58"))
		mfg_mode = 6;
	else if (!strcmp(s, "gift_mode"))
		mfg_mode = 7;
	else if (!strcmp(s, "mfgkernel"))
		mfg_mode = 8;
	else if (!strcmp(s, "mini") || !strcmp(s, "skip_9k_mini")) {
		mfg_mode = 9;
		fullramdump_flag = 0;
	} else if (!strcmp(s, "mini:1gdump")) {
		mfg_mode = 9;
		fullramdump_flag = 1;
	}
	return 1;
}
__setup("androidboot.mode=", board_mfg_mode_init);


int board_mfg_mode(void)
{
	return mfg_mode;
}

EXPORT_SYMBOL(board_mfg_mode);


int board_fullramdump_flag(void)
{
	return fullramdump_flag;
}

EXPORT_SYMBOL(board_fullramdump_flag);

static int build_flag;

static int __init board_bootloader_setup(char *str)
{
	char temp[strlen(str) + 1];
	char *p = NULL;
	char *build = NULL;
	char *args = temp;

	printk(KERN_INFO "%s: %s\n", __func__, str);

	strcpy(temp, str);

	/*parse the last parameter*/
	while ((p = strsep(&args, ".")) != NULL) build = p;

	/* Sometime hboot version would change from .X000 to .X001, .X002,...
	 * So compare the first character to avoid unnecessary error.
	 */
	if (build) {
		if (build[0] == '0') {
			printk(KERN_INFO "%s: SHIP BUILD\n", __func__);
			build_flag = SHIP_BUILD;
		} else if (build[0] == '2') {
			printk(KERN_INFO "%s: ENG BUILD\n", __func__);
			build_flag = ENG_BUILD;
		} else if (build[0] == '1') {
			printk(KERN_INFO "%s: MFG BUILD\n", __func__);
			build_flag = MFG_BUILD;
		} else {
			printk(KERN_INFO "%s: default ENG BUILD\n", __func__);
			build_flag = ENG_BUILD;
		}
	}
	return 1;
}
__setup("androidboot.bootloader=", board_bootloader_setup);

int board_build_flag(void)
{
	return build_flag;
}
EXPORT_SYMBOL(board_build_flag);

/* ISL29028 ID values */
#define ATAG_PS_TYPE 0x4d534D77
int ps_type;
EXPORT_SYMBOL(ps_type);
int __init tag_ps_parsing(const struct tag *tags)
{
	ps_type = tags->u.revision.rev;

	printk(KERN_DEBUG "%s: PS type = 0x%x\n", __func__,
		ps_type);

	return ps_type;
}
__tagtable(ATAG_PS_TYPE, tag_ps_parsing);

/* Gyro ID values */
#define ATAG_GY_TYPE 0x4d534D78
int gy_type;
EXPORT_SYMBOL(gy_type);
int __init tag_gy_parsing(const struct tag *tags)
{
	gy_type = tags->u.revision.rev;

	printk(KERN_DEBUG "%s: Gyro type = 0x%x\n", __func__,
		gy_type);

	return gy_type;
}
__tagtable(ATAG_GY_TYPE, tag_gy_parsing);

static unsigned long radio_flag;
int __init radio_flag_init(char *s)
{
	int ret = 0;
	ret = strict_strtoul(s, 16, &radio_flag);
	if (ret != 0)
		pr_err("%s: radio flag cannot be parsed from `%s'\r\n", __func__, s);
	return 1;
}
__setup("radioflag=", radio_flag_init);

unsigned int get_radio_flag(void)
{
	return radio_flag;
}

static unsigned long kernel_flag;
int __init kernel_flag_init(char *s)
{
	int ret;
	ret = strict_strtoul(s, 16, &kernel_flag);
	if (ret != 0)
		pr_err("%s: kernel flag cannot be parsed from `%s'\r\n", __func__, s);
	return 1;
}
__setup("kernelflag=", kernel_flag_init);

unsigned long get_kernel_flag(void)
{
	return kernel_flag;
}

static char *sku_color_tag = NULL;
static int __init board_set_qwerty_color_tag(char *get_sku_color)
{
	if (strlen(get_sku_color))
		sku_color_tag = get_sku_color;
	else
		sku_color_tag = NULL;
	return 1;
}
__setup("androidboot.qwerty_color=", board_set_qwerty_color_tag);

void board_get_sku_color_tag(char **ret_data)
{
	*ret_data = sku_color_tag;
}
EXPORT_SYMBOL(board_get_sku_color_tag);

static unsigned long boot_powerkey_debounce_ms;
int __init boot_powerkey_debounce_time_init(char *s)
{
	int ret;
	ret = strict_strtoul(s, 16, &boot_powerkey_debounce_ms);
	if (ret != 0)
		pr_err("%s: boot_powerkey_debounce_ms cannot be parsed from `%s'\r\n", __func__, s);
	return 1;
}
__setup("bpht=", boot_powerkey_debounce_time_init);

int board_get_boot_powerkey_debounce_time(void)
{
	return boot_powerkey_debounce_ms;
}
EXPORT_SYMBOL(board_get_boot_powerkey_debounce_time);

static unsigned long usb_ats;
int __init board_ats_init(char *s)
{
	int ret;
	ret = strict_strtoul(s, 16, &usb_ats);
	if (ret != 0)
		pr_err("%s: usb_ats cannot be parsed from `%s'\r\n", __func__, s);
	return 1;
}
__setup("ats=", board_ats_init);

static char android_serialno[16] = {0};
static int __init board_serialno_setup(char *serialno)
{
	pr_info("%s: set serial no to %s\r\n", __func__, serialno);
	strncpy(android_serialno, serialno, sizeof(android_serialno)/sizeof(android_serialno[0]) - 1);
	return 1;
}
__setup("androidboot.serialno=", board_serialno_setup);

char *board_serialno(void)
{
	return android_serialno;
}
EXPORT_SYMBOL(board_serialno);

int board_get_usb_ats(void)
{
	return usb_ats;
}
EXPORT_SYMBOL(board_get_usb_ats);

static int tamper_sf;
int __init check_tamper_sf(char *s)
{
	tamper_sf = simple_strtoul(s, 0, 10);
	return 1;
}
__setup("td.sf=", check_tamper_sf);

unsigned int get_tamper_sf(void)
{
	return tamper_sf;
}
EXPORT_SYMBOL(get_tamper_sf);

static int ls_setting = 0;
#define FAKE_ID 2
#define REAL_ID 1
int __init board_ls_setting(char *s)
{
	if (!strcmp(s, "0x1"))
		ls_setting = REAL_ID;
	else if (!strcmp(s, "0x2"))
		ls_setting = FAKE_ID;

	return 1;
}
__setup("lscd=", board_ls_setting);

int get_ls_setting(void)
{
	return ls_setting;
}
EXPORT_SYMBOL(get_ls_setting);

static char *keycap_tag = NULL;
static int __init board_keycaps_tag(char *get_keypads)
{
	if(strlen(get_keypads))
		keycap_tag = get_keypads;
	else
		keycap_tag = NULL;
	return 1;
}
__setup("androidboot.keycaps=", board_keycaps_tag);

void board_get_keycaps_tag(char **ret_data)
{
	*ret_data = keycap_tag;
}
EXPORT_SYMBOL(board_get_keycaps_tag);

static char *cid_tag = NULL;
static int __init board_set_cid_tag(char *get_hboot_cid)
{
	if(strlen(get_hboot_cid))
		cid_tag = get_hboot_cid;
	else
		cid_tag = NULL;
	return 1;
}
__setup("androidboot.cid=", board_set_cid_tag);

void board_get_cid_tag(char **ret_data)
{
	*ret_data = cid_tag;
}
EXPORT_SYMBOL(board_get_cid_tag);

static char *carrier_tag = NULL;
static int __init board_set_carrier_tag(char *get_hboot_carrier)
{
	if(strlen(get_hboot_carrier))
		carrier_tag = get_hboot_carrier;
	else
		carrier_tag = NULL;
	return 1;
}
__setup("androidboot.carrier=", board_set_carrier_tag);

void board_get_carrier_tag(char **ret_data)
{
	*ret_data = carrier_tag;
}
EXPORT_SYMBOL(board_get_carrier_tag);

#ifdef CONFIG_ARCH_MSM8930
#define MSM_RAM_CONSOLE_BASE   0x8F900000
#elif defined(CONFIG_ARCH_MSM8X60)
#define MSM_RAM_CONSOLE_BASE   0x40300000
#elif defined(CONFIG_ARCH_MSM7X30)
#define MSM_RAM_CONSOLE_BASE   0x00500000
#elif defined(CONFIG_ARCH_APQ8064)
#define MSM_RAM_CONSOLE_BASE   0x8F100000
#else
#define MSM_RAM_CONSOLE_BASE	MSM_HTC_RAM_CONSOLE_PHYS
#endif
#ifdef CONFIG_ARCH_MSM7X30
#define MSM_RAM_CONSOLE_SIZE	0x00100000
#else
#ifdef MSM_RAM_CONSOLE_SIZE
#define MSM_RAM_CONSOLE_SIZE	MSM_HTC_RAM_CONSOLE_SIZE
#else
#define MSM_RAM_CONSOLE_SIZE   (SZ_1M - SZ_128K) /* 128K for debug info */
#endif
#endif

static struct resource ram_console_resources[] = {
	{
		.start	= MSM_RAM_CONSOLE_BASE,
		.end	= MSM_RAM_CONSOLE_BASE + MSM_RAM_CONSOLE_SIZE - 1,
		.flags	= IORESOURCE_MEM,
	},
};

static struct platform_device ram_console_device = {
	.name		= "ram_console",
	.id		= -1,
        .num_resources	= ARRAY_SIZE(ram_console_resources),
        .resource	= ram_console_resources,
};

void __init htc_add_ramconsole_devices(void)
{
	platform_device_register(&ram_console_device);
}
