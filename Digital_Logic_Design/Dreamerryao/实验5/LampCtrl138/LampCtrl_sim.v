// Verilog test fixture created from schematic D:\ISEpro\LampCtrl138\LampCtrl.sch - Sun Oct 13 21:26:53 2019

`timescale 1ns / 1ps

module LampCtrl_LampCtrl_sch_tb();

// Inputs
   reg S2;
   reg S3;
   reg S1;

// Output
   wire F;

// Bidirs

// Instantiate the UUT
   LampCtrl UUT (
		.S2(S2), 
		.S3(S3), 
		.S1(S1), 
		.F(F)
   );
// Initialize Inputs
   //`ifdef auto_init
	integer i;
       initial begin
		 for(i=0;i<=8;i=i+1)begin
		 {S3,S2,S1}<=i;
		 #50;
		 end
	end
		
   //`endif
endmodule
