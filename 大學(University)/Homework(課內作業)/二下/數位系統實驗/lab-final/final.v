/* 
(C) OOMusou 2008 http://oomusou.cnblogs.com

Filename    : DE2.v
Compiler    : Quartus II 8.0
Description : Demo how to write color pattern generator
Release     : 11/16/2008 1.0
*/

module final (
		////////////////////	Clock Input	 	////////////////////	 
		CLOCK_50,						//	50 MHz
		CLOCK_50_2,						//	50 MHz
		////////////////////	Push Button		////////////////////
		ORG_BUTTON,						//	Pushbutton[2:0]
		////////////////////	DPDT Switch		////////////////////
		SW,								//	Toggle Switch[9:0]
		////////////////////	7-SEG Dispaly	////////////////////
		HEX0_D,							//	Seven Segment Digit 0
		HEX0_DP,						//	Seven Segment Digit DP 0
		HEX1_D,							//	Seven Segment Digit 1
		HEX1_DP,						//	Seven Segment Digit DP 1
		HEX2_D,							//	Seven Segment Digit 2
		HEX2_DP,						//	Seven Segment Digit DP 2
		HEX3_D,							//	Seven Segment Digit 3
		HEX3_DP,						//	Seven Segment Digit DP 3
		////////////////////////	LED		////////////////////////
		LEDG,							//	LED Green[9:0]
		////////////////////////	UART	////////////////////////
		UART_TXD,						//	UART Transmitter
		UART_RXD,						//	UART Receiver
		UART_CTS,						//	UART Clear To Send
		UART_RTS,						//	UART Request To Send
		/////////////////////	SDRAM Interface		////////////////
		DRAM_DQ,						//	SDRAM Data bus 16 Bits
		DRAM_ADDR,						//	SDRAM Address bus 13 Bits
		DRAM_LDQM,						//	SDRAM Low-byte Data Mask 
		DRAM_UDQM,						//	SDRAM High-byte Data Mask
		DRAM_WE_N,						//	SDRAM Write Enable
		DRAM_CAS_N,						//	SDRAM Column Address Strobe
		DRAM_RAS_N,						//	SDRAM Row Address Strobe
		DRAM_CS_N,						//	SDRAM Chip Select
		DRAM_BA_0,						//	SDRAM Bank Address 0
		DRAM_BA_1,						//	SDRAM Bank Address 1
		DRAM_CLK,						//	SDRAM Clock
		DRAM_CKE,						//	SDRAM Clock Enable
		////////////////////	Flash Interface		////////////////
		FL_DQ,							//	FLASH Data bus 15 Bits
		FL_DQ15_AM1,					//	FLASH Data bus Bit 15 or Address A-1
		FL_ADDR,						//	FLASH Address bus 22 Bits
		FL_WE_N,						//	FLASH Write Enable
		FL_RST_N,						//	FLASH Reset
		FL_OE_N,						//	FLASH Output Enable
		FL_CE_N,						//	FLASH Chip Enable
		FL_WP_N,						//	FLASH Hardware Write Protect
		FL_BYTE_N,						//	FLASH Selects 8/16-bit mode
		FL_RY,							//	FLASH Ready/Busy
		////////////////////	LCD Module 16X2		////////////////
		LCD_BLON,						//	LCD Back Light ON/OFF
		LCD_RW,							//	LCD Read/Write Select, 0 = Write, 1 = Read
		LCD_EN,							//	LCD Enable
		LCD_RS,							//	LCD Command/Data Select, 0 = Command, 1 = Data
		LCD_DATA,						//	LCD Data bus 8 bits
		////////////////////	SD_Card Interface	////////////////
		SD_DAT0,						//	SD Card Data 0
		SD_DAT3,						//	SD Card Data 3
		SD_CMD,							//	SD Card Command Signal
		SD_CLK,							//	SD Card Clock
		SD_WP_N,						//	SD Card Write Protect
		////////////////////	PS2		////////////////////////////
		PS2_KBDAT,						//	PS2 Keyboard Data
		PS2_KBCLK,						//	PS2 Keyboard Clock
		PS2_MSDAT,						//	PS2 Mouse Data
		PS2_MSCLK,						//	PS2 Mouse Clock
		////////////////////	VGA		////////////////////////////
		VGA_HS,							//	VGA H_SYNC
		VGA_VS,							//	VGA V_SYNC
		VGA_R,   						//	VGA Red[3:0]
		VGA_G,	 						//	VGA Green[3:0]
		VGA_B,  						//	VGA Blue[3:0]
		////////////////////	GPIO	////////////////////////////
		GPIO0_CLKIN,					//	GPIO Connection 0 Clock In Bus
		GPIO0_CLKOUT,					//	GPIO Connection 0 Clock Out Bus
		GPIO0_D,						//	GPIO Connection 0 Data Bus
		GPIO1_CLKIN,					//	GPIO Connection 1 Clock In Bus
		GPIO1_CLKOUT,					//	GPIO Connection 1 Clock Out Bus
		GPIO1_D							//	GPIO Connection 1 Data Bus
	);
	////////////////////////	Clock Input	 	////////////////////////
	input			CLOCK_50;				//	50 MHz
	input			CLOCK_50_2;				//	50 MHz
	////////////////////////	Push Button		////////////////////////
	input	[2:0]	ORG_BUTTON;				//	Pushbutton[2:0]
	////////////////////////	DPDT Switch		////////////////////////
	input	[9:0]	SW;						//	Toggle Switch[9:0]
	////////////////////////	7-SEG Dispaly	////////////////////////
	output	[6:0]	HEX0_D;					//	Seven Segment Digit 0
	output			HEX0_DP;				//	Seven Segment Digit DP 0
	output	[6:0]	HEX1_D;					//	Seven Segment Digit 1
	output			HEX1_DP;				//	Seven Segment Digit DP 1
	output	[6:0]	HEX2_D;					//	Seven Segment Digit 2
	output			HEX2_DP;				//	Seven Segment Digit DP 2
	output	[6:0]	HEX3_D;					//	Seven Segment Digit 3
	output			HEX3_DP;				//	Seven Segment Digit DP 3
	////////////////////////////	LED		////////////////////////////
	output	[9:0]	LEDG;					//	LED Green[9:0]
	////////////////////////////	UART	////////////////////////////
	output			UART_TXD;				//	UART Transmitter
	input			UART_RXD;				//	UART Receiver
	output			UART_CTS;				//	UART Clear To Send
	input			UART_RTS;				//	UART Request To Send
	///////////////////////		SDRAM Interface	////////////////////////
	inout	[15:0]	DRAM_DQ;				//	SDRAM Data bus 16 Bits
	output	[12:0]	DRAM_ADDR;				//	SDRAM Address bus 13 Bits
	output			DRAM_LDQM;				//	SDRAM Low-byte Data Mask
	output			DRAM_UDQM;				//	SDRAM High-byte Data Mask
	output			DRAM_WE_N;				//	SDRAM Write Enable
	output			DRAM_CAS_N;				//	SDRAM Column Address Strobe
	output			DRAM_RAS_N;				//	SDRAM Row Address Strobe
	output			DRAM_CS_N;				//	SDRAM Chip Select
	output			DRAM_BA_0;				//	SDRAM Bank Address 0
	output			DRAM_BA_1;				//	SDRAM Bank Address 1
	output			DRAM_CLK;				//	SDRAM Clock
	output			DRAM_CKE;				//	SDRAM Clock Enable
	////////////////////////	Flash Interface	////////////////////////
	inout	[14:0]	FL_DQ;					//	FLASH Data bus 15 Bits
	inout			FL_DQ15_AM1;			//	FLASH Data bus Bit 15 or Address A-1
	output	[21:0]	FL_ADDR;				//	FLASH Address bus 22 Bits
	output			FL_WE_N;				//	FLASH Write Enable
	output			FL_RST_N;				//	FLASH Reset
	output			FL_OE_N;				//	FLASH Output Enable
	output			FL_CE_N;				//	FLASH Chip Enable
	output			FL_WP_N;				//	FLASH Hardware Write Protect
	output			FL_BYTE_N;				//	FLASH Selects 8/16-bit mode
	input			FL_RY;					//	FLASH Ready/Busy
	////////////////////	LCD Module 16X2	////////////////////////////
	inout	[7:0]	LCD_DATA;				//	LCD Data bus 8 bits
	output			LCD_BLON;				//	LCD Back Light ON/OFF
	output			LCD_RW;					//	LCD Read/Write Select, 0 = Write, 1 = Read
	output			LCD_EN;					//	LCD Enable
	output			LCD_RS;					//	LCD Command/Data Select, 0 = Command, 1 = Data
	////////////////////	SD Card Interface	////////////////////////
	inout			SD_DAT0;				//	SD Card Data 0
	inout			SD_DAT3;				//	SD Card Data 3
	inout			SD_CMD;					//	SD Card Command Signal
	output			SD_CLK;					//	SD Card Clock
	input			SD_WP_N;				//	SD Card Write Protect
	////////////////////////	PS2		////////////////////////////////
	inout		 	PS2_KBDAT;				//	PS2 Keyboard Data
	inout			PS2_KBCLK;				//	PS2 Keyboard Clock
	inout		 	PS2_MSDAT;				//	PS2 Mouse Data
	inout			PS2_MSCLK;				//	PS2 Mouse Clock
	////////////////////////	VGA			////////////////////////////
	output			VGA_HS;					//	VGA H_SYNC
	output			VGA_VS;					//	VGA V_SYNC
	output	[3:0]	VGA_R;   				//	VGA Red[3:0]
	output	[3:0]	VGA_G;	 				//	VGA Green[3:0]
	output	[3:0]	VGA_B;   				//	VGA Blue[3:0]
	////////////////////////	GPIO	////////////////////////////////
	input	[1:0]	GPIO0_CLKIN;			//	GPIO Connection 0 Clock In Bus
	output	[1:0]	GPIO0_CLKOUT;			//	GPIO Connection 0 Clock Out Bus
	inout	[31:0]	GPIO0_D;				//	GPIO Connection 0 Data Bus
	input	[1:0]	GPIO1_CLKIN;			//	GPIO Connection 1 Clock In Bus
	output	[1:0]	GPIO1_CLKOUT;			//	GPIO Connection 1 Clock Out Bus
	inout	[31:0]	GPIO1_D;				//	GPIO Connection 1 Data Bus
	
	// Horizontal Parameter
	parameter H_FRONT = 16;
	parameter H_SYNC  = 96;
	parameter H_BACK  = 48;
	parameter H_ACT   = 640;
	parameter H_BLANK = H_FRONT + H_SYNC + H_BACK;
	parameter H_TOTAL = H_FRONT + H_SYNC + H_BACK + H_ACT;

	// Vertical Parameter
	parameter V_FRONT = 11;
	parameter V_SYNC  = 2;
	parameter V_BACK  = 32;
	parameter V_ACT   = 480;
	parameter V_BLANK = V_FRONT + V_SYNC + V_BACK;
	parameter V_TOTAL = V_FRONT + V_SYNC + V_BACK + V_ACT;

	wire CLK_25;
	wire CLK_to_DAC;
	wire RST_N;
	
	/*PLL pll0 (
	  .inclk0(CLOCK_50),
	  .c0(CLK_25)
	);*/
	divn # (.WIDTH(26), .N(2))
	u0 (
	  .clk(CLOCK_50),
	  .rst_n(SW[0]),
	  .o_clk(CLK_25)
	);

	// Select DAC clock
	assign CLK_to_DAC = CLK_25;
	assign VGA_SYNC  = 1'b0;        // This pin is unused.
	assign VGA_BLANK = ~((H_Cont<H_BLANK)||(V_Cont<V_BLANK));
	assign VGA_CLK   = ~CLK_to_DAC; // Invert internal clock to output clock
	assign RST_N     = SW[0];      // Set reset signal is KEY[0]

	wire BT[0:2];
	assign BT[0] = ORG_BUTTON[0];
	assign BT[1] = ORG_BUTTON[1];
	assign BT[2] = ORG_BUTTON[2];

	reg [10:0] H_Cont;
	reg [10:0] V_Cont;
	reg [9:0]  vga_r;
	reg [9:0]  vga_g;
	reg [9:0]  vga_b;
	reg        vga_hs;
	reg        vga_vs;
	reg [10:0] X;
	reg [10:0] Y;

	assign VGA_R = vga_r;
	assign VGA_G = vga_g;
	assign VGA_B = vga_b;
	assign VGA_HS = vga_hs;
	assign VGA_VS = vga_vs;

	// Horizontal Generator: Refer to the pixel clock
	always@(posedge CLK_to_DAC, negedge RST_N) begin
		if(!RST_N) begin
			H_Cont <= 0;
			vga_hs <= 1;
			X      <= 0;
		end 
		else begin
			if (H_Cont < H_TOTAL)
				H_Cont	<=	H_Cont+1'b1;
			else
				H_Cont	<=	0;
			  
			// Horizontal Sync
			if(H_Cont == H_FRONT-1) // Front porch end
				vga_hs <= 1'b0;
			  
			if(H_Cont == H_FRONT + H_SYNC -1) // Sync pulse end
				vga_hs <= 1'b1;

			// Current X
			if(H_Cont >= H_BLANK)
				X <= H_Cont-H_BLANK;
			else
				X <= 0;
		end
	end

	// Vertical Generator: Refer to the horizontal sync
	always@(posedge VGA_HS, negedge RST_N) begin
		if(!RST_N) begin
				V_Cont <= 0;
				vga_vs <= 1;
				Y      <= 0;
		end
		else begin
			if (V_Cont<V_TOTAL)
				V_Cont <= V_Cont + 1'b1;
			else
				V_Cont	<= 0;
			  
			// Vertical Sync
			if (V_Cont == V_FRONT-1) // Front porch end
				vga_vs <= 1'b0;
			  
			if (V_Cont == V_FRONT + V_SYNC-1) // Sync pulse end
				vga_vs <= 1'b1;
			  
			// Current Y
			if (V_Cont >= V_BLANK)
				Y <= V_Cont-V_BLANK;
			else
				Y <= 0;
		end
	end


	integer rxc = 100;
	integer rxr = 15;
	integer ryc = 300;
	integer ryr = 30;
	integer jh  = 0;
	integer jcd = 0;
	integer jh2  = 0;
	integer jcd2 = 0;
	integer jcount = 0;
	integer timer = 0;
	integer s10 = 250000000;// 10s
	integer s1  = 25000000;// 1s
	integer ms1 = 25000;// 1ms
	integer	clock = 0;
	integer djbool = 0;
	integer lifecount = 3;
	integer gamelock = 2;
	integer moving = 0;
	integer touchboxA = 0;
	integer touchboxB = 0;
	integer bAx = 700;
	integer bAy = 300;
	integer bBx = 1020;
	integer bBy = 300;
	
