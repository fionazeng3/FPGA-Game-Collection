module start_detect
	(input	logic	clk_i
	,input	logic	rst_i
	,input	logic	data_i
	,output	logic	init_o
	,output	logic	recv_en_o
	);
	
	logic[4:0] counter;
	logic state_r, state_n;
	parameter IDLE = 1'b0;
	parameter LOADING = 1'b1;
	
	
	always_ff @(posedge clk_i or posedge rst_i) begin
		if (rst_i) begin
			state_r <= IDLE;
		end else begin
			state_r <= state_n;
		end
	end
	
	logic count_rst, count_en;
	
	always_comb begin
		case (state_r)
			IDLE: begin
				state_n = IDLE;
				count_rst = 1;
				count_en = 0;
				recv_en_o = 0;
				if (~data_i) begin
					state_n = LOADING;
					count_rst = 0;
					count_en = 1;
					recv_en_o = 1;
				end
			end
			
			LOADING: begin
				state_n = LOADING;
				count_rst = 0;
				count_en = 1;
				recv_en_o = 1;
				if (counter == 5'b0) begin
					state_n = IDLE;
					count_rst = 1;
					count_en = 0;
					recv_en_o = 0;
				end
			end
			
			default: begin
				state_n = IDLE;
				count_rst = 1;
				count_en = 0;
				recv_en_o = 0;
			end
		endcase
	end

	assign init_o = (state_r == IDLE) & (state_n == LOADING);

	always_ff @(posedge clk_i or posedge rst_i) begin
		if (rst_i) begin
			counter <= 5'b10000;
		end else if (count_rst) begin
			counter <= 5'b10000;
		end else if (count_en) begin
			counter <= counter - 1'b1;
		end else begin
			counter <= counter;
		end
	end
	
endmodule
