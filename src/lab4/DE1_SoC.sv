

module DE1_SoC(CLOCK_50, SW, KEY, LEDR, GPIO_0);
    input CLOCK_50;
	 input [9:0]SW;
	 input [2:0] KEY;
	 inout [35:0] GPIO_0;
	 output [9:0] LEDR;

	 
	 
	  // assign every hardware port to the proper NIOS II microprocessor export connection

	 // Quartus auto-generated sram verilog code with port proper connected
	 //sram	sram_inst (.address (address), .clock (CLOCK_50), .data (sramOut), .wren (sramRWen), .q (sramIn));
    
	 logic [7:0]paraOut, paraIn;
	 // connects the nios to the hardware pins
	     nios2 niosDesign (
        .businput_external_connection_export   (paraOut),   //   businput_external_connection.export
        .busouput_external_connection_export   (paraIn),   //   busouput_external_connection.export
        .charrec_external_connection_export    (char_recv_o),    //    charrec_external_connection.export
        .charsent_external_connection_export   (char_sent_o),   //   charsent_external_connection.export
        .clk_clk                               (CLOCK_50),                               //                            clk.clk
        .led_pio_external_connection_export    (LEDR[7:0]),    //    led_pio_external_connection.export
        .loadi_external_connection_export      (load_i),      //      loadi_external_connection.export
        .reset_reset_n                         (KEY[0]),                         //                          reset.reset_n
        .switches07_external_connection_export (SW[7:0]), // switches07_external_connection.export
        .transen_external_connection_export    (trans_en_i),    //    transen_external_connection.export
    );
	 
	 
	 logic trans_en_i;
	 logic load_i;

	
	 logic char_sent_o;
	 logic char_recv_o;
    
//	logic sin, sout; 
//	assign sin = GPIO_0[28];
//	assign GPIO_0[29] = sout;
	logic clkout;
	clk16 otherClock(CLOCK_50, ~KEY[0], clkout);
	logic clr_r;
	clock_divider clk_div (clkout, clk_r);	
	
	 // verilog top module for the bus transmission 
	 serial_parallel_serial_interface busDesign
	(.clk_i(clk_r) 
	,.clk_16_i(clkout)
	,.rst_i(~KEY[0]) 
	,.trans_en_i(trans_en_i)  
	,.para_data_i(paraIn)
	,.load_i(load_i) 
	,.serial_data_i(GPIO_0[28])
	,.char_sent_o(char_sent_o)
	,.para_data_o(paraOut)
	,.char_recv_o(char_recv_o)
	,.serial_data_o(GPIO_0[29])
	);
	
	assign LEDR[8] = char_recv_o;
	assign LEDR[9] = ~GPIO_0[28];
	
endmodule



module clk16 (clk, rst, clkout);
	input clk, rst;
	output clkout;
	
	reg [7:0] edgecount, ns;

	// 50M / 9600 / 16 / 2 = 163
	// 162 = 0b10100010
	parameter clock = 8'b10100010;
	always@(*)
		case (edgecount)
			clock : ns = 8'b00000000;
			default : ns = edgecount + 8'b00000001;
		endcase
	
	always@(posedge clk or posedge rst)
		if (rst)
			edgecount <= 8'b00000000;
		else
			edgecount <= ns;
	
	
	reg clkps, clkns;
	assign clkout = clkps;
	
	always@(*)
		if (edgecount == clock)
			clkns = ~clkps;
		else 
			clkns = clkps;
			
	always@(posedge clk or posedge rst)
		if (rst)
			clkps <= 1'b0;
		else 
			clkps <= clkns;
endmodule


module clock_divider
	(input 	logic 		clock_i
	,output logic	slow_clock_o
	);
	logic[3:0]  divided_clocks;
	
	initial begin
		divided_clocks <= 0;
	end
		
	assign slow_clock_o = divided_clocks[3];
	
	always @(posedge clock_i)
		divided_clocks <= divided_clocks + 1;
endmodule


//module veri_testbench();
//	logic CLOCK_50;
//	logic [9:0] SW, LEDR;
//	logic [2:0] KEY;
//	logic GPIO_00, GPIO_01;
//	verilog_only dut (.*);
//	
//	assign GPIO_00 = GPIO_01;
//	
//	parameter CLOCK_PERIOD = 100;
//	initial begin
//		CLOCK_50 <= 0;
//		forever #(CLOCK_PERIOD / 2) CLOCK_50 <= ~CLOCK_50;
//	end
//	
//	initial begin
//		KEY[0] <= 1; 										@(posedge CLOCK_50);
//		KEY[0] <= 0; 										@(posedge CLOCK_50);
//		KEY[0] <= 1; SW[9] <= 0; SW[8] <= 0; SW[7:0] = 8'b11111111;	@(posedge CLOCK_50);
//																#100000000;
//		SW[9] <= 1; 										@(posedge CLOCK_50);
//																#100000000;
//		SW[7:0] <= 8'b11100101;							@(posedge CLOCK_50);
//																#100000000;
//		SW[8] <= 1;											@(posedge CLOCK_50);
//																#500000000;
//		SW[9] <= 0; SW[8] <= 0;							@(posedge CLOCK_50);
//																#500000000;
//		
//																
//		$stop;
//	end
//endmodule


