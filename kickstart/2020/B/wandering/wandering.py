from math import log, exp, inf

MAXN = 100000
fact = [0 for i in range(2*MAXN+1)]
p2 = [0 for i in range(2*MAXN+1)]
for i in range(1, 2*MAXN+1):
    fact[i] = fact[i-1] + log(i)
for i in range(1, 2*MAXN+1):
    p2[i] = p2[i-1] + log(2)

edge_low = []
edge_right = []
W, H = 0, 0

def paths(x, y):
    return fact[x+y-2]-(fact[x-1]+fact[y-1])

def prob(x, y):
    global W, H
    if x < 1 or y < 1:
        return -inf
    if x == H:
        return edge_low[y]
    if y == W:
        return edge_right[x]
    return exp(paths(x, y) - p2[x+y-2])

T = int(input())
for t in range(1, T+1):
    W, H, L, U, R, D = map(int, input().split())

    if (L == 1 and R == W) or (U == 1 and D == H):
        print("Case #%d: 0.0" % t)
        continue

    edge_low = [0 for i in range(W+1)]
    edge_right = [0 for i in range(H+1)]

    for i in range(1, W):
        edge_low[i] = prob(H-1, i)/2+edge_low[i-1]
    for i in range(1, H):
        edge_right[i] = prob(i, W-1)/2+edge_right[i-1]
    edge_low[W] = 1
    edge_right[H] = 1

    # print(H, W)
    # for i in range(1, H+1):
    #     s = ""
    #     for j in range(1, W+1):
    #         s += str(round(exp(prob(i, j)), 6)) + " "
    #     print(s)

    res = 1.0
    if U > 1:
        for i in range(L, R+1):
            if i == W:
                res -= prob(U-1, i)
            else:
                res -= prob(U-1, i)/2
    if L > 1:
        for i in range(U, D+1):
            if i == H:
                res -= prob(i, L-1)
            else:
                res -= prob(i, L-1)/2

    print("Case #%d: %.6f" % (t, abs(res)))