import cocotb
from cocotb.triggers import RisingEdge
from cocotb.clock import Clock
import os

@cocotb.test()
async def test_adder(dut):

    a = int(os.environ["A"])
    b = int(os.environ["B"])

    dut.a.value = a
    dut.b.value = b
    
    await cocotb.triggers.Timer(1, units="ns")  # allow combinational logic to settle

    result = dut.sum.value.integer
    with open("sum_result.txt", "w") as f:
        f.write(str(result))
