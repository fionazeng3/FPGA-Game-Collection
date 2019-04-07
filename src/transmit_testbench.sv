// This is the testbench for the transmit module of the sps interface

module transmit_testbench();
	logic			clk_i;
	logic			clk_16_i;
	logic			rst_i;
	logic			trans_en_i;
	logic			load_i;
	logic			char_sent_o;
	logic	[7:0]	para_data_i;
	logic			serial_data_o;
	
	transmit dut(.*);
	
	parameter CLOCK_PERIOD = 320;
	parameter CLOCK_16_PERIOD = 20;
	initial begin
		clk_16_i <= 0;
		forever #(CLOCK_16_PERIOD/2) clk_16_i <= ~clk_16_i;
	end
	
	initial begin
		clk_i <= 0;
		forever #(CLOCK_PERIOD/2) clk_i <= ~clk_i;
	end
	
	initial begin
		rst_i <= 0;
		trans_en_i <= 0;
		load_i <= 0;
		para_data_i <= '0;
		#320;
		rst_i <= 1;
		#320;
		rst_i <= 0;
		#320;
		trans_en_i <= 1;
		load_i <= 1;
		para_data_i <= 8'b10110010;
		#320;
		para_data_i <= '1;
		#320;
		#320;
		#320;
		#320;
		#320;
		#320;
		#320;
		#3200;
		$stop;
	end
endmodule