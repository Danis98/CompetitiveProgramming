N = int(input())

s = ""
while True:
    s += "%d " % N
    if N == 1:
        break
    N = N // 2 if N % 2 == 0 else 3 * N + 1

print(s)
