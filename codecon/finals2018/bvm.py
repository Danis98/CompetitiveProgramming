import sys

N = int(sys.stdin.readline())
instrs = []
for i in range(0, N):
    instrs.append(sys.stdin.readline())

regs={
    'a': 0,
    'b': 0,
    'c': 0,
    'd': 0,
    'e': 0,
    'f': 0,
    'g': 0,
    'h': 0
}

def get_val(name):
    if name>='a' and name<='h':
        return regs[name]
    else:
        return int(name)

ip=0
while ip>=0 and ip<len(instrs):
    instr=instrs[ip]
    ops = instr.split()
    if ops[0] == 'set':
        regs[ops[1]]=get_val(ops[2])
        ip+=1
    elif ops[0] == 'add':
        regs[ops[1]]+=get_val(ops[2])
        ip+=1
    elif ops[0] == 'sub':
        regs[ops[1]]-=get_val(ops[2])
        ip+=1
    elif ops[0] == 'mul':
        regs[ops[1]]*=get_val(ops[2])
        ip+=1
    elif ops[0] == 'mod':
        regs[ops[1]]%=get_val(ops[2])
        ip+=1
    elif ops[0] == 'div':
        regs[ops[1]]=int(regs[ops[1]]/get_val(ops[2]))
        ip+=1
    elif ops[0] == 'jmp':
        ip+=get_val(ops[1])
        if get_val(ops[1])==0:
            ip+=1
    elif ops[0] == 'ret':
        print get_val(ops[1])
        break
