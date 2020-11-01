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
    unisims_ver_m_00000000003149700083_3274606718_init();
    unisims_ver_m_00000000003510477262_2316096324_init();
    unisims_ver_m_00000000002549801008_1565138397_init();
    unisims_ver_m_00000000000236260522_2449448540_init();
    unisims_ver_m_00000000001162476414_3090295908_init();
    work_m_00000000001887935892_3463696931_init();
    unisims_ver_m_00000000003317509437_1759035934_init();
    unisims_ver_m_00000000003927721830_1593237687_init();
    work_m_00000000001645318227_1325037141_init();
    work_m_00000000001750157387_3192566426_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000001750157387_3192566426");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
