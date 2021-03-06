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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000003266574342_1222131070_init();
    work_m_00000000003266574342_1129804446_init();
    work_m_00000000002428017387_2532022638_init();
    work_m_00000000001662062654_1931955998_init();
    work_m_00000000002738371156_2002060500_init();
    work_m_00000000000197330456_0182372474_init();
    work_m_00000000001304455177_4283663877_init();
    work_m_00000000000339650694_1532905740_init();
    work_m_00000000000897832967_0619962294_init();
    work_m_00000000000544942185_2591206844_init();
    xilinxcorelib_ver_m_00000000001358910285_2975324287_init();
    xilinxcorelib_ver_m_00000000001687936702_0838807351_init();
    xilinxcorelib_ver_m_00000000000277421008_1937575457_init();
    xilinxcorelib_ver_m_00000000001603977570_0395169303_init();
    work_m_00000000000403262735_1516458078_init();
    xilinxcorelib_ver_m_00000000001358910285_4092804232_init();
    xilinxcorelib_ver_m_00000000001687936702_3947549588_init();
    xilinxcorelib_ver_m_00000000000277421008_2784666015_init();
    xilinxcorelib_ver_m_00000000001603977570_4041760848_init();
    work_m_00000000000403262735_3804412843_init();
    xilinxcorelib_ver_m_00000000000277421008_2878307789_init();
    xilinxcorelib_ver_m_00000000001603977570_1910117433_init();
    work_m_00000000000403262735_2039588255_init();
    xilinxcorelib_ver_m_00000000000277421008_1075716571_init();
    xilinxcorelib_ver_m_00000000001603977570_3344507644_init();
    work_m_00000000000403262735_0801262884_init();
    work_m_00000000001304455177_3383072609_init();
    work_m_00000000003364938197_3376253697_init();
    work_m_00000000000177344818_2872392499_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000000177344818_2872392499");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
