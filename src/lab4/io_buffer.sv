module io_buffer
	(input	logic	clk_i
	,input	logic	rst_i
	,input	logic	data_i
	,output	logic	data_o
	);
	
	logic data_r;
	assign data_o = data_r;
	
	always_ff @(posedge clk_i or posedge rst_i)	begin
		if (rst_i) begin
			data_r <= 1'b1;
		end else begin
			data_r <= data_i;
		end
	end
endmodule