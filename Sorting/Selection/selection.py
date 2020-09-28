#selection sort
'''
Selects the minimum element from the unsorted array everytime 
and inserts it in the beginning
'''
arr=list(map(int,input("Enter array ").split()))
for i in range(len(arr)):
    min = i
    for j in range(i+1,len(arr)):
        if arr[min]>arr[j]:
            # element at j is the minimum element in this iteration
            min = j
    # Swapping minimum element with the element at first
    arr[i],arr[min]=arr[min],arr[i]
print("Sorted array", arr)
