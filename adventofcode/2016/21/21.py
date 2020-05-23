instrs=open("input.txt", "r").read().split("\n")

S=list("fbgdceah")

instrs.reverse()

for instr in instrs:
    words=instr.split(" ")
    if words[0]=='rotate':
        if words[1]=='based':
            lett=words[6]
            off=0
            for i in range(0, len(S)):
                #check if lett can be at i
                o=i+(2 if i>=4 else 1)
                if (i+o)%len(S)==S.index(lett):
                    off=o
                    break
            while off>len(S):
                off-=len(S)
            S=S[off:]+S[:off]
            continue
        off=int(words[2])
        if words[1]=='right':
            S=S[off:]+S[:off]
        elif words[1]=='left':
            S=S[-off:]+S[:-off]
    elif words[0]=='swap':
        if words[1]=='position':
            temp=S[int(words[2])]
            S[int(words[2])]=S[int(words[5])]
            S[int(words[5])]=temp
        elif words[1]=='letter':
            x=words[2]
            y=words[5]
            for i in range(0, len(S)):
                if S[i]==x:
                    S[i]=y
                elif S[i]==y:
                    S[i]=x
    elif words[0]=='reverse':
        x=int(words[2])
        y=int(words[4])
        l=[]
        for i in range(x, y+1):
            l.append(S[y-i+x])
        for i in range(x, y+1):
            S[i]=l[i-x]
    elif words[0]=='move':
        x=int(words[5])
        y=int(words[2])
        if x<y:
            temp=S[x]
            for i in range(x, y):
                S[i]=S[i+1]
            S[y]=temp
        else:
            temp=S[x]
            for i in range(x, y, -1):
                S[i]=S[i-1]
            S[y]=temp
#    print "".join(S)

print "".join(S)
