/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright 2016-2018, 2020 NXP
 * Copyright 2015, Freescale Semiconductor
 */

#ifndef _ASM_ARMV8_FSL_LAYERSCAPE_CONFIG_H_
#define _ASM_ARMV8_FSL_LAYERSCAPE_CONFIG_H_

#include <fsl_ddrc_version.h>

#ifndef __ASSEMBLY__
#include <linux/bitops.h>
#endif

/*
 * Reserve secure memory
 * To be aligned with MMU block size
 */
#define CFG_SYS_MEM_RESERVE_SECURE	(66 * 1024 * 1024)	/* 66MB */
#define SPL_TLB_SETBACK	0x1000000	/* 16MB under effective memory top */

#ifdef CONFIG_ARCH_LS2080A
#define CFG_SYS_FSL_CLUSTER_CLOCKS		{ 1, 1, 4, 4 }
#define	SRDS_MAX_LANES	8
#define CFG_SYS_PAGE_SIZE		0x10000
#ifndef L1_CACHE_BYTES
#define L1_CACHE_SHIFT		6
#define L1_CACHE_BYTES		BIT(L1_CACHE_SHIFT)
#endif

#define CFG_SYS_FSL_OCRAM_BASE	0x18000000 /* initial RAM */
#define SYS_FSL_OCRAM_SPACE_SIZE	0x00200000 /* 2M space */
#define CFG_SYS_FSL_OCRAM_SIZE	0x00020000 /* Real size 128K */

/* DDR */
#define CFG_SYS_DDR_BLOCK1_SIZE	((phys_size_t)2 << 30)
#define CFG_MAX_MEM_MAPPED		CFG_SYS_DDR_BLOCK1_SIZE

/* Generic Interrupt Controller Definitions */
#define GICD_BASE			0x06000000
#define GICR_BASE			0x06100000

/* SMMU Defintions */
#define SMMU_BASE			0x05000000 /* GR0 Base */

/* Cache Coherent Interconnect */
#define CCI_MN_BASE			0x04000000
#define CCI_MN_RNF_NODEID_LIST		0x180
#define CCI_MN_DVM_DOMAIN_CTL		0x200
#define CCI_MN_DVM_DOMAIN_CTL_SET	0x210

#define CCI_HN_F_0_BASE			(CCI_MN_BASE + 0x200000)
#define CCI_HN_F_1_BASE			(CCI_MN_BASE + 0x210000)
#define CCN_HN_F_SAM_CTL		0x8	/* offset on base HN_F base */
#define CCN_HN_F_SAM_NODEID_MASK	0x7f
#define CCN_HN_F_SAM_NODEID_DDR0	0x4
#define CCN_HN_F_SAM_NODEID_DDR1	0xe

#define CCI_RN_I_0_BASE			(CCI_MN_BASE + 0x800000)
#define CCI_RN_I_2_BASE			(CCI_MN_BASE + 0x820000)
#define CCI_RN_I_6_BASE			(CCI_MN_BASE + 0x860000)
#define CCI_RN_I_12_BASE		(CCI_MN_BASE + 0x8C0000)
#define CCI_RN_I_16_BASE		(CCI_MN_BASE + 0x900000)
#define CCI_RN_I_20_BASE		(CCI_MN_BASE + 0x940000)

#define CCI_S0_QOS_CONTROL_BASE(x) ((CCI_RN_I_0_BASE + (x * 0x10000)) + 0x10)
#define CCI_S1_QOS_CONTROL_BASE(x) ((CCI_RN_I_0_BASE + (x * 0x10000)) + 0x110)
#define CCI_S2_QOS_CONTROL_BASE(x) ((CCI_RN_I_0_BASE + (x * 0x10000)) + 0x210)

#define CCI_AUX_CONTROL_BASE(x) ((CCI_RN_I_0_BASE + (x * 0x10000)) + 0x0500)

/* TZ Protection Controller Definitions */
#define TZPC_BASE				0x02200000
#define TZPCR0SIZE_BASE				(TZPC_BASE)
#define TZPCDECPROT_0_STAT_BASE			(TZPC_BASE + 0x800)
#define TZPCDECPROT_0_SET_BASE			(TZPC_BASE + 0x804)
#define TZPCDECPROT_0_CLR_BASE			(TZPC_BASE + 0x808)
#define TZPCDECPROT_1_STAT_BASE			(TZPC_BASE + 0x80C)
#define TZPCDECPROT_1_SET_BASE			(TZPC_BASE + 0x810)
#define TZPCDECPROT_1_CLR_BASE			(TZPC_BASE + 0x814)
#define TZPCDECPROT_2_STAT_BASE			(TZPC_BASE + 0x818)
#define TZPCDECPROT_2_SET_BASE			(TZPC_BASE + 0x81C)
#define TZPCDECPROT_2_CLR_BASE			(TZPC_BASE + 0x820)

