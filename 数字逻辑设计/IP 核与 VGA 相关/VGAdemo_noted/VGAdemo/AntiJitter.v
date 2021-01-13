`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:00:03 12/10/2015 
// Design Name: 
// Module Name:    AntiJitter 
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
module AntiJitter(
	input clk, input I, output reg O
);
	parameter WIDTH = 20;
	reg [WIDTH-1:0] cnt = 0;

	always @ (posedge clk)
	begin
		if(I)
		begin
			if(&cnt)
				O <= 1'b1;
			else
				cnt <= cnt + 1'b1;
		end
		else
		begin
			if(|cnt)
				cnt <= cnt - 1'b1;
			else
				O <= 1'b0;
		end
	end

endmodule
