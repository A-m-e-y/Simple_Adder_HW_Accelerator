from hw_fixed_ops import hw_fixed_add_mul

a = 1.5
b = 2.25

sum_result, mul_result = hw_fixed_add_mul(a, b)

print(f"{a} + {b} = {sum_result:.4f} (via HW)")
print(f"{a} * {b} = {mul_result:.4f} (via HW)")
