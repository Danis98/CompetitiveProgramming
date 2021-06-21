K = int(raw_input())

precalc = [0, 6, 28, 96]
for k in range(1, K+1):
    if k < 5:
        print(precalc[k-1])
        continue
    res = 0
    tot = k ** 2
    res += 4 * (tot - 3) # 0, 0
    res += 8 * (tot - 4) # 0, 1
    res += 4 * (tot - 5) # 1, 1
    res += (4 * (k - 3) - 4) * (tot - 7) # 1, x
    res += (4 * (k - 3) - 4) * (tot - 5) # 0, x
    res += (k - 4) ** 2 * (tot - 9) # x, x
    res //= 2
    print(res)