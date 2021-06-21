S = raw_input().strip()

start = 0
score = 0

for i in range(1, len(S)):
    if S[i] != S[start]:
        score = max(score, i - start)
        start = i

score = max(score, len(S) - start)

print(score)