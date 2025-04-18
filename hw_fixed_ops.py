import os
import subprocess

def hw_fixed_add_mul(a, b):
    env = os.environ.copy()
    env["A"] = str(a)
    env["B"] = str(b)

    subprocess.run(["make"], env=env, check=True)

    with open("fixed_sum.txt") as fsum, open("fixed_mul.txt") as fmul:
        return float(fsum.read().strip()), float(fmul.read().strip())
