`timescale 1ns / 1ps

module Top(
	/*output [3:0] debugX,
	output [3:0] debugY,
	output debugIsFT,
	output [3:0] debugIx,
	output [3:0] debugIy,
	output [9:0] debugaddr,
	output [9:0] debugvgax,
	output [8:0] debugvgay,
	output [11:0] debugvgad,
	output [3:0] debuginTy,
	output [2:0] debugxin,
	output [2:0] debugyin,*/
	input clk,
	input ps2_clk,
	input ps2_data,
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
	/*assign debugX = x;
	assign debugY = y;
	assign debugIsFT = countDown[0]; //isFirstTime;
	assign debugIx = xi;
	assign debugIy = yi;
	assign debugaddr = addr;
	assign debugvgax = col_addr;
	assign debugvgay = row_addr;
	assign debugvgad = vga_data;
	assign debuginTy = countDown; //innerTyOut;
	assign debugxin = x_inner_off;
	assign debugyin = y_inner_off;*/
	
	// ÿ�� clk �δ�clkdiv++
	reg [31:0]clkdiv;
	always@(posedge clk) begin
		clkdiv <= clkdiv + 1'b1;
	end
	
	// ��������
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
	
	// ���� VGA �����
	// input clrn: ~clear, if it's 0 then clear, Ҳ������Ҫ SW[0] Ϊ 1
	// input vga_data: bbbb_gggg_rrrr
	// output row_addr & col_addr: ��Ҫ���� vga_data ����������
	// �������ù�
 	reg [11:0] vga_data;
 	wire [9:0] col_addr;
 	wire [8:0] row_addr;
	vgac v0 (
		.vga_clk(clkdiv[1]), .clrn(SW_OK[0]), .d_in(vga_data), .row_addr(row_addr), 
		.col_addr(col_addr), .r(r), .g(g), .b(b), .hs(hs), .vs(vs)
	);
	
	wire [9:0] keyb;
	wire keybR;
	ps2 k1 (.clk(clk), .rst((~rstn)), .ps2_clk(ps2_clk), .ps2_data(ps2_data), .data_out(keyb), .ready(keybR));
	
	// �ؿ���ż���һ��ʱ��ʱ�Ĺؿ����
	reg [2:0] lastTimeLevel = 7;
	wire [2:0] level;
	assign level = SW[15:13];
	
	// ���ӡ����Ӽ����ϴ������������� (1~9)����ͼ��֤ 9*9
	// * - bean, b - box, l - last
	reg [3:0] x, y, bx, by, lx, ly, lbx, lby;
	// �������� LevelRef ���� 1 ������ʾ�ܹؿ�����12 ������ʾ�ؿ����ã�ÿ���ؿ��� 133 �������
	parameter OriOffset = 1, LevelOffset = 12, WholeLevel = 133;
	// �ϴ��ƶ��ķ��� 0~3: left, right, up, down
	reg [1:0] lastDir = 2;
	// �Ƿ��Ѿ����Ŀ��
	wire isBean, isBox;
	assign isBean = (x == xd && y == yd) ? 1 : 0;
	assign isBox = (bx == bxd && by == byd) ? 1 : 0;
	
	// �����������ҵĸ������� 0~4
	wire [3:0] left, right, up, down;
	wire [9:0] addr;
	assign addr = 1 + LevelOffset + WholeLevel * level + x + y * 11;
	LevelRef leftRef(.clka(clk), .addra(addr - 1), .douta(left));
	LevelRef rightRef(.clka(clk), .addra(addr + 1), .douta(right));
	LevelRef upRef(.clka(clk), .addra(addr - 11), .douta(up));
	LevelRef downRef(.clka(clk), .addra(addr + 11), .douta(down));
	
	// �����������ҵĸ������� 0~4
	// b - box
	wire [3:0] bleft, bright, bup, bdown;
	wire [9:0] baddr;
	assign baddr = 1 + LevelOffset + WholeLevel * level + bx + by * 11;
	LevelRef bleftRef(.clka(clk), .addra(baddr - 1), .douta(bleft));
	LevelRef brightRef(.clka(clk), .addra(baddr + 1), .douta(bright));
	LevelRef bupRef(.clka(clk), .addra(baddr - 11), .douta(bup));
	LevelRef bdownRef(.clka(clk), .addra(baddr + 11), .douta(bdown));
	
	// ÿ�صĹؿ���Ϣ����ʼ��Ŀ��λ���Լ��ĸ��������ڣ�û����Ϊ 0
	// i - init, d - dest, b - box, loopi - ����ѭ����ȡ
	// li, ri, ui, di - left, right, up, down in
	wire [3:0] xi, yi, bxi, byi, xd, yd, bxd, byd, li, ri, ui, di;
	wire [9:0] initaddr;
	assign initaddr = 1 + WholeLevel * level;
	LevelRef initXi(.clka(clk), .addra(initaddr + 0), .douta(xi));
	LevelRef initYi(.clka(clk), .addra(initaddr + 1), .douta(yi));
	LevelRef initBxi(.clka(clk), .addra(initaddr + 2), .douta(bxi));
	LevelRef initByi(.clka(clk), .addra(initaddr + 3), .douta(byi));
	LevelRef initXd(.clka(clk), .addra(initaddr + 4), .douta(xd));
	LevelRef initYd(.clka(clk), .addra(initaddr + 5), .douta(yd));
	LevelRef initBxd(.clka(clk), .addra(initaddr + 6), .douta(bxd));
	LevelRef initByd(.clka(clk), .addra(initaddr + 7), .douta(byd));
	LevelRef initLi(.clka(clk), .addra(initaddr + 8), .douta(li));
	LevelRef initRi(.clka(clk), .addra(initaddr + 9), .douta(ri));
	LevelRef initUi(.clka(clk), .addra(initaddr + 10), .douta(ui));
	LevelRef initDI(.clka(clk), .addra(initaddr + 11), .douta(di));
	
	// �ȴ�����֤��ȷ����ֵ
	reg isWait = 0, wasWait = 0;
	reg [3:0] countDown = 4'b0111;
	always @(posedge clk) begin
		if (!wasWait && isWait)
			countDown = 4'b0111;
		if (isWait)
			countDown = countDown - 1;
		else
			countDown = 4'b0111;
		wasWait = isWait;
	end
	
	// �����ƶ�
	reg isFirstTime = 1;
	// ��һ��ʱ���ź�ʱ�ǲ��ǰ����˰�ť
	reg wasReady, wasKbReady;
	always @(posedge clk) begin
		// rstn �� top �����룬���������������Ǹ�
		// ��������£��������мĴ���
		if (isFirstTime || !rstn || level != lastTimeLevel) begin
			isWait = 1;
			if (countDown == 0) begin
				lastDir <= 2;
				isFirstTime = 0;
				lx = xi; ly = yi; lbx = bxi; lby = byi;
				x <= xi; y <= yi; bx <= bxi; by <= byi;
				lastTimeLevel <= level;
				isWait = 0;
			end
		end else begin
			// ����һ��ʱ���ź�ʱ��ťδ�����������ڱ�������
			// ���ǳ��������
			wasReady <= keyReady;
			if (!wasReady&&keyReady) begin
				case (keyCode)
					// ����
					5'h10: begin
						x <= lx; y <= ly; bx <= lbx; by <= lby;
					end
					
					// left
					5'hc: begin
						lastDir <= 0;
						if (x == bx + 1 && y == by) begin	// ������������
							case (bleft)
								1, 3, 4: begin		// �����������ǿգ��ƶ����Ӻ�����
									lx = x; ly = y; lbx = bx; lby = by;
									x <= x - 1; bx <= bx - 1;
								end
								0: begin				//	������������ǽ...
										if (ri != 0) begin	// �����ұ�����ڣ���������
											lx = x; ly = y; lbx = bx; lby = by;
											y <= ri; x <= 9;
										end
									end
								2: ;					// ��������ǵݹ���ڣ���ͼ��֤û�д����
							endcase							
						end // end of if
						else case (left)
							1, 3, 4: begin			// ������Ϊ�գ��ƶ� x ������ lx
								lx = x; ly = y; lbx = bx; lby = by;
								x <= x - 1;
							end
							0: ;				// ��������ǽ��ʲô������
							2: begin			// �������ǵݹ����...
								case (bleft)
									1, 3, 4: begin		// �����������ǿգ��ƶ����ӵ��������
										lx = x; ly = y; lbx = bx; lby = by;
										x <= bx - 1; y <= by;
									end
									0: ;			// ��������ǽ��ʲô������
									2: ;			// ��������ǵݹ���ڣ���ͼ��֤û�д����
									default: ;
								endcase
							end // end of 2:
							default: ;
						endcase	
					end
					
					// right
					5'he: begin
						lastDir <= 1;
						if (x == bx - 1 && y == by) begin
							case (bright)
								1, 3, 4: begin	
									lx = x; ly = y; lbx = bx; lby = by;
									x <= x + 1; bx <= bx + 1;
								end
								0: begin
									if (li != 0) begin
										lx = x; ly = y; lbx = bx; lby = by;
										y <= li; x <= 1;
									end
								end
								2: ;
							endcase							
						end // end of if
						else case (right)
							1, 3, 4: begin
								lx = x; ly = y; lbx = bx; lby = by;
								x <= x + 1;
							end
							0: ;
							2: begin	
								case (bright)
									1, 3, 4: begin	
										lx = x; ly = y; lbx = bx; lby = by;
										x <= bx + 1; y <= by;
									end
									0: ;
									2: ;
									default: ;
								endcase
							end // end of 2:
							default: ;
						endcase	
					end
					
					// up
					5'h9: begin
						lastDir <= 2;
						if (x == bx && y == by + 1) begin
							case (bup)
								1, 3, 4: begin	
									lx = x; ly = y; lbx = bx; lby = by;
									y <= y - 1; by <= by - 1;
								end
								0: begin
									if (di != 0) begin
										lx = x; ly = y; lbx = bx; lby = by;
										y <= 9; x <= di;
									end
								end
								2: ;
							endcase							
						end // end of if
						else case (up)
							1, 3, 4: begin
								lx = x; ly = y; lbx = bx; lby = by;
								y <= y - 1;
							end
							0: ;
							2: begin	
								case (bup)
									1, 3, 4: begin	
										lx = x; ly = y; lbx = bx; lby = by;
										x <= bx; y <= by - 1;
									end
									0: ;
									2: ;
									default: ;
								endcase
							end // end of 2:
							default: ;
						endcase	
					end
					
					// down
					5'h11: begin
						lastDir <= 3;
						if (x == bx && y == by - 1) begin
							case (bup)
								1, 3, 4: begin	
									lx = x; ly = y; lbx = bx; lby = by;
									y <= y + 1; by <= by + 1;
								end
								0: begin
									if (ui != 0) begin
										lx = x; ly = y; lbx = bx; lby = by;
										y <= 1; x <= ui;
									end
								end
								2: ;
							endcase							
						end // end of if
						else case (down)
							1, 3, 4: begin
								lx = x; ly = y; lbx = bx; lby = by;
								y <= y + 1;
							end
							0: ;
							2: begin	
								case (bdown)
									1, 3, 4: begin	
										lx = x; ly = y; lbx = bx; lby = by;
										x <= bx; y <= by + 1;
									end
									0: ;
									2: ;
									default: ;
								endcase
							end // end of 2:
							default: ;
						endcase	
					end
					
					default: ;
				endcase
			end	// end of if
			
			//wasKbReady <= keybR;
			//if (!wasKbReady && keybR) begin
			if (keyb[9] && keybR) begin
				case (keyb[7:0])
					// ���� - R
					8'h2D: begin
						x <= lx; y <= ly; bx <= lbx; by <= lby;
					end
					
					// left - A
					8'h1c: begin
						lastDir <= 0;
						if (x == bx + 1 && y == by) begin	// ������������
							case (bleft)
								1, 3, 4: begin		// �����������ǿգ��ƶ����Ӻ�����
									lx = x; ly = y; lbx = bx; lby = by;
									x <= x - 1; bx <= bx - 1;
								end
								0: begin				//	������������ǽ...
										if (ri != 0) begin	// �����ұ�����ڣ���������
											lx = x; ly = y; lbx = bx; lby = by;
											y <= ri; x <= 9;
										end
									end
								2: ;					// ��������ǵݹ���ڣ���ͼ��֤û�д����
							endcase							
						end // end of if
						else case (left)
							1, 3, 4: begin			// ������Ϊ�գ��ƶ� x ������ lx
								lx = x; ly = y; lbx = bx; lby = by;
								x <= x - 1;
							end
							0: ;				// ��������ǽ��ʲô������
							2: begin			// �������ǵݹ����...
								case (bleft)
									1, 3, 4: begin		// �����������ǿգ��ƶ����ӵ��������
										lx = x; ly = y; lbx = bx; lby = by;
										x <= bx - 1; y <= by;
									end
									0: ;			// ��������ǽ��ʲô������
									2: ;			// ��������ǵݹ���ڣ���ͼ��֤û�д����
									default: ;
								endcase
							end // end of 2:
							default: ;
						endcase	
					end
					
					// right - D
					8'h23: begin
						lastDir <= 1;
						if (x == bx - 1 && y == by) begin
							case (bright)
								1, 3, 4: begin	
									lx = x; ly = y; lbx = bx; lby = by;
									x <= x + 1; bx <= bx + 1;
								end
								0: begin
									if (li != 0) begin
										lx = x; ly = y; lbx = bx; lby = by;
										y <= li; x <= 1;
									end
								end
								2: ;
							endcase							
						end // end of if
						else case (right)
							1, 3, 4: begin
								lx = x; ly = y; lbx = bx; lby = by;
								x <= x + 1;
							end
							0: ;
							2: begin	
								case (bright)
									1, 3, 4: begin	
										lx = x; ly = y; lbx = bx; lby = by;
										x <= bx + 1; y <= by;
									end
									0: ;
									2: ;
									default: ;
								endcase
							end // end of 2:
							default: ;
						endcase	
					end
					
					// up - W
					8'h1d: begin
						lastDir <= 2;
						if (x == bx && y == by + 1) begin
							case (bup)
								1, 3, 4: begin	
									lx = x; ly = y; lbx = bx; lby = by;
									y <= y - 1; by <= by - 1;
								end
								0: begin
									if (di != 0) begin
										lx = x; ly = y; lbx = bx; lby = by;
										y <= 9; x <= di;
									end
								end
								2: ;
							endcase							
						end // end of if
						else case (up)
							1, 3, 4: begin
								lx = x; ly = y; lbx = bx; lby = by;
								y <= y - 1;
							end
							0: ;
							2: begin	
								case (bup)
									1, 3, 4: begin	
										lx = x; ly = y; lbx = bx; lby = by;
										x <= bx; y <= by - 1;
									end
									0: ;
									2: ;
									default: ;
								endcase
							end // end of 2:
							default: ;
						endcase	
					end
					
					// down - W
					8'h1B: begin
						lastDir <= 3;
						if (x == bx && y == by - 1) begin
							case (bup)
								1, 3, 4: begin	
									lx = x; ly = y; lbx = bx; lby = by;
									y <= y + 1; by <= by + 1;
								end
								0: begin
									if (ui != 0) begin
										lx = x; ly = y; lbx = bx; lby = by;
										y <= 1; x <= ui;
									end
								end
								2: ;
							endcase							
						end // end of if
						else case (down)
							1, 3, 4: begin
								lx = x; ly = y; lbx = bx; lby = by;
								y <= y + 1;
							end
							0: ;
							2: begin	
								case (bdown)
									1, 3, 4: begin	
										lx = x; ly = y; lbx = bx; lby = by;
										x <= bx; y <= by + 1;
									end
									0: ;
									2: ;
									default: ;
								endcase
							end // end of 2:
							default: ;
						endcase	
					end
					
					default: ;
				endcase
			end	// end of if
		end // end of else
	end
	
	// ���� VGA ��ʾ
	// �ı߽߱磬�ⲿ��ʾ��ɫ
	// e - edge, l,r,u,e - left,right,up,down
	parameter le = 117, re = 522, ue = 37, de = 442, blkSz = 45;
	wire [8:0] x_addr, y_addr;			// 0~404
	wire [5:0] x_off, y_off;			// 0~44
	wire [3:0] x_num, y_num;			// 1~9
	reg [2:0] picInd;
	assign x_addr = col_addr - le;
	assign y_addr = row_addr - ue;
	assign x_off = x_addr % blkSz;
	assign y_off = y_addr % blkSz;
	assign x_num = x_addr / blkSz + 1;
	assign y_num = y_addr / blkSz + 1;
	
	wire [11:0] beanOut, mapOut;
	wire [13:0] refAddr;
	assign refAddr = picInd * blkSz * blkSz + x_off + y_off * blkSz;
	BeanRef beanRef(.clka(clk), .addra(refAddr), .douta(beanOut));
	MapRef mapRef(.clka(clk), .addra(refAddr), .douta(mapOut));
	
	wire [3:0] typeOut;
	wire [9:0] taddr;
	assign taddr = 1 + LevelOffset + WholeLevel * level + x_num + y_num * 11;
	LevelRef typeRef(.clka(clk), .addra(taddr), .douta(typeOut));
	
	parameter innerSz = 5;
	wire [2:0] x_inner_off, y_inner_off, x_inner_num, y_inner_num; 
	assign x_inner_off = x_off % innerSz;		// 0~4
	assign y_inner_off = y_off % innerSz;
	assign x_inner_num = x_off / innerSz + 1;	// 1~9
	assign y_inner_num = y_off / innerSz + 1;
	wire [3:0] innerTyOut;
	wire [9:0] innerTaddr;
	assign innerTaddr = 1 + LevelOffset + WholeLevel * level + x_inner_num + y_inner_num * 11;
	LevelRef innerTyRef(.clka(clk), .addra(innerTaddr), .douta(innerTyOut));
	
	
	wire [13:0] innerBoxAddr;
	wire [11:0] innerBoxOut;
	wire [1:0] iBoxPicInd;
	assign iBoxPicInd = level == 0 ? (isBox ? 2 : 0) : (isBox ? 3 : 1);
	assign innerBoxAddr = iBoxPicInd * 45 * 45 + x_off + y_off * 45;
	Lvpic innerBoxRef(.clka(clk), .addra(innerBoxAddr), .douta(innerBoxOut));
	
	reg [3:0] storeExp = 0;
	reg [8:0] str_x_addr, str_y_addr;			// 0~404 
	reg [2:0] str_xin, str_yin;
	//always@(*) begin
	always @(posedge clkdiv[1]) begin
		// ����������ڣ���ͼ
		if (row_addr >= ue && row_addr < de && col_addr >= le && col_addr < re) begin
			if (x_num == x && y_num == y) begin			// ����������Ƕ���...
				if (isBean)		picInd <= 4;				// ����Ѿ���λ������ɫ����
				else picInd <= lastDir;						// �����÷����Ӧ����
				vga_data = beanOut;							// �Ѷ�������� VGA	
			end 
			
			else if (x_num == bx && y_num == by) begin						// ����������������ڲ���...
			
				if (x_inner_num == x && y_inner_num == y) begin				// \_ ���ӣ�...
					if (y_inner_off == 1 && (x_inner_off == 1 || x_inner_off == 3)) begin								
						vga_data = 12'h0;												//    \_ ���۾�����ô���ɺ�ɫ
					end 
					else begin
						vga_data = isBean ? 12'h6f9 : 12'h60b;					//    \_	�����壬�����Ƿ�λ����/��
					end
				end
				
				else if (x_inner_num == bx && y_inner_num == by) begin	// \_ ���ӣ�...
					if (x_inner_off == 0 || x_inner_off == 4 
					 || y_inner_off == 0 || y_inner_off == 4)	begin					
						vga_data = 12'hfff;											//		\_ �ı߿���ô���ɰ�ɫ
					end 
					else begin
						vga_data = isBox ? 12'h5f8 : 12'hfb4;					//		\_ ���ڲ��������Ƿ�λ����/��
					end
				end
				
				else begin
					vga_data = innerBoxOut;
					/*case (innerTyOut)
						0: vga_data = isBox ? 12'h5f8 : 12'hfb4;				// \_ ��������ô�����Ƿ�λ����/��
						1, 3, 4: vga_data = isBox ? 12'h142 : 12'h631;
						default: begin 
							vga_data = 12'h0f0;
							if (storeExp == 0) begin
								storeExp = vga_data;
								str_x_addr = x_addr;
								str_y_addr = y_addr;
								str_xin = x_inner_num;
								str_yin = y_inner_num;
							end
						end
					endcase*/
				end
			end 
			
			else begin
				case (typeOut)
					0: if (isBean && isBox)	picInd <= 4;
						else	picInd <= 0;
					1:	if (isBean && isBox) picInd <= 5;
						else	picInd <= 1;
					3: picInd <= 2;
					4: picInd <= 3;
				endcase
				vga_data = mapOut;
			end
		end
		// ������ʾ��ɫ
		else vga_data = 12'h0;
	end
	
	// �� segTestData ��Ϊ level_0000_x_0000_y_0000_0_isBean_0_isBox
	// ����ʾ�� 7 ���������
	assign segTestData = {1'b0, level, 4'b0, x, 4'b0, y, 7'b0, isBean, 3'b0, isBox};
	//assign segTestData = {x, y, bx, by, lx, ly, lbx, lby};
	//assign segTextData = {storeExp, 3'b0, str_x_addr, 3'b0, str_y_addr, str_xin, str_yin};
	// ���� LED �����
	// ledData �� 16 ���Ƶ���ʾ����
	// �������ù�
	wire [15:0] ledData;
	// ����� SW_OK ������ ledData������ʾ�������
	assign ledData = SW_OK;
	ShiftReg #(.WIDTH(16)) ledDevice (.clk(clkdiv[3]), .pdata(~ledData), 
												 .sout({LED_CLK,LED_DO,LED_PEN,LED_CLR}));
endmodule
