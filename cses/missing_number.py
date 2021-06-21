N = int(raw_input())
A = list(map(int, raw_input().split(" ")))

A = sorted(A)

if A[0] != 1:
    print(1)
else:
    a, b = 0, N-2
    while a < b:
        mid = (a + b + 1) // 2
        if A[mid] != mid + 1:
            b = mid - 1
        else:
            a = mid

    print(a + 2)
