TOPLEVEL_LANG = verilog
VERILOG_SOURCES = $(PWD)/adder.v
TOPLEVEL = adder
MODULE = test_adder
SIM = verilator
WAVES = 0

include $(shell cocotb-config --makefiles)/Makefile.sim
