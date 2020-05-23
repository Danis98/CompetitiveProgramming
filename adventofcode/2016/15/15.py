def check(n):
    if (n+1+11)%13!=0:
        return False
    if (n+2)%5!=0:
        return False
    if (n+3+11)%17!=0:
        return False
    if (n+4)%3!=0:
        return False
    if (n+5+2)%7!=0:
        return False
    if (n+6+17)%19!=0:
        return False
    if(n+7)%11!=0:
        return False
    return True

for i in range(0, 100000001):
    n=i
    if check(n):
        print n
        break
