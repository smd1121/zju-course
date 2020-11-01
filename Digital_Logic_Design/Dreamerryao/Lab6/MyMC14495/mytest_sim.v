// Verilog test fixture created from schematic D:\ISEpro\MyMC14495\MyMC14495.sch - Thu Oct 17 23:09:12 2019

`timescale 1ns / 1ps

module MyMC14495_MyMC14495_sch_tb();

// Inputs
   reg point;
   reg LE;
   reg D3;
   reg D2;
   reg D1;
   reg D0;

// Output
   wire p;
   wire a;
   wire b;
   wire c;
   wire d;
   wire e;
   wire f;
   wire g;

// Bidirs

// Instantiate the UUT
   MyMC14495 UUT (
		.point(point), 
		.p(p), 
		.LE(LE), 
		.a(a), 
		.b(b), 
		.c(c), 
		.d(d), 
		.e(e), 
		.f(f), 
		.g(g), 
		.D3(D3), 
		.D2(D2), 
		.D1(D1), 
		.D0(D0)
   );
// Initialize Inputs
   //`ifdef auto_init
	integer i;
       initial begin
		point = 0;
		LE = 0;
		D3 = 0;
		D2 = 0;
		D1 = 0;
		D0 = 0;
		for(i=0;i<=15;i=i+1)begin
		#50;
		{D3,D2,D1,D0}=i;
		point=i;
		end
		
		#50;
		LE=1;
		end
   //`endif
endmodule
