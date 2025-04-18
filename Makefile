# TOPLEVEL_LANG = verilog
# VERILOG_SOURCES = $(PWD)/adder.v
# TOPLEVEL = adder
# MODULE = test_adder
# SIM = verilator
# WAVES = 0
# 
# include $(shell cocotb-config --makefiles)/Makefile.sim

TOPLEVEL_LANG = verilog
VERILOG_SOURCES = $(PWD)/hw_top.v $(PWD)/fixed_adder.v $(PWD)/fixed_multiplier.v
TOPLEVEL = hw_top
MODULE = test_batch_hw_file_io

SIM = verilator
WAVES = 0

include $(shell cocotb-config --makefiles)/Makefile.sim
