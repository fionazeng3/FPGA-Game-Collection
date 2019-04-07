// This is the module for parallel in serial out
// Input:
// 		sr_clk_i: 	the clock for this module, it is not the original clock, it is
//					the modified version by BSC, which have a 0.5T latency.
//		rst_i:		the reset signal.
//		data_i:		the input signal, it is an 8 bits parallel signal sent by the
//					microprocessor, representing the char it stores.
//		load_i:		the signal that instruct the module to load data. After this 
//					signal is switched to high, the module will read input data.
//					The default load signal is a one cycle pulse.
//	Output:
//		data_o:		the output data signal, this signal is serial, containing a start
//					bit before the data, so the signal would have 9 bits of information,
//					a start bit that is set to 0, the 8 bits data, otherwise it stays at 1.
//		busy_o:		the signal that indicates that this module is currently processing
//					data, so that the input shouldn't change.
module piso (sr_clk_i, rst_i, data_i, data_o, load_i, busy_o);
	input logic sr_clk_i, rst_i, load_i;
	input logic [7:0] data_i;
	output logic data_o;
	output logic busy_o;
	
	logic [9:0] data_buffer;
	logic ps, ns;
	parameter IDLE = 1'b0;
	parameter LOADING = 1'b1;
	
	
	logic load_b, load_c, load;
	
	assign load = load_b && ~load_c;
	
	always_comb begin
	 case (ps)
		IDLE:
		begin
			if (load) begin
				ns = LOADING;
			end else begin
				ns = IDLE;
			end
		end
		LOADING:
		begin
			if (data_buffer == 10'b1000000000) begin
				ns = IDLE;
			end else begin 
				ns = LOADING;
			end
		end
		default:
			ns = IDLE;
	 endcase
	end
	
	assign busy_o = ps;
	
	always_ff @(posedge sr_clk_i or posedge rst_i) 
	begin
		if (rst_i) begin
			ps = IDLE;
			data_buffer = 10'b1111111111;
			data_o = 1;
		end else begin
			load_c = load_b;
			load_b = load_i;
			ps = ns;
			if (ps == IDLE) begin
				data_o = 1;
				data_buffer[8:1] = data_i[7:0];
				data_buffer[9] = 1'b0;
				data_buffer[0] = 1'b1;
			end else begin
				data_o = data_buffer[9];
				data_buffer[9:1] = data_buffer[8:0];
				data_buffer[0] = 1'b0;
			end
		end
	end
endmodule

module piso_testbench();
	logic sr_clk_i, rst_i, data_o, load_i, busy_o;
	logic [7:0] data_i;
	piso dut (.*);
	
	parameter CLOCK_PERIOD = 100;
	initial begin
		sr_clk_i <= 0;
		forever #(CLOCK_PERIOD / 2) sr_clk_i <= ~sr_clk_i;
	end
	
	initial begin
		rst_i = 0; 				@(posedge sr_clk_i);
		rst_i = 1; 				@(posedge sr_clk_i);
		rst_i = 0; 				@(posedge sr_clk_i);
		data_i = 8'b00101100; 	@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
		load_i = 1; 			@(posedge sr_clk_i);
		load_i = 0; 			@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
		data_i = 8'b11010010; 	@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
		load_i = 1; 			@(posedge sr_clk_i);
		load_i = 0; 			@(posedge sr_clk_i);
								@(posedge sr_clk_i);
		data_i = 8'b00101010; 	@(posedge sr_clk_i);
								@(posedge sr_clk_i);
		load_i = 1; 			@(posedge sr_clk_i);
		load_i = 0; 			@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
								@(posedge sr_clk_i);
		$stop;
	end
endmodule