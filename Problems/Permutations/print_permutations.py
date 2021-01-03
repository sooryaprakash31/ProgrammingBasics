def permute(a,l,r,result):

    # print a if l is equal to r
    if l==r:
        print(a)

    else:

        #loop from l to r
        for i in range(l,r):

            #swap first index with element at i
            a[l],a[i] = a[i],a[l]

            #run permute for remining values keeping element at l as fixed
            permute(a,l+1,r,result)

            #backtracking
            a[l],a[i] = a[i],a[l]


l=list(map(int,input().split()))
permute(l,0,len(l))
