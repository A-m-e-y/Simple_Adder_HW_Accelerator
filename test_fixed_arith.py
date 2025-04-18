import cocotb
import os
from cocotb.triggers import Timer

def float_to_fixed(val):
    return int(val * 256) & 0xFFFF

def fixed_to_float(val):
    if val & 0x8000:
        val -= 0x10000
    return val / 256.0

@cocotb.test()
async def test_fixed_arith(dut):
    a = float_to_fixed(float(os.environ["A"]))
    b = float_to_fixed(float(os.environ["B"]))

    dut.a.value = a
    dut.b.value = b

    await Timer(1, units="ns")

    sum_out = fixed_to_float(dut.sum.value.integer)
    mul_out = fixed_to_float(dut.product.value.integer)

    with open("fixed_sum.txt", "w") as f:
        f.write(str(sum_out))

    with open("fixed_mul.txt", "w") as f:
        f.write(str(mul_out))
