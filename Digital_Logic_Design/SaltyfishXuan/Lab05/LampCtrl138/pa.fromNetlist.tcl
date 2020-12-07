
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name LampCtrl138 -dir "G:/Logic/SaltyfishXuan/LampCtrl138/planAhead_run_1" -part xc7k160tffg676-1
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "G:/Logic/SaltyfishXuan/LampCtrl138/LampCtrl138.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {G:/Logic/SaltyfishXuan/LampCtrl138} }
set_property target_constrs_file "k7.ucf" [current_fileset -constrset]
add_files [list {k7.ucf}] -fileset [get_property constrset [current_run]]
link_design
