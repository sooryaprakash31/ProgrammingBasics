def permute(a,l,r,result):
    if l==r:
        print(a)
    else:
        for i in range(l,r):
            a[l],a[i] = a[i],a[l]
            permute(a,l+1,r,result)
            a[l],a[i] = a[i],a[l]

l=list(map(int,input().split()))
result=[]
permute(l,0,len(l),result)
for i in result:
    print(i)