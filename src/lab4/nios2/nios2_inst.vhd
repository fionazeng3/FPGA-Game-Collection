	component nios2 is
		port (
			businput_external_connection_export   : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			busouput_external_connection_export   : out std_logic_vector(7 downto 0);                    -- export
			charrec_external_connection_export    : in  std_logic                    := 'X';             -- export
			charsent_external_connection_export   : in  std_logic                    := 'X';             -- export
			clk_clk                               : in  std_logic                    := 'X';             -- clk
			led_pio_external_connection_export    : out std_logic_vector(7 downto 0);                    -- export
			loadi_external_connection_export      : out std_logic;                                       -- export
			reset_reset_n                         : in  std_logic                    := 'X';             -- reset_n
			switches07_external_connection_export : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			transen_external_connection_export    : out std_logic                                        -- export
		);
	end component nios2;

	u0 : component nios2
		port map (
			businput_external_connection_export   => CONNECTED_TO_businput_external_connection_export,   --   businput_external_connection.export
			busouput_external_connection_export   => CONNECTED_TO_busouput_external_connection_export,   --   busouput_external_connection.export
			charrec_external_connection_export    => CONNECTED_TO_charrec_external_connection_export,    --    charrec_external_connection.export
			charsent_external_connection_export   => CONNECTED_TO_charsent_external_connection_export,   --   charsent_external_connection.export
			clk_clk                               => CONNECTED_TO_clk_clk,                               --                            clk.clk
			led_pio_external_connection_export    => CONNECTED_TO_led_pio_external_connection_export,    --    led_pio_external_connection.export
			loadi_external_connection_export      => CONNECTED_TO_loadi_external_connection_export,      --      loadi_external_connection.export
			reset_reset_n                         => CONNECTED_TO_reset_reset_n,                         --                          reset.reset_n
			switches07_external_connection_export => CONNECTED_TO_switches07_external_connection_export, -- switches07_external_connection.export
			transen_external_connection_export    => CONNECTED_TO_transen_external_connection_export     --    transen_external_connection.export
		);

