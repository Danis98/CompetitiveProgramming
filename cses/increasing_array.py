N = int(raw_input())
A = list(map(int, raw_input().split(" ")))

moves = 0
h = A[0]
for i in range(1, N):
    moves += max(0, h - A[i])
    h = max(h, A[i])

print(moves)
