// Verilog test fixture created from schematic D:\ISEpro\D_74LS138_SCH\D_74L138.sch - Sun Oct 13 18:28:44 2019

`timescale 1ns / 1ps

module D_74L138_D_74L138_sch_tb();

// Inputs
   reg G2A;
   reg G2B;
   reg G;
   reg C;
   reg B;
   reg A;

// Output
   wire [7:0] Y;

// Bidirs

// Instantiate the UUT
   D_74L138 UUT (
		.Y(Y), 
		.G2A(G2A), 
		.G2B(G2B), 
		.G(G), 
		.C(C), 
		.B(B), 
		.A(A)
   );
// Initialize Inputs
   //`ifdef auto_init
	integer i;
       initial begin
		C=0;
		B=0;
		A=0;
		
		G=1;
		G2A=0;
		G2B=0;
		#50;
		
		for(i=0;i<=7;i=i+1)begin
		{C,B,A}=i;
		#50;
		end
		assign G=0;
		assign G2A=0;
		assign G2B=0;
		#50;
		
		assign G=1;
		assign G2A=0;
		assign G2B=1;
		#50;
		end
   //`endif
endmodule
