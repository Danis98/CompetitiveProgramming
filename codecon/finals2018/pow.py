#Problem        : The Cryptocurrency Miner
#Language       : Python
#Compiled Using : py_compile
#Version        : Python 2.7.8
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

import sys

data = sys.stdin.readline()

tx = data.split()[0]
N = int(data.split()[1])
S = data.split()[2]

def hash(tx, S, nonce):
    tx=str(int(tx)+nonce)
    res=""
    for i in xrange(0, len(tx)):
        if tx[i]!="0" and S[i%len(S)]!="0":
            res+=str(int(tx[i])%int(S[i%len(S)]))
        elif tx[i]=="0":
            res+=S[i%len(S)]
        elif S[i%len(S)]=="0":
            res+=tx[i]
    return res

n = 0
while not hash(tx, S, n).startswith("0"*N):
    n+=1
print n
