`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:37:44 11/09/2020 
// Design Name: 
// Module Name:    CreateNumber 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module CreateNumber(
	input wire clk,
	input wire [3:0] btn,
	output reg [15:0] num
    );
	 
	 wire [3:0] A, B, C, D;
	 wire [3:0] temp_btn;
	 
	 initial num<=16'b0001001000110100;
	 
	 assign A = num[3:0] + 1'b1;
	 assign B = num[7:4] + 1'b1;
	 assign C = num[11:8] + 1'b1;
	 assign D = num[15:12] + 1'b1;
	 
	 pbdebounce p0(.clk_1ms(clk), .button(btn[0]), .pbreg(temp_btn[0]));
	 pbdebounce p1(.clk_1ms(clk), .button(btn[1]), .pbreg(temp_btn[1]));
	 pbdebounce p2(.clk_1ms(clk), .button(btn[2]), .pbreg(temp_btn[2]));
	 pbdebounce p3(.clk_1ms(clk), .button(btn[3]), .pbreg(temp_btn[3]));

	 always@(posedge temp_btn[0]) num[3:0]<=A;
	 always@(posedge temp_btn[1]) num[7:4]<=B;
	 always@(posedge temp_btn[2]) num[11:8]<=C;
	 always@(posedge temp_btn[3]) num[15:12]<=D;
	 
endmodule