// Pattern Generator
	always@(posedge CLK_to_DAC, negedge RST_N) begin
		if(!RST_N) begin
			vga_r <= 0;
			vga_g <= 0;
			vga_b <= 0;
			jh  = 0;
			jcd = 0;
			jh2  = 0;
			jcd2 = 0;
			jcount = 0;
			timer = 0;
			clock = 0;
			djbool = 0;
			lifecount = 3;
			gamelock = 2;
			moving = 0;
			touchboxA = 0;
			touchboxB = 0;
			bAx = 700;
			bAy = 300;
			bBx = 1020;
			bBy = 300;
		end
		else begin
		/*
			if(!BT[2]) begin
				if(jcd == 0 && jcd2 == 0) begin
					jh = 0;
					jcd = s1;
					timer = 0;
				end
				else if(jcd2 == 0 && djbool == 1 && jcount == 0) begin 
					jh2 = 0;
					jcd2 = s1/2;
					djbool = 0;
					jcount = 1;
				end
			end
			
			if(jcd != 0)
				timer = timer + 1;
			else if(jcd2 != 0)
				timer = timer + 1;
				
			if(timer > 500*ms1 && jcount == 0)
				djbool = 1;
			
			if(jcd2 != 0) begin 
				if (jcd2 > s1/4 && jcd2 % (5*ms1) == 0)
					jh2 = jh2 - 1;
				else if (jcd2 % (5*ms1) == 0 && jcd2 != 0)
					jh2 = jh2 + 1;
				jcd2 = jcd2 - 1;
			end
			else if(jcd != 0) begin //going up and going down
				if (jcd > s1/2 && jcd % (5*ms1) == 0)
					jh = jh - 1;
				else if (jcd % (5*ms1) == 0 && jcd != 0) //can use double jump
					jh = jh + 1;
				jcd = jcd - 1;
			end
			else if(jcd == 0 && jcd2 == 0) begin
				jcount = 0;
				timer = 0;
				djbool = 0;
				jh = 0;
				jh2 = 0;
			end	
		*/		
			if(gamelock == 0) begin	
				clock = clock + 1;
				if(clock % s1 == 0) begin
					clock = 0;
					/*if(!BT[0]) begin
						lifecount = lifecount - 1;
					end*/
				end
				if(clock % (100*ms1) == 0) begin
					if(lifecount == 0)
						gamelock = 1;
				end
				if(clock % (10*ms1) == 0) begin
					moving = moving + 1;
					if( moving % 1280 == 0 )
						moving = 0;
					bAx = bAx - 1;
					bBx = bBx - 1;
					if(bAx == -50) begin
						bAx = 700;
						touchboxA = 0;
					end
					if(bBx == -50) begin
						bBx = 700;
						touchboxB = 0;
					end
					
					if(touchboxA == 0 && bAx-rxr<=rxc+rxr && bAx+rxr >= rxc-rxr && bAy-ryr/2<=ryc+ryr+jh+jh2 && bAy+ryr/2 >= ryc-ryr+jh+jh2) begin
						touchboxA = 1;
						lifecount = lifecount - 1;
					end
					if(touchboxB == 0 && bBx-rxr<=rxc+rxr && bBx+rxr >= rxc-rxr && bBy-ryr/2<=ryc+ryr+jh+jh2 && bBy+ryr/2 >= ryc-ryr+jh+jh2) begin
						touchboxB = 1;
						lifecount = lifecount - 1;
					end
				end
				if(clock % ms1 == 0) begin
					if(!BT[2]) begin
						if(jcd == 0 && jcd2 == 0) begin
							jh = 0;
							jcd = s1 / ms1;
							timer = 0;
						end
						else if(jcd2 == 0 && djbool == 1 && jcount == 0) begin 
							jh2 = 0;
							jcd2 = s1 / 2 / ms1;
							djbool = 0;
							jcount = 1;
						end
					end
					
					if(jcd != 0)
						timer = timer + 1;
					else if(jcd2 != 0)
						timer = timer + 1;
						
					if(timer > 500 && jcount == 0)
						djbool = 1;
					
					if(jcd2 != 0) begin 
						if (jcd2 > s1/4/ms1 && jcd2 % 5 == 0)
							jh2 = jh2 - 1;
						else if (jcd2 % 5 == 0 && jcd2 != 0)
							jh2 = jh2 + 1;
						jcd2 = jcd2 - 1;
					end
					else if(jcd != 0) begin //going up and going down
						if (jcd > s1/2/ms1 && jcd % 5 == 0)
							jh = jh - 1;
						else if (jcd % 5 == 0 && jcd != 0) //can use double jump
							jh = jh + 1;
						jcd = jcd - 1;
					end
					else if(jcd == 0 && jcd2 == 0) begin
						jcount = 0;
						timer = 0;
						djbool = 0;
						jh = 0;
						jh2 = 0;
					end	
				end
			end
			
			vga_r <= ( X>=rxc-rxr && X<rxc+rxr && Y>=ryc-ryr+jh+jh2 && Y<ryc+ryr+jh+jh2) ? 1023 : 
					 ( lifecount >= 3 && X>=rxc-8+25 && X<rxc+8+25 && Y>=24 && Y<48) ? 1023 :
					 ( lifecount >= 2 && X>=rxc-8 && X<rxc+8 && Y>=24 && Y<48) ? 1023 :
					 ( lifecount >= 1 && X>=rxc-8-25 && X<rxc+8-25 && Y>=24 && Y<48) ? 1023 :
					 ( touchboxA == 0 && X>=((bAx-rxr>0) ? bAx-rxr : 1) && X<((bAx+rxr>0) ? bAx+rxr : 1) && Y>=bAy-ryr/2 && Y<bAy+ryr/2) ? 1023 : 
					 ( touchboxB == 0 && X>=((bBx-rxr>0) ? bBx-rxr : 1) && X<((bBx+rxr>0) ? bBx+rxr : 1) && Y>=bBy-ryr/2 && Y<bBy+ryr/2) ? 1023 : 
					 128;
				
			/*vga_g <= ( 1 == 2 && Y>=280 ) ? 1023 : // debug line
					 ( 1 == 2 && X>=32 * 1 && X<32 * 19 && Y == 240) ? 1023 :
					 ( 1 == 2 && X == 320 && Y>=24 * 1 && Y<24 * 19) ? 1023 :
					 ( X>=1 && X<640 && Y == 240) ? 1023 :
					 ( X == 320 && Y>=1 && Y<480) ? 1023 :
					 128;*/
					 
			vga_g <= ( Y >= ryc+ryr && Y <= ryc+ryr+4 ) ? 1023 :
					 ( Y == ryc+ryr+48*1 ) ? 1023 :
					 ( Y == ryc+ryr+48*2 ) ? 1023 :
					 ( Y == ryc+ryr+48*3 ) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*1-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*2-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*3-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*4-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*5-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*6-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*7-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*8-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*9-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*10-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*11-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*12-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*13-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*14-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*15-moving%40) ? 1023 :
					 ( Y >= ryc+ryr && X == 40*16-moving%40) ? 1023 :
					 128;			 
						 
			vga_b <= ( Y>=1 && Y < 96) ? 1023:
					 128;
					 
			if(gamelock == 1) begin
				vga_r <= ( 1 == 2 &&Y>=160 && Y<=200) ? 1023 :
						 // n
						 ( Y == 180 && X>=320-5 && X<=320+5) ? 1023 :
						 ( Y >= 175 && Y <= 200 && X==320-5) ? 1023 :
						 ( Y >= 180 && Y <= 200 && X==320+5) ? 1023 :
						 // E
						 ( Y == 160 && X>=320-30-10 && X<=320-30+10) ? 1023 :
						 ( Y == 180 && X>=320-30-10 && X<=320-30+10) ? 1023 :
						 ( Y == 200 && X>=320-30-10 && X<=320-30+10) ? 1023 :
						 ( Y >= 160 && Y <= 200 && X==320-30-10) ? 1023 :
						 // d
						 ( Y == 180 && X>=320+20-5 && X<=320+20+5) ? 1023 :
						 ( Y == 200 && X>=320+20-5 && X<=320+20+5) ? 1023 :
						 ( Y >= 180 && Y <= 200 && X==320+20-5) ? 1023 :
						 ( Y >= 160 && Y <= 200 && X==320+20+5) ? 1023 :
						 128;
				
			end
			else if(gamelock == 2) begin
				vga_r <= ( 1 == 2 &&Y>=160 && Y<=200) ? 1023 :
						 // T
						 ( Y == 160 && X>=320-10 && X<=320+10) ? 1023 :
						 ( Y >= 160 && Y <= 200 && X==320) ? 1023 :
						 // B
						 ( Y == 160 && X>=320-40-10 && X<=320-40+10) ? 1023 :
						 ( Y == 180 && X>=320-40-10 && X<=320-40+10) ? 1023 :
						 ( Y == 200 && X>=320-40-10 && X<=320-40+10) ? 1023 :
						 ( Y >= 160 && Y <= 200 && X==320-40-10) ? 1023 :
						 ( Y >= 160 && Y <= 200 && X==320-40+10) ? 1023 :
						 // 2
						 ( Y == 160 && X>=320+40-10 && X<=320+40+10) ? 1023 :
						 ( Y == 180 && X>=320+40-10 && X<=320+40+10) ? 1023 :
						 ( Y == 200 && X>=320+40-10 && X<=320+40+10) ? 1023 :
						 ( Y >= 180 && Y <= 200 && X==320+40-10) ? 1023 :
						 ( Y >= 160 && Y <= 180 && X==320+40+10) ? 1023 :
						 128;
				
				if(!BT[2]) begin
					gamelock = 0;
				end
			end
		end
	end

endmodule
