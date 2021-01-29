`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:37:46 01/11/2021
// Design Name:   Top
// Module Name:   F:/_TOT_FILES/ZJU/A_1_Course/2_1/Digital_Logic_Design/project/bigProgram2020/VGAdemo/VGAdemo/Debug1.v
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

module Debug1;

	// Inputs
	reg clk;
	reg rstn;
	reg [15:0] SW;

	// Outputs
	wire [3:0] debugX;
	wire [3:0] debugY;
	wire debugIsFT;
	wire [3:0] debugIx;
	wire [3:0] debugIy;
	wire [9:0] debugvgax;
	wire [8:0] debugvgay;
	wire [3:0] debuginTy;
	wire [2:0] debugxin;
	wire [2:0] debugyin;
	wire hs;
	wire vs;
	wire [3:0] r;
	wire [3:0] g;
	wire [3:0] b;
	wire SEGLED_CLK;
	wire SEGLED_CLR;
	wire SEGLED_DO;
	wire SEGLED_PEN;
	wire LED_CLK;
	wire LED_CLR;
	wire LED_DO;
	wire LED_PEN;
	wire buzzer;

	// Bidirs
	wire [4:0] BTN_X;
	wire [3:0] BTN_Y;

	// Instantiate the Unit Under Test (UUT)
	Top uut (
		.debugX(debugX), 
		.debugY(debugY), 
		.debugIsFT(debugIsFT), 
		.debugIx(debugIx), 
		.debugIy(debugIy), 
		.debugaddr(debugaddr),
		.debugvgax(debugvgax), 
		.debugvgay(debugvgay), 
		.debugvgad(debugvgad),
		.debuginTy(debuginTy), 
		.debugxin(debugxin), 
		.debugyin(debugyin), 
		.clk(clk), 
		.rstn(rstn), 
		.SW(SW), 
		.hs(hs), 
		.vs(vs), 
		.r(r), 
		.g(g), 
		.b(b), 
		.SEGLED_CLK(SEGLED_CLK), 
		.SEGLED_CLR(SEGLED_CLR), 
		.SEGLED_DO(SEGLED_DO), 
		.SEGLED_PEN(SEGLED_PEN), 
		.LED_CLK(LED_CLK), 
		.LED_CLR(LED_CLR), 
		.LED_DO(LED_DO), 
		.LED_PEN(LED_PEN), 
		.BTN_X(BTN_X), 
		.BTN_Y(BTN_Y), 
		.buzzer(buzzer)
	);

	initial begin
		SW = 1;
		rstn = 1;
		fork clk = 0; #0.5;
			forever #0.5 clk <= ~clk;
		join
	end
      
endmodule

