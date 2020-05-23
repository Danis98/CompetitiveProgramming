str=open("input.txt", "r").read()
instr=str.split(", ")

mem={
    (0, 0): 1
}

dir=0
x=0
y=0

for i in instr:
    doff=1 if i[0]=='R' else -1
    dir=(dir+doff)%4
    off=int(i[1:])
    if dir==0:
        dx=0
        dy=1
        for k in range(0, off):
            x+=dx
            y+=dy
            if (x, y) in mem:
                print abs(x)+abs(y)
            mem[(x, y)]=1
    elif dir==1:
        dx=1
        dy=0
        for k in range(0, off):
            x+=dx
            y+=dy
            if (x, y) in mem:
                print abs(x)+abs(y)
            mem[(x, y)]=1
    elif dir==2:
        dx=0
        dy=-1
        for k in range(0, off):
            x+=dx
            y+=dy
            if (x, y) in mem:
                print abs(x)+abs(y)
            mem[(x, y)]=1
    elif dir==3:
        dx=-1
        dy=0
        for k in range(0, off):
            x+=dx
            y+=dy
            if (x, y) in mem:
                print abs(x)+abs(y)
            mem[(x, y)]=1

print abs(x)+abs(y)
