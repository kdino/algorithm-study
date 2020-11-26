nums = list(map(int, list(input())))

total = 0

for i in nums:
    if total == 0:
        total += i
        continue
    if i == 0 or i == 1: total += i
    else: total *= i

print(total)