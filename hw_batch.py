import time
import subprocess

def hw_batch_add_mul(a_list, b_list):
    assert len(a_list) == len(b_list)
    with open("input_buffer.txt", "w") as f:
        for a, b in zip(a_list, b_list):
            f.write(f"{a} {b}\n")

    start = time.time()
    subprocess.run(["make"], check=True)
    elapsed = (time.time() - start) * 1000

    sum_out, mul_out = [], []
    with open("output_buffer.txt", "r") as f:
        for line in f:
            s, m = map(float, line.strip().split())
            sum_out.append(s)
            mul_out.append(m)

    return sum_out, mul_out, elapsed
