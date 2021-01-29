`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:12:26 11/03/2016 
// Design Name: 
// Module Name:    Keypad 
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
module Keypad(
	input clk, inout [3:0] keyX, inout [4:0] keyY,
	output reg [4:0] keyCode, output ready, output [8:0] dbg_keyLine
);
	
	reg state = 1'b0;
	reg [3:0] keyLineX;
	reg [4:0] keyLineY;
	assign keyX = state? 4'h0: 4'bzzzz;
	assign keyY = state? 5'bzzzzz: 5'h0;
	
	always @ (posedge clk)
	begin
		if(state)
			keyLineY <= keyY;
		else
			keyLineX <= keyX;
		state <= ~state;
	end
	
	assign dbg_keyLine = ~{keyLineY, keyLineX};

	wire ready_raw1 = (keyLineX == 4'b1110) | (keyLineX == 4'b1101) | (keyLineX == 4'b1011) | (keyLineX == 4'b0111);
	wire ready_raw2 = (keyLineY == 5'b11110) | (keyLineY == 5'b11101) | (keyLineY == 5'b11011) | (keyLineY == 5'b10111) | (keyLineY == 5'b01111);
	wire ready_raw = ready_raw1 & ready_raw2;
	
	always @*
	begin
		case(keyLineX)
		4'b1110: keyCode[1:0] <= 2'h0;
		4'b1101: keyCode[1:0] <= 2'h1;
		4'b1011: keyCode[1:0] <= 2'h2;
		default: keyCode[1:0] <= 2'h3;
		endcase
		case(keyLineY)
		5'b11110: keyCode[4:2] <= 3'h0;
		5'b11101: keyCode[4:2] <= 3'h1;
		5'b11011: keyCode[4:2] <= 3'h2;
		5'b10111: keyCode[4:2] <= 3'h3;
		5'b01111: keyCode[4:2] <= 3'h4;
		default: keyCode[4:2] <= 3'h7;
		endcase
	end
	
	AntiJitter #(4) rdyFilter(.clk(clk), .I(ready_raw), .O(ready));
	
endmodule
