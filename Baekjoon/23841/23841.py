n,m=map(int,input().split(" "))

for _ in range(0,n):
    c=input()
    b=[]
    for i in range(0,m//2):
        if c[m-1-i] != '.':
            b.append(c[m-1-i])
        else:
            b.append(c[i])
    
    for i in range(0,m//2):
        print(b[i], end="")
    for j in range((m//2)-1, -1, -1):
        print(b[j], end="")
    print("")