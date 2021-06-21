T = int(raw_input())

for _ in range(T):
    x, y = map(int, raw_input().split())
    m = max(x, y)
    v = 1 + m * (m - 1)
    r = v + (y - x) * (1 if m % 2 == 1 else -1)
    print(r)
