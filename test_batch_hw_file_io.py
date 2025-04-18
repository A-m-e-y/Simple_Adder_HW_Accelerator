import cocotb
from cocotb.triggers import RisingEdge
from cocotb.clock import Clock

WIDTH = 16
FRAC = 8
MAX_N = 1024

def float_to_fixed(val):
    return int(round(val * (1 << FRAC))) & 0xFFFF

def fixed_to_float(val):
    if val & 0x8000:
        val -= 0x10000
    return val / float(1 << FRAC)

@cocotb.test()
async def test_batch_hw_file_io(dut):
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    await RisingEdge(dut.clk)

    a_vals = []
    b_vals = []
    with open("input_buffer.txt", "r") as f:
        for line in f:
            a_str, b_str = line.strip().split()
            a_vals.append(float_to_fixed(float(a_str)))
            b_vals.append(float_to_fixed(float(b_str)))

    N = len(a_vals)
    assert N <= MAX_N

    # Flatten
    a_flat = 0
    b_flat = 0
    for i in range(N):
        a_flat |= a_vals[i] << (i * WIDTH)
        b_flat |= b_vals[i] << (i * WIDTH)

    dut.a_in_flat.value = a_flat
    dut.b_in_flat.value = b_flat
    dut.burst_len.value = N

    dut.rst.value = 1
    dut.start.value = 0
    await RisingEdge(dut.clk)
    dut.rst.value = 0

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0

    while not dut.done.value:
        await RisingEdge(dut.clk)

    sum_out = []
    prod_out = []
    flat_sum = dut.sum_out_flat.value.integer
    flat_mul = dut.product_out_flat.value.integer

    for i in range(N):
        s = (flat_sum >> (i * WIDTH)) & 0xFFFF
        m = (flat_mul >> (i * WIDTH)) & 0xFFFF
        sum_out.append(fixed_to_float(s))
        prod_out.append(fixed_to_float(m))

    with open("output_buffer.txt", "w") as f:
        for s, m in zip(sum_out, prod_out):
            f.write(f"{s:.4f} {m:.4f}\n")
