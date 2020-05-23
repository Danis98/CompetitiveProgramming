import md5

doorID="ugkcyxxp"

psw=["" for i in range(0, 8)]
i=0
cnt=0

while cnt<8:
    s=doorID+str(i)
    h=md5.new(s).digest().encode("hex")
    if h.startswith("00000"):
        if h[5]>='0' and h[5]<='9' and int(h[5])<8 and psw[int(h[5])]=="":
            psw[int(h[5])]=h[6]
            print h[5]
            print h[6]
            print psw
            cnt+=1
    i+=1
print psw
