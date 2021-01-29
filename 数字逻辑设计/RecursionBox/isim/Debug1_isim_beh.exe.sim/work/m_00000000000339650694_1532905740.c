/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "F:/_TOT_FILES/ZJU/A_1_Course/2_1/Digital_Logic_Design/project/RecursionBox/RecursionBox/Seg7Device.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {14U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {13U, 0U};
static unsigned int ng5[] = {2U, 0U};
static unsigned int ng6[] = {11U, 0U};
static unsigned int ng7[] = {3U, 0U};
static unsigned int ng8[] = {7U, 0U};
static int ng9[] = {8, 0};



static void Always_35_0(char *t0)
{
    char t7[8];
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;

LAB0:    t1 = (t0 + 3968U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 4536);
    *((int *)t2) = 1;
    t3 = (t0 + 4000);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(36, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);

LAB5:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t4, 2);
    if (t6 == 1)
        goto LAB6;

LAB7:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB8;

LAB9:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB10;

LAB11:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB12;

LAB13:
LAB14:    goto LAB2;

LAB6:    xsi_set_current_line(37, ng0);

LAB15:    xsi_set_current_line(37, ng0);
    t9 = (t0 + 2328U);
    t10 = *((char **)t9);
    memset(t8, 0, 8);
    t9 = (t8 + 4);
    t11 = (t10 + 4);
    t12 = *((unsigned int *)t10);
    t13 = (t12 >> 0);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t11);
    t15 = (t14 >> 0);
    *((unsigned int *)t9) = t15;
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 255U);
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 255U);
    memset(t7, 0, 8);
    t18 = (t7 + 4);
    t19 = (t8 + 4);
    t20 = *((unsigned int *)t8);
    t21 = (~(t20));
    *((unsigned int *)t7) = t21;
    *((unsigned int *)t18) = 0;
    if (*((unsigned int *)t19) != 0)
        goto LAB17;

LAB16:    t26 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t26 & 255U);
    t27 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t27 & 255U);
    t28 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t28, t7, 0, 0, 8, 0LL);
    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    goto LAB14;

LAB8:    xsi_set_current_line(38, ng0);

LAB18:    xsi_set_current_line(38, ng0);
    t3 = (t0 + 2328U);
    t4 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t8 + 4);
    t9 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 8);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t9);
    t15 = (t14 >> 8);
    *((unsigned int *)t3) = t15;
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 255U);
    t17 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t17 & 255U);
    memset(t7, 0, 8);
    t10 = (t7 + 4);
    t11 = (t8 + 4);
    t20 = *((unsigned int *)t8);
    t21 = (~(t20));
    *((unsigned int *)t7) = t21;
    *((unsigned int *)t10) = 0;
    if (*((unsigned int *)t11) != 0)
        goto LAB20;

LAB19:    t26 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t26 & 255U);
    t27 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t27 & 255U);
    t18 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t18, t7, 0, 0, 8, 0LL);
    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    goto LAB14;

LAB10:    xsi_set_current_line(39, ng0);

LAB21:    xsi_set_current_line(39, ng0);
    t3 = (t0 + 2328U);
    t4 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t8 + 4);
    t9 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 16);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t9);
    t15 = (t14 >> 16);
    *((unsigned int *)t3) = t15;
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 255U);
    t17 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t17 & 255U);
    memset(t7, 0, 8);
    t10 = (t7 + 4);
    t11 = (t8 + 4);
    t20 = *((unsigned int *)t8);
    t21 = (~(t20));
    *((unsigned int *)t7) = t21;
    *((unsigned int *)t10) = 0;
    if (*((unsigned int *)t11) != 0)
        goto LAB23;

LAB22:    t26 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t26 & 255U);
    t27 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t27 & 255U);
    t18 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t18, t7, 0, 0, 8, 0LL);
    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    goto LAB14;

LAB12:    xsi_set_current_line(40, ng0);

LAB24:    xsi_set_current_line(40, ng0);
    t3 = (t0 + 2328U);
    t4 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t8 + 4);
    t9 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 24);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t9);
    t15 = (t14 >> 24);
    *((unsigned int *)t3) = t15;
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 255U);
    t17 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t17 & 255U);
    memset(t7, 0, 8);
    t10 = (t7 + 4);
    t11 = (t8 + 4);
    t20 = *((unsigned int *)t8);
    t21 = (~(t20));
    *((unsigned int *)t7) = t21;
    *((unsigned int *)t10) = 0;
    if (*((unsigned int *)t11) != 0)
        goto LAB26;

