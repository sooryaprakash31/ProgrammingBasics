def permute(arr):

    #return [] if there is no element
    if len(arr)==0:
        return []

    #return the list if there is only one element
    if len(arr)==1:
        return [arr]

    #declare temp list
    temp = []

    for i in range(len(arr)):

        #take arr[i] as fixed element
        fixed = arr[i]

        #store the remaining elements in arrRem
        arrRem = arr[:i] + arr[i+1:]

        #run permute for the remaining list recursively
        for j in permute(arrRem): 
            
            #Append the fixed element at the first index and the permutations for 
            #remaining elements (obtained recursively)
            temp.append([fixed]+j)
    
    return temp


result = permute([1,2,3])
for i in result:
    print(i)
