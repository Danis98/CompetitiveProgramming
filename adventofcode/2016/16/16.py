fin=open("input.txt", "r").read()
N=int(fin.split("\n")[0])
S=fin.split("\n")[1]

while(len(S)<N):
    b=""
    for i in range(0, len(S)):
        b+='0' if S[len(S)-1-i]=='1' else '1'
    S+='0'
    S+=b

S=S[:N]
print S

while len(S)%2==0:
    b=""
    for i in range(0, len(S), 2):
        if S[i]==S[i+1]:
            b+='1'
        else:
            b+='0'
    S=b
print S