LAB25:    t26 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t26 & 255U);
    t27 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t27 & 255U);
    t18 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t18, t7, 0, 0, 8, 0LL);
    xsi_set_current_line(40, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    goto LAB14;

LAB17:    t22 = *((unsigned int *)t7);
    t23 = *((unsigned int *)t19);
    *((unsigned int *)t7) = (t22 | t23);
    t24 = *((unsigned int *)t18);
    t25 = *((unsigned int *)t19);
    *((unsigned int *)t18) = (t24 | t25);
    goto LAB16;

LAB20:    t22 = *((unsigned int *)t7);
    t23 = *((unsigned int *)t11);
    *((unsigned int *)t7) = (t22 | t23);
    t24 = *((unsigned int *)t10);
    t25 = *((unsigned int *)t11);
    *((unsigned int *)t10) = (t24 | t25);
    goto LAB19;

LAB23:    t22 = *((unsigned int *)t7);
    t23 = *((unsigned int *)t11);
    *((unsigned int *)t7) = (t22 | t23);
    t24 = *((unsigned int *)t10);
    t25 = *((unsigned int *)t11);
    *((unsigned int *)t10) = (t24 | t25);
    goto LAB22;

LAB26:    t22 = *((unsigned int *)t7);
    t23 = *((unsigned int *)t11);
    *((unsigned int *)t7) = (t22 | t23);
    t24 = *((unsigned int *)t10);
    t25 = *((unsigned int *)t11);
    *((unsigned int *)t10) = (t24 | t25);
    goto LAB25;

}

static void implSig1_execute(char *t0)
{
    char t4[8];
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    int t30;
    int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;

LAB0:    t1 = (t0 + 4216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng9)));
    t5 = (t0 + 1368U);
    t6 = *((char **)t5);
    xsi_vlog_mul_concat(t4, 8, 1, t2, 1U, t6, 1);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t4);
    t10 = (t8 & t9);
    *((unsigned int *)t7) = t10;
    t5 = (t3 + 4);
    t11 = (t4 + 4);
    t12 = (t7 + 4);
    t13 = *((unsigned int *)t5);
    t14 = *((unsigned int *)t11);
    t15 = (t13 | t14);
    *((unsigned int *)t12) = t15;
    t16 = *((unsigned int *)t12);
    t17 = (t16 != 0);
    if (t17 == 1)
        goto LAB4;

LAB5:
LAB6:    t38 = (t0 + 4632);
    t39 = (t38 + 56U);
    t40 = *((char **)t39);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    memset(t42, 0, 8);
    t43 = 255U;
    t44 = t43;
    t45 = (t7 + 4);
    t46 = *((unsigned int *)t7);
    t43 = (t43 & t46);
    t47 = *((unsigned int *)t45);
    t44 = (t44 & t47);
    t48 = (t42 + 4);
    t49 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t49 | t43);
    t50 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t50 | t44);
    xsi_driver_vfirst_trans(t38, 0, 7);
    t51 = (t0 + 4552);
    *((int *)t51) = 1;

LAB1:    return;
LAB4:    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t12);
    *((unsigned int *)t7) = (t18 | t19);
    t20 = (t3 + 4);
    t21 = (t4 + 4);
    t22 = *((unsigned int *)t3);
    t23 = (~(t22));
    t24 = *((unsigned int *)t20);
    t25 = (~(t24));
    t26 = *((unsigned int *)t4);
    t27 = (~(t26));
    t28 = *((unsigned int *)t21);
    t29 = (~(t28));
    t30 = (t23 & t25);
    t31 = (t27 & t29);
    t32 = (~(t30));
    t33 = (~(t31));
    t34 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t34 & t32);
    t35 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t35 & t33);
    t36 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t36 & t32);
    t37 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t37 & t33);
    goto LAB6;

}


extern void work_m_00000000000339650694_1532905740_init()
{
	static char *pe[] = {(void *)Always_35_0,(void *)implSig1_execute};
	xsi_register_didat("work_m_00000000000339650694_1532905740", "isim/Debug1_isim_beh.exe.sim/work/m_00000000000339650694_1532905740.didat");
	xsi_register_executes(pe);
}
