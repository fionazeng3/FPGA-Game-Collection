module detection
	(input	logic	clk_i
	,input	logic	rst_i
	,input	logic	data_i		// serial-in data
	,output	logic	detect_o	// initially 0, change to 1 if the data_i changes
	);
	
	logic	data_buff;
	
	always_ff @(posedge clk_i) begin
		data_buff <= data_i;
	end
	
	logic changed;
	
	assign changed = data_i ^ data_buff;
	
	typedef enum logic {eHold, eChange} state_e;
	state_e state_n, state_r;
	
	always_ff @(posedge clk_i) begin
		state_r <= rst_i ? eHold : state_n;
	end
	
	always_comb begin
		case(state_r)
			eHold: begin
				detect_o = 0;
				state_n = eHold;
				if (changed) begin
					state_n = eChange;
					detect_o = 1;
				end
			end
			eChange: begin
				detect_o = 1;
				state_n = eChange;
			end
			default : begin
				detect_o = 0;
				state_n = eHold;
			end
		endcase
	end
	
endmodule


module detect_testbench();
	logic	clk_i;
	logic	rst_i;
	logic	data_i;
	logic	detect_o;
	
	detection dut(.*);
	
	initial begin
		clk_i <= 1;
		forever #(50) clk_i <= ~clk_i;
	end

	initial begin
		rst_i <= 0;
		data_i <= 1;
		@(posedge clk_i);
		rst_i <= 1;
		@(posedge clk_i);
		rst_i <= 0;
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		data_i <= 0;
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		data_i <= 1;
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i); 
		$stop;
	end 

endmodule