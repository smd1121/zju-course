`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07/05/2016 12:26:15 AM
// Design Name: 
// Module Name: Seg7Device
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
module Seg7Device(
	input clkIO, input [1:0] clkScan, input clkBlink,
	input [31:0] data, input [7:0] point, input [7:0] LES,
	output [3:0] sout, output reg [7:0] segment, output reg [3:0] anode
);
	wire [63:0] dispData;
	wire [31:0] dispPattern;
	
	Seg7Decode U0(.hex(data), .point(point),
		.LE(LES & {8{clkBlink}}), .pattern(dispData));
	Seg7Remap U1(.I(data), .O(dispPattern));

	ShiftReg #(.WIDTH(64)) U2(.clk(clkIO), .pdata(dispData), .sout(sout));

	always @*
		case(clkScan)
		2'b00: begin segment <= ~dispPattern[ 7: 0]; anode <= 4'b1110; end
		2'b01: begin segment <= ~dispPattern[15: 8]; anode <= 4'b1101; end
		2'b10: begin segment <= ~dispPattern[23:16]; anode <= 4'b1011; end
		2'b11: begin segment <= ~dispPattern[31:24]; anode <= 4'b0111; end
		endcase
	
	
endmodule
