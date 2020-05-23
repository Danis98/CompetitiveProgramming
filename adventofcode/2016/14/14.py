import md5

N=50000
K=64
salt="ahsbgdzn"

def stretch_hash(clear):
    h=md5.new(clear).digest().encode("hex")
    for i in range(0, 2016):
        h=md5.new(h).digest().encode("hex")
    return h

hashes=[stretch_hash(salt+str(i)) for i in range(0, N)]

cnt=0
ind=0

while cnt<K:
    for i in range(0, len(hashes[ind])-2):
        if hashes[ind][i]==hashes[ind][i+1] and hashes[ind][i]==hashes[ind][i+2]:
            #Potential key, scan next 1000 hashes
            #print hashes[ind]
            found=False
            for n in range(1, 1001):
                if ind+n>=N:
                    break
                for j in range(0, len(hashes[ind])-4):
                    if hashes[ind][i]==hashes[ind+n][j] and hashes[ind+n][j]==hashes[ind+n][j+1] and hashes[ind+n][j]==hashes[ind+n][j+2] and hashes[ind+n][j]==hashes[ind+n][j+3] and hashes[ind+n][j]==hashes[ind+n][j+4]:
                        cnt+=1
                        found=True
                        print str(cnt)+" : ("+str(ind)+","+str(ind+n)+") "+hashes[ind]+" "+hashes[ind+n]
                        break
                if found:
                    break
            break
    if cnt==K:
        print ind
    ind+=1
    if ind==N:
        break
