import md5
import Queue

passw="pxxbnzuo"

maxlen=0

Q=Queue.Queue()
Q.put((0, (0, 0), passw))
while not Q.empty():
    state=Q.get()
    d=state[0]
    coord=state[1]
    string=state[2]
    if coord==(3, 3):
        maxlen=len(string[len(passw):]) if len(string[len(passw):])>maxlen else maxlen
        print maxlen
        continue
    h=md5.new(string).digest().encode("hex")
    if coord[0]>0 and ord(h[0])>ord('a'):
        Q.put((d+1, (coord[0]-1, coord[1]), string+'U'))
    if coord[0]<3 and ord(h[1])>ord('a'):
        Q.put((d+1, (coord[0]+1, coord[1]), string+'D'))
    if coord[1]>0 and ord(h[2])>ord('a'):
        Q.put((d+1, (coord[0], coord[1]-1), string+'L'))
    if coord[1]<3 and ord(h[3])>ord('a'):
        Q.put((d+1, (coord[0], coord[1]+1), string+'R'))

print maxlen
