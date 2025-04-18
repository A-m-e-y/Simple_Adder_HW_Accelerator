from hw_add import hw_add
import time

a = 13
b = 29

# Time profiling for hardware computation
start_time = time.time()
result = hw_add(a, b)
hw_time = time.time() - start_time
print(f"Hardware says: {a} + {b} = {result} (Time taken: {hw_time:.6f} seconds)")

# Time profiling for software computation
start_time = time.time()
result = a + b
sw_time = time.time() - start_time
print(f"Software says: {a} + {b} = {result} (Time taken: {sw_time:.6f} seconds)")

