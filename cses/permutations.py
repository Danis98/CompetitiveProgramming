N = int(raw_input())

if N in [2, 3]:
    print("NO SOLUTION")
else:
    s = [str(e) for e in range(2, N+1, 2)] + [str(e) for e in range(1, N+1, 2)]
    print(" ".join(s))