#define DCSR_CGACRE5		0x700070914ULL
#define EPU_EPCMPR5		0x700060914ULL
#define EPU_EPCCR5		0x700060814ULL
#define EPU_EPSMCR5		0x700060228ULL
#define EPU_EPECR5		0x700060314ULL
#define EPU_EPCTR5		0x700060a14ULL
#define EPU_EPGCR		0x700060000ULL

#elif defined(CONFIG_ARCH_LS1088A)
#define CFG_SYS_FSL_CLUSTER_CLOCKS		{ 1, 1 }
#define CFG_SYS_PAGE_SIZE		0x10000

#define	SRDS_MAX_LANES	4
#define	SRDS_BITS_PER_LANE	4

/* TZ Protection Controller Definitions */
#define TZPC_BASE				0x02200000
#define TZPCR0SIZE_BASE				(TZPC_BASE)
#define TZPCDECPROT_0_STAT_BASE			(TZPC_BASE + 0x800)
#define TZPCDECPROT_0_SET_BASE			(TZPC_BASE + 0x804)
#define TZPCDECPROT_0_CLR_BASE			(TZPC_BASE + 0x808)
#define TZPCDECPROT_1_STAT_BASE			(TZPC_BASE + 0x80C)
#define TZPCDECPROT_1_SET_BASE			(TZPC_BASE + 0x810)
#define TZPCDECPROT_1_CLR_BASE			(TZPC_BASE + 0x814)
#define TZPCDECPROT_2_STAT_BASE			(TZPC_BASE + 0x818)
#define TZPCDECPROT_2_SET_BASE			(TZPC_BASE + 0x81C)
#define TZPCDECPROT_2_CLR_BASE			(TZPC_BASE + 0x820)

/* Generic Interrupt Controller Definitions */
#define GICD_BASE			0x06000000
#define GICR_BASE			0x06100000

/* SMMU Defintions */
#define SMMU_BASE			0x05000000 /* GR0 Base */

/* DDR */
#define CFG_SYS_DDR_BLOCK1_SIZE	((phys_size_t)2 << 30)
#define CFG_MAX_MEM_MAPPED		CFG_SYS_DDR_BLOCK1_SIZE

/* DCFG - GUR */
#define CFG_SYS_FSL_OCRAM_BASE	0x18000000 /* initial RAM */
#define SYS_FSL_OCRAM_SPACE_SIZE	0x00200000 /* 2M space */
#define CFG_SYS_FSL_OCRAM_SIZE	0x00020000 /* Real size 128K */

/* LX2160A/LX2162A Soc Support */
#elif defined(CONFIG_ARCH_LX2160A) || defined(CONFIG_ARCH_LX2162A)
#define TZPC_BASE				0x02200000
#define TZPCDECPROT_0_SET_BASE			(TZPC_BASE + 0x804)
#define SRDS_MAX_LANES  8
#ifndef L1_CACHE_BYTES
#define L1_CACHE_SHIFT		6
#define L1_CACHE_BYTES		BIT(L1_CACHE_SHIFT)
#endif
#define CFG_SYS_FSL_CLUSTER_CLOCKS		{ 1, 1, 1, 1, 4, 4, 4, 4 }

#define CFG_SYS_PAGE_SIZE			0x10000

#define CFG_SYS_FSL_OCRAM_BASE		0x18000000 /* initial RAM */
#define SYS_FSL_OCRAM_SPACE_SIZE		0x00200000 /* 2M space */
#define CFG_SYS_FSL_OCRAM_SIZE		0x00040000 /* Real size 256K */

/* DDR */
#define CFG_SYS_DDR_BLOCK1_SIZE		((phys_size_t)2 << 30)
#define CFG_MAX_MEM_MAPPED			CFG_SYS_DDR_BLOCK1_SIZE

/* Generic Interrupt Controller Definitions */
#define GICD_BASE				0x06000000
#define GICR_BASE				0x06200000

/* SMMU Definitions */
#define SMMU_BASE				0x05000000 /* GR0 Base */

/* DCFG - GUR */

#elif defined(CONFIG_ARCH_LS1028A)
#define CFG_SYS_FSL_CLUSTER_CLOCKS		{ 1, 1 }

/* TZ Protection Controller Definitions */
#define TZPC_BASE				0x02200000
#define TZPCR0SIZE_BASE				(TZPC_BASE)
#define TZPCDECPROT_0_STAT_BASE			(TZPC_BASE + 0x800)
#define TZPCDECPROT_0_SET_BASE			(TZPC_BASE + 0x804)
#define TZPCDECPROT_0_CLR_BASE			(TZPC_BASE + 0x808)
#define TZPCDECPROT_1_STAT_BASE			(TZPC_BASE + 0x80C)
#define TZPCDECPROT_1_SET_BASE			(TZPC_BASE + 0x810)
#define TZPCDECPROT_1_CLR_BASE			(TZPC_BASE + 0x814)
#define TZPCDECPROT_2_STAT_BASE			(TZPC_BASE + 0x818)
#define TZPCDECPROT_2_SET_BASE			(TZPC_BASE + 0x81C)
#define TZPCDECPROT_2_CLR_BASE			(TZPC_BASE + 0x820)

