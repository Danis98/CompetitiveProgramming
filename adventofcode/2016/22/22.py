lines=open("input.txt", "r").read().split("\n")

N=26
M=38

nodes=[]

for line in lines:
    words=line.split()
    if len(words)==0:
        continue
    nodes.append((int(words[2][:-1]), int(words[3][:-1])))

# PART 1
cnt=0
for i in range(0, len(nodes)):
    for j in range(0, len(nodes)):
        if i==j:
            continue
        if nodes[i][0]!=0 and nodes[i][0]<nodes[j][1]:
            cnt+=1

print cnt

#PART 2
grid=[[
        (nodes[i*M+j][0], nodes[i*M+j][0]+nodes[i*M+j][1]) for j in range(0, M)
    ]for i in range(0, N)]
