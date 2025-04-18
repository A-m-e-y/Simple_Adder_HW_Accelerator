import os
import subprocess
import time

def hw_add(a, b):
    env = os.environ.copy()
    env["A"] = str(a)
    env["B"] = str(b)

    subprocess.run(["make"], env=env, check=True)

    with open("sum_result.txt", "r") as f:
        return int(f.read().strip())
