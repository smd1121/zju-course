`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    
// Design Name: 
// Module Name:    ps2 
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
	module ps2(
				input clk,
				input rst,
				input ps2_clk,
				input ps2_data,
				output [9:0] data_out,
				output ready
    );

    reg ps2_clk_sign0, ps2_clk_sign1, ps2_clk_sign2, ps2_clk_sign3;
    wire negedge_ps2_clk;
	 
    always @ (posedge clk or posedge rst) begin
        if(rst) begin
            ps2_clk_sign0 <= 1'b0;
            ps2_clk_sign1 <= 1'b0;
            ps2_clk_sign2 <= 1'b0; 
            ps2_clk_sign3 <= 1'b0;
        end
        else begin
            ps2_clk_sign0 <= ps2_clk;
            ps2_clk_sign1 <= ps2_clk_sign0;
            ps2_clk_sign2 <= ps2_clk_sign1; 
            ps2_clk_sign3 <= ps2_clk_sign2;  
        end
    end

    assign negedge_ps2_clk = !ps2_clk_sign0 & !ps2_clk_sign1 & ps2_clk_sign2 & ps2_clk_sign3;
    reg [3:0] cnt;
    always @(posedge clk or posedge rst) begin
        if(rst)
            cnt <= 4'd0;
        else if(cnt == 4'd11)
            cnt <= 4'd0;
        else if(negedge_ps2_clk)
            cnt <= cnt + 1'b1;
    end

    reg negedge_ps2_clk_shift;
    always @ (posedge clk) begin
        negedge_ps2_clk_shift <= negedge_ps2_clk;
    end

    reg [7:0] data_in;
    always @ (posedge clk or posedge rst) begin
        if(rst)
            data_in <= 8'd0;
        else if(negedge_ps2_clk_shift) begin
            case(cnt)
                4'd2 : data_in[0] <= ps2_data;
                4'd3 : data_in[1] <= ps2_data;
                4'd4 : data_in[2] <= ps2_data;
                4'd5 : data_in[3] <= ps2_data;
                4'd6 : data_in[4] <= ps2_data;
                4'd7 : data_in[5] <= ps2_data;
                4'd8 : data_in[6] <= ps2_data;
                4'd9 : data_in[7] <= ps2_data;
                default : data_in <= data_in;
            endcase 
        end else
            data_in <= data_in;
    end

    reg key_break, key_done, key_expand;
    reg [9:0] data;
    always @ (posedge clk or posedge rst) begin
        if(rst) begin
            key_break <= 1'b0;
            data <= 10'd0;
            key_done <= 1'b0;
            key_expand <= 1'b0;
        end 
        else if(cnt == 4'd11) begin
            if(data_in == 8'hE0) begin
                key_expand <= 1'b1;
				key_break <= 1'b0;
			end
            else if(data_in == 8'hF0) begin
                key_break <= 1'b1;
				key_expand <= 1'b0;
			end
            else begin
                data <= {key_expand, key_break, data_in};
                key_done <= 1'b1;
                key_expand <= 1'b1;
                key_break <= 1'b0;
            end  
        end 
        else begin
            data <= data;
            key_done <= 1'b0;
            key_expand <= key_expand;
            key_break <= key_break;
        end
    end

    assign data_out = data;
    assign ready = key_done;

endmodule
