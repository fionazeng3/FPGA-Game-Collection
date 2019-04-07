// This is the top module for the Serial-Parallel-Serial interface
//
// Input:
//		From NIOS:
//			clk_i: the clock that this module runs on
//			clk_16_i: the clock 16 that the bit sample counter runs on
//			rst_i: the reset signal for  this module
//			en_i: the enable signal for whole module
//			trans_en_i: the transmit enable signal from NIOS processor
//			para_data_i: the 8-bit data that will be sent out in parallel form
//			load_i: the load signal from the NIOS processor
//		From outside:
//			serial_data_i: the serial form data will be sent to NIOS
// Output:
//		To NIOS:
//			char_sent_o: the signal that indicates the parallel form data is sent
//			para_data_o: the serial_data_i converted to parallel form
//			char_recv_o: the signal that indicates the serial data is received
//		To Outside:
//			serial_data_o: the para_data_i in serial form

module serial_parallel_serial_interface
	(input	logic		clk_i
	,input	logic		clk_16_i
	,input	logic		rst_i
	,input	logic		trans_en_i
	,input	logic [7:0]	para_data_i
	,input	logic		load_i
	,input	logic		serial_data_i
	,output	logic		char_sent_o
	,output	logic [7:0] para_data_o
	,output logic		char_recv_o
	,output	logic		serial_data_o
	);
	
	transmit p_to_s
		(.clk_i(clk_i)
		,.clk_16_i(clk_16_i)
		,.rst_i(rst_i)
		,.trans_en_i(trans_en_i)
		,.para_data_i(para_data_i)
		,.load_i(load_i)
		,.char_sent_o(char_sent_o)
		,.serial_data_o(serial_data_o)
		);
		
		
	receive s_to_p
		(.clk_i(clk_i)
		,.clk_16_i(clk_16_i)
		,.rst_i(rst_i)
		,.serial_data_i(serial_data_i)
		,.char_recv_o(char_recv_o)
		,.para_data_o(para_data_o)
		);
	
endmodule