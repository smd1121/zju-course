`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:06:07 01/11/2021
// Design Name:   Top
// Module Name:   F:/_TOT_FILES/ZJU/A_1_Course/2_1/Digital_Logic_Design/project/bigProgram2020/VGAdemo/VGAdemo/vgaTest.v
// Project Name:  VGAdemo
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module vgaTest;

	// Inputs
	reg clk;
	reg rstn;
	reg [15:0] SW;

	// Outputs
	wire hs;
	wire vs;
	wire [3:0] r;
	wire [3:0] g;
	wire [3:0] b;

	// Bidirs
	wire [4:0] BTN_X;
	wire [3:0] BTN_Y;

	// Instantiate the Unit Under Test (UUT)
	Top uut (
		.clk(clk), 
		.rstn(rstn), 
		.SW(SW), 
		.hs(hs), 
		.vs(vs), 
		.r(r), 
		.g(g), 
		.b(b), 
		.BTN_X(BTN_X), 
		.BTN_Y(BTN_Y), 
		.debugX(debugX),
		.debugY(debugY),
		.debugIsFT(debugIsFT),
		.debugIx(debugIx),
		.debugIy(debugIy),
		.debugvgax(debugvgax),
		.debugvgay(debugvgay),
		.debuginTy(debuginTy),
		.debugxin(debugxin),
		.debugyin(debugyin)
	);

	initial begin
		SW = 1;
		fork clk = 0; #5;
			forever #5 clk <= ~clk;
		join
	end
      
endmodule

