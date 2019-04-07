
module nios2 (
	businput_external_connection_export,
	busouput_external_connection_export,
	charrec_external_connection_export,
	charsent_external_connection_export,
	clk_clk,
	led_pio_external_connection_export,
	loadi_external_connection_export,
	reset_reset_n,
	switches07_external_connection_export,
	transen_external_connection_export);	

	input	[7:0]	businput_external_connection_export;
	output	[7:0]	busouput_external_connection_export;
	input		charrec_external_connection_export;
	input		charsent_external_connection_export;
	input		clk_clk;
	output	[7:0]	led_pio_external_connection_export;
	output		loadi_external_connection_export;
	input		reset_reset_n;
	input	[7:0]	switches07_external_connection_export;
	output		transen_external_connection_export;
endmodule
