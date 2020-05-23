import sys

H=6
W=50

disp=[[0 for i in range(0, W)] for j in range(0, H)]

instr=open("input.txt", "r").read()
lines=instr.split("\n")

for line in lines:
    words=line.split(" ")
    if words[0]=="rect":
        coords=words[1].split("x")
        for i in range(0, int(coords[1])):
            for j in range(0, int(coords[0])):
                disp[i][j]=1
    elif words[0]=="rotate" and words[1]=="row":
        ind=int(words[2][2:])
        rot=int(words[4])
        arr=[0 for i in range(0, W)]
        for i in range(0, W):
            arr[i]=disp[ind][(i-rot+W)%W]
        disp[ind]=arr
    elif words[0]=="rotate" and words[1]=="column":
        ind=int(words[2][2:])
        rot=int(words[4])
        arr=[0 for i in range(0, H)]
        for i in range(0, H):
            arr[i]=disp[(i-rot+H)%H][ind]
        for i in range(0, H):
            disp[i][ind]=arr[i]
    for i in range(0, H):
        for j in range(0, W):
            sys.stdout.write('#' if disp[i][j]==1 else '.')
        print ""
    print ""


cnt=0
for i in range(0, H):
    for j in range(0, W):
        cnt+=disp[i][j]
print cnt
