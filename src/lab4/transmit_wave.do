onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /transmit_testbench/dut/bsc_count
add wave -noupdate /transmit_testbench/dut/busy
add wave -noupdate /transmit_testbench/dut/char_sent_o
add wave -noupdate /transmit_testbench/dut/clk_16_i
add wave -noupdate /transmit_testbench/dut/clk_i
add wave -noupdate /transmit_testbench/dut/load_i
add wave -noupdate /transmit_testbench/dut/para_data_i
add wave -noupdate /transmit_testbench/dut/rst_i
add wave -noupdate /transmit_testbench/dut/serial_data
add wave -noupdate /transmit_testbench/dut/serial_data_o
add wave -noupdate /transmit_testbench/dut/sr_clock
add wave -noupdate /transmit_testbench/dut/trans_en_i
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {4640 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ps
update
WaveRestoreZoom {0 ps} {10416 ps}
