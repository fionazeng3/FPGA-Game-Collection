// This is the bit identification counter module
//
// Input:
//		clk_i: the clock that this module runs on
//		rst_i: the reset signal for  this module
//		en_i: the enable signal for whole module
//		count_i: 
//
// Output:
//		trans_recv_done_o: the signal that indicates the parallel form data is sent
	
module bit_identification_counter
	(input	logic		clk_i
	,input	logic		rst_i
	,input	logic		en_i
	,input	logic		init_i
	,output	logic		trans_recv_done_o
	);
	
	logic count_init;
	logic init_b;

	always_ff @(posedge clk_i) begin
		init_b <= init_i;
	end
	
	assign count_init = (init_b ^ init_i) && init_i; 
	
	
	// bic_count register
	logic [3:0] count_r;
	logic count_en, count_rst;

	always_ff @(posedge clk_i or posedge rst_i) begin
		if (rst_i) begin
			count_r <= '1;
		end else if (count_rst) begin
			count_r <= '1;
		end else if (count_en && en_i) begin
			count_r <= count_r - 1'b1;
		end else begin
			count_r <= count_r;
		end
	end	
	
	typedef enum logic [1:0] {eWait, eBusy, eDone} state_e;
	state_e state_r, state_n;
	
	always_ff @(posedge clk_i or posedge rst_i) begin
		if (rst_i) begin
			state_r <= eWait;
		end else if (en_i) begin
			state_r <= state_n;
		end else begin
			state_r <= state_r;
		end
	end
	
	always_comb begin
		case(state_r)
			eWait: begin // wait for posedge of load
				state_n = eWait;
				count_en = 1'b0;
				count_rst = 1'b1;
				if (count_init) begin
					state_n = eBusy;
					count_en = 1'b1;
					count_rst = 1'b0;
				end			
			end
			
			eBusy: begin // data is being transmitted 
				state_n = eBusy;
				count_en = 1'b1;
				count_rst = 1'b0;
				if (count_r == 4'b0000) begin
					state_n = eDone;
				end
				
			end
			
			eDone: begin
				state_n = eDone;
				count_en = 1'b0;
				count_rst = 1'b1;
				if (count_init == 1'b1) begin
					state_n = eBusy;
					count_en = 1'b1;
					count_rst = 1'b0;
				end
			end
		endcase
	end
	
	assign trans_recv_done_o = (count_r == 0);
	
endmodule

module bit_identification_counter_testbench();
	logic clk_i;
	logic rst_i;
	logic en_i;
	logic init_i;
	logic trans_recv_done_o;
	
	bit_identification_counter dut(.*);
	
	initial begin
		clk_i <= 1;
		forever #(50) clk_i <= ~clk_i;
	end

	initial begin
		rst_i <= 0;
		en_i <= 0;
		init_i <= 0;
		@(posedge clk_i);
		rst_i <= 1;
		@(posedge clk_i);
		rst_i <= 0;
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		en_i <= 1;
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		init_i <= 1;
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		init_i <= 0;
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		init_i <= 1;
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i);
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i); 
		@(posedge clk_i); @(posedge clk_i); @(posedge clk_i); @(posedge clk_i); 
		$stop;
	end 

endmodule




