`timescale 1ns / 1ps

module Top(
	input clk,
	input rstn,
	input [15:0]SW,
	output hs,
	output vs,
	output [3:0] r,
	output [3:0] g,
	output [3:0] b,
	output SEGLED_CLK,
	output SEGLED_CLR,
	output SEGLED_DO,
	output SEGLED_PEN,
  output LED_CLK,
	output LED_CLR,
	output LED_DO,
	output LED_PEN,
	inout [4:0]BTN_X,
	inout [3:0]BTN_Y,
	output buzzer
    );
	
	// ÿ�� clk �δ�clkdiv++
	reg [31:0]clkdiv;
	always@(posedge clk) begin
		clkdiv <= clkdiv + 1'b1;
	end
	
	// �����������ﲢû��ʹ��
	assign buzzer = 1'b1;
	
	// SW_OK �Ƿ�������Ŀ��أ��������ù�
	wire [15:0] SW_OK;
	// #(4) �Ǹ�����ĳ�����ֵ
	AntiJitter #(4) a0[15:0](.clk(clkdiv[15]), .I(SW), .O(SW_OK));
	
	// ���������룺
	// keyCode �ǰ����ı�ţ��������Ϊ��
	// 0 1 2 3
	// 4 5 6 7
	// ...
	// keyReady Ϊ 1�����а�ť������
	// �������ù�
	// ���ұ�һ�в����˴���
	wire [4:0] keyCode;
	wire keyReady;
	Keypad k0 (.clk(clkdiv[15]), .keyX(BTN_Y), .keyY(BTN_X), .keyCode(keyCode), .ready(keyReady));
	
	// �����߶��������ʾ��
	// segTestData �� 8*4 λҪ��ʾ������
	// �������ù�
	wire [31:0] segTestData;
	wire [3:0] sout;
   Seg7Device segDevice(.clkIO(clkdiv[3]), .clkScan(clkdiv[15:14]), .clkBlink(clkdiv[25]),
		.data(segTestData), .point(8'h0), .LES(8'h0), .sout(sout));
	assign SEGLED_CLK = sout[3];
	assign SEGLED_DO = sout[2];
	assign SEGLED_PEN = sout[1];
	assign SEGLED_CLR = sout[0];
 	
	// VGA �� 640*480 �ģ��ֱ��� 10 λ�� 9 λ��ʾ����λ��
	reg [9:0] x;
	reg [8:0] y;
	
	// ���� VGA �����
	// input clrn: ~clear, if it's 0 then clear
	// input vga_data: bbbb_gggg_rrrr
	// output row_addr & col_addr: ��Ҫ���� vga_data ����������
 	reg [11:0] vga_data;
 	wire [9:0] col_addr;
 	wire [8:0] row_addr;
	vgac v0 (
		.vga_clk(clkdiv[1]), .clrn(SW_OK[0]), .d_in(vga_data), .row_addr(row_addr), 
		.col_addr(col_addr), .r(r), .g(g), .b(b), .hs(hs), .vs(vs)
	);
	
	wire [19:0] x_sqr, y_sqr, r_sqr;
	reg wasReady;
	// ��ʼ�� radius = 15
	reg [9:0] radius = 10'd15;
	always @(posedge clk) begin
		// rstn �� top �����룬���������������Ǹ�
		// ��������£����� x, y, radius
		// �ƺ���ʼʱ�� rstn �źţ�
		if (!rstn) begin
			x <= 10'd320;
			y <= 9'd240;
			radius <= 10'd15;
		end else begin
			// ����һ��ʱ���ź�ʱ��ťδ�����������ڱ�������
			// ���ǳ��������
			wasReady <= keyReady;
			if (!wasReady&&keyReady) begin
				case (keyCode)
					5'h10: radius <= radius - 10'd5;
					5'h12: radius <= radius + 10'd5;
					5'hc: x <= x - 10'd20;
					5'he: x <= x + 10'd20;
					5'h9: y <= y - 9'd20;
					5'h11: y <= y + 9'd20;
					default: ;
				endcase
			end
		end
	end
	
	assign x_sqr = (x - col_addr) * (x - col_addr);
	assign y_sqr = (y - row_addr) * (y - row_addr);
	assign r_sqr = radius * radius;
	
	always@(*) begin
		// �����ǰλ����Բ�ڣ��� SW[12:1] ��Ϊ��ɫ��� vga_data
		// ����Բ��ʾΪ SW[12:1] ��Ӧ����ɫ
		if ((x_sqr + y_sqr < r_sqr))
			vga_data <= SW[12:1];
		// ������ʾ��ɫ
		else vga_data <= 12'hfff;
	end
	
	// �� segTestData ��Ϊ 0000_000x_xxxx_xxxx_0000_0000_yyyy_yyyy
	// ����ʾ�� 7 ���������
	assign segTestData = {7'b0,x,8'b0,y};
	
	// ���� LED �����
	// ledData �� 16 ���Ƶ���ʾ����
	// �������ù�
	wire [15:0] ledData;
	// ����� SW_OK ������ ledData������ʾ�������
	assign ledData = SW_OK;
	ShiftReg #(.WIDTH(16)) ledDevice (.clk(clkdiv[3]), .pdata(~ledData), 
												 .sout({LED_CLK,LED_DO,LED_PEN,LED_CLR}));
endmodule
