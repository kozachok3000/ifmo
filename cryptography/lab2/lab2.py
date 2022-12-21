import math 
import random
def textblock(text):
    if len(text)%8 !=0: 
        text=text + " "*(8-len(text)%8)
    return [text[i:i+8] for i in range(0,len(text),8)]

def to_bin(text):
    return "".join([format(ord(c),'08b') for c in text])

def to_text(str):
    text=[chr(int(str[i:i+8],2)) for i in range(0,len(str),8)]
    return "".join(text)

def random_key(seed,K):
    random.seed(seed)
    key = [random.getrandbits(32) for i in range(4)]
    return key
def f(B,K):
    fun7 = pow(2, 64*abs(abs(math.sin(B))*math.log2(abs(math.cos(K)) + 1))) - 1
    fun7 = int(fun7)% int("0xFFFFFFFF",16)
    return fun7
def to_festel(intext,seed,K):
    key=random_key(seed,K)
    bincod=to_bin(intext)
    L=int(bincod[:32],2)
    R=int(bincod[32:],2)
    for i in range(4):
        temp=R
        R=L^f(R, key[i])
        L=temp
    L=format(L,"032b")
    R=format(R,"032b")
    return to_text(R+L)
def from_festel(text,seed,K):
    key=random_key(seed,K)
    key=key[::-1]
    bincod=to_bin(text)
    R=int(bincod[:32],2)
    L=int(bincod[32:],2)
    for i in range(4):
        temp=L
        L=R^f(L,key[i])
        R=temp
    L=format(L,"032b")
    R=format(R,"032b")
    Xor = L+R
    return to_text(Xor)

print("Enter a text:")
text = input()
seed=random.randint(1,255)
text = "".join([to_festel(intext,seed,255)for intext in textblock(text)])
print("Encrypted text:",text)
text="".join(from_festel(text,seed,255))
print("Decrypted text:",text)
