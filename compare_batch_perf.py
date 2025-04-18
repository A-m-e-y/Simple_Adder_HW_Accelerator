from hw_batch import hw_batch_add_mul
import time
import random

def generate_q88_quarters(n, max_product=127.0):
    a_vals = []
    b_vals = []
    for _ in range(n):
        # Generate a value like 0.25, 0.5, 0.75, 1.0, ..., safely
        a = random.randint(1, int(max_product / 0.25)) * 0.25
        max_b = max_product / a
        b = random.randint(1, int(min(max_b, 127.0) / 0.25)) * 0.25
        a_vals.append(round(a, 2))
        b_vals.append(round(b, 2))
    return a_vals, b_vals

# Fixed-point precision tolerance
EPSILON = 0.01

N = 100  # Set this to 10, 100, 1000 etc

a_vals, b_vals = generate_q88_quarters(N)

print(f"\n🔢 Comparing Software vs Hardware Results for {N} Fixed-Point Values\n")

# Software implementation
sw_start = time.time()
sw_sum = [a + b for a, b in zip(a_vals, b_vals)]
sw_mul = [a * b for a, b in zip(a_vals, b_vals)]
sw_time = (time.time() - sw_start) * 1000  # ms

# Hardware call
hw_sum, hw_mul, hw_time = hw_batch_add_mul(a_vals, b_vals)

# Print table header
print("{:^5} {:^8} {:^8} | {:^10} {:^10} | {:^10} {:^10} | {:^6} {:^6}".format(
    "Idx", "A", "B", "SW Add", "HW Add", "SW Mul", "HW Mul", "Add OK", "Mul OK"
))
print("-" * 90)

# Compare and print
all_add_ok = True
all_mul_ok = True

for i in range(len(a_vals)):
    a = a_vals[i]
    b = b_vals[i]
    s_sw = sw_sum[i]
    s_hw = hw_sum[i]
    m_sw = sw_mul[i]
    m_hw = hw_mul[i]

    add_match = abs(s_sw - s_hw) < EPSILON
    mul_match = abs(m_sw - m_hw) < EPSILON

    if not add_match:
        all_add_ok = False
    if not mul_match:
        all_mul_ok = False

    print("{:<5} {:<8.2f} {:<8.2f} | {:<10.4f} {:<10.4f} | {:<10.4f} {:<10.4f} | {:^6} {:^6}".format(
        i, a, b, s_sw, s_hw, m_sw, m_hw,
        "✓" if add_match else "✗",
        "✓" if mul_match else "✗"
    ))

print("\n⏱️  Software time: {:.2f} ms".format(sw_time))
print("⏱️  Hardware time: {:.2f} ms".format(hw_time))

if all_add_ok and all_mul_ok:
    print("\n✅ All results match! HW == SW ✅\n")
else:
    print("\n❌ Mismatch found between HW and SW results ❌\n")
