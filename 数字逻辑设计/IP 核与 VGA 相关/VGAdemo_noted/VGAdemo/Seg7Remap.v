`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:41:23 03/08/2016 
// Design Name: 
// Module Name:    Seg7Remap 
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
module Seg7Remap(
	input [31:0] I, output [31:0] O
);
	
	assign O[ 7: 0] = {I[24], I[12], I[5], I[17], I[25], I[16], I[4], I[0]};
	assign O[15: 8] = {I[26], I[13], I[7], I[19], I[27], I[18], I[6], I[1]};
	assign O[23:16] = {I[28], I[14], I[9], I[21], I[29], I[20], I[8], I[2]};
	assign O[31:24] = {I[30], I[15], I[11],I[23], I[31], I[22], I[10],I[3]};
	
endmodule
