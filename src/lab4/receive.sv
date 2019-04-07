// This is the module that will convert the serial data from outside to serial
//	form and sent it to NIOS.
//
// Input:
//		clk_i: the clock that this module runs on
//		rst_i: the reset signal for  this module
//		en_i: the enable signal for whole module
//		serial_data_i: the serial form data will be sent to NIOS
//
// Output:
//		char_recv_o: the signal that indicates the serial data is received
//		para_data_o: the serial_data_i converted to parallel form

module receive
	(input	logic		clk_i
	,input	logic		clk_16_i
	,input	logic		rst_i
	,input	logic		serial_data_i
	,output	logic		char_recv_o
	,output	logic [7:0]	para_data_o
	);
	
	logic serial_data;
	logic recv_en;
	logic recv_busy;
	logic bic_init;
	logic [3:0] bsc_count;
	
	io_buffer buffer
		(.clk_i(clk_i)
		,.rst_i(rst_i)
		,.data_i(serial_data_i)
		,.data_o(serial_data)
		);
	
	start_detect detect
		(.clk_i(clk_i)
		,.rst_i(rst_i)
		,.data_i(serial_data)
		,.init_o(bic_init)
		,.recv_en_o(recv_en)
		);
	
	bit_identification_counter bic
		(.clk_i(clk_i)
		,.rst_i(rst_i)
		,.en_i(recv_en)
		,.init_i(bic_init)
		,.trans_recv_done_o(char_recv_o)
		);
	
	bit_sample_counter send_bsc
		(.clk_i(clk_16_i)
		,.rst_i(rst_i)
		,.en_i(recv_en)
		,.count_o(bsc_count)
		);
	
	sr_clock_control srcc_p_to_s
		(.bsc_count_i(bsc_count)
		,.sr_clock_o(sr_clock)
		);
		
	sipo sipo_buffer
		(.sr_clk_i(sr_clock)
		,.rst_i(rst_i)
		,.enable_i(recv_en)
		,.data_i(serial_data)
		,.data_o(para_data_o)
		,.busy_o(recv_busy)
		);
	
endmodule


module receive_testbench();
	logic			clk_i;
	logic			clk_16_i;
	logic			rst_i;
	logic			char_recv_o;
	logic	[7:0]	para_data_o;
	logic			serial_data_i;
	
	receive dut(.*);
	
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
		serial_data_i <= 1;
		#320;
		rst_i <= 1;
		#320;
		rst_i <= 0;
		#320;
		serial_data_i <= 0;
		#320;
		serial_data_i <= 1;
		#320;
		serial_data_i <= 0;
		#320;
		serial_data_i <= 0;
		#320;
		serial_data_i <= 1;
		#320;
		serial_data_i <= 1;
		#320;
		serial_data_i <= 0;
		#320;
		serial_data_i <= 1;
		#320;
		#3200;
		$stop;
	end
endmodule