// This is the module for the bit identifier counter
//
// Input:
//		clk_i: the clock that this module runs on
//		rst_i: the reset signal for this module
//		en_i: the enable signal for this module
//
// Output:
//		count_o: the 4-bit count signal of the current state 

module bit_sample_counter
	(input	logic		clk_i
	,input	logic		rst_i
	,input	logic		en_i
	,output	logic [3:0]	count_o
	);
	
	// count register
	logic [3:0] count_r;
	
	
	always_ff @(posedge clk_i or posedge rst_i) begin
		if (rst_i) begin
			count_r <= 4'b0;
		end else if (en_i == 0) begin
			count_r <= 4'b0;
		end else if (en_i) begin
			count_r <= count_r + 1'b1;
		end else begin
			count_r <= count_r;
		end
	end

	assign count_o = count_r;
endmodule

/*
module bit_sample_counter_testbench();
	logic clk_i;
	logic rst_i;
	logic en_i;
	logic [3:0] count_o;
	
	bit_sample_counter dut (.*);

	parameter CLOCK_PERIOD = 10;
	initial begin
		clk_i <= 0;
		forever #(CLOCK_PERIOD/2) clk_i <= ~clk_i;
	end
	
	initial begin
		@(posedge clk_i);
		rst_i <= 0;
		en_i <= 0;
		@(posedge clk_i);
		rst_i <= 1;
		@(posedge clk_i);
		rst_i <= 0;
		@(posedge clk_i);
		@(posedge clk_i);
		@(posedge clk_i);
		en_i <= 1;
		@(posedge clk_i); @(posedge clk_i);	@(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i);	@(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		
		@(posedge clk_i); @(posedge clk_i);	@(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i);	@(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		en_i <= 0;
		@(posedge clk_i); @(posedge clk_i);	@(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i);	@(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		$stop;
	end
endmodule
*/