#define	SRDS_MAX_LANES	4
#define	SRDS_BITS_PER_LANE	4

#define CFG_SYS_FSL_OCRAM_BASE		0x18000000 /* initial RAM */
#define SYS_FSL_OCRAM_SPACE_SIZE		0x00200000 /* 2M */
#define CFG_SYS_FSL_OCRAM_SIZE		0x00040000 /* Real size 256K */

/* Generic Interrupt Controller Definitions */
#define GICD_BASE				0x06000000
#define GICR_BASE				0x06040000

/* SMMU Definitions */
#define SMMU_BASE				0x05000000 /* GR0 Base */

/* DDR */
#define CFG_SYS_DDR_BLOCK1_SIZE	((phys_size_t)2 << 30)
#define CFG_MAX_MEM_MAPPED		CFG_SYS_DDR_BLOCK1_SIZE

/* SEC */

/* DCFG - GUR */

#elif defined(CONFIG_FSL_LSCH2)
#define CFG_SYS_FSL_OCRAM_BASE		0x10000000 /* initial RAM */
#define SYS_FSL_OCRAM_SPACE_SIZE		0x00200000 /* 2M space */
#define CFG_SYS_FSL_OCRAM_SIZE		0x00020000 /* Real size 128K */

#define DCSR_DCFG_SBEESR2			0x20140534
#define DCSR_DCFG_MBEESR2			0x20140544

/* SoC related */
#ifdef CONFIG_ARCH_LS1043A
#define CFG_SYS_NUM_FMAN			1
#define CFG_SYS_NUM_FM1_DTSEC		7
#define CFG_SYS_NUM_FM1_10GEC		1
#define CFG_SYS_DDR_BLOCK1_SIZE		((phys_size_t)2 << 30)
#define CFG_MAX_MEM_MAPPED			CFG_SYS_DDR_BLOCK1_SIZE

#define QE_MURAM_SIZE		0x6000UL
#define MAX_QE_RISC		1
#define QE_NUM_OF_SNUM		28

/* SMMU Defintions */
#define SMMU_BASE		0x09000000

/* Generic Interrupt Controller Definitions */
#define GICD_BASE		0x01401000
#define GICC_BASE		0x01402000
#define GICH_BASE		0x01404000
#define GICV_BASE		0x01406000
#define GICD_SIZE		0x1000
#define GICC_SIZE		0x2000
#define GICH_SIZE		0x2000
#define GICV_SIZE		0x2000
#ifdef CONFIG_HAS_FEATURE_GIC64K_ALIGN
#define GICD_BASE_64K		0x01410000
#define GICC_BASE_64K		0x01420000
#define GICH_BASE_64K		0x01440000
#define GICV_BASE_64K		0x01460000
#define GICD_SIZE_64K		0x10000
#define GICC_SIZE_64K		0x20000
#define GICH_SIZE_64K		0x20000
#define GICV_SIZE_64K		0x20000
#endif

#define DCFG_CCSR_SVR		0x1ee00a4
#define REV1_0			0x10
#define REV1_1			0x11
#define GIC_ADDR_BIT		31
#define SCFG_GIC400_ALIGN	0x1570188

#elif defined(CONFIG_ARCH_LS1012A)
#define GICD_BASE		0x01401000
#define GICC_BASE		0x01402000
#define CFG_SYS_DDR_BLOCK1_SIZE	((phys_size_t)2 << 30)
#define CFG_MAX_MEM_MAPPED		CFG_SYS_DDR_BLOCK1_SIZE

#elif defined(CONFIG_ARCH_LS1046A)
#define CFG_SYS_NUM_FMAN			1
#define CFG_SYS_NUM_FM1_DTSEC		8
#define CFG_SYS_NUM_FM1_10GEC		2
#define CFG_SYS_DDR_BLOCK1_SIZE  ((phys_size_t)2 << 30)
#define CFG_MAX_MEM_MAPPED           CFG_SYS_DDR_BLOCK1_SIZE

/* SMMU Defintions */
#define SMMU_BASE		0x09000000

/* Generic Interrupt Controller Definitions */
#define GICD_BASE		0x01410000
#define GICC_BASE		0x01420000
#else
#error SoC not defined
#endif
#endif

#endif /* _ASM_ARMV8_FSL_LAYERSCAPE_CONFIG_H_ */
