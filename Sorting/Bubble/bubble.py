'''
Bubble Sort:

- Compares every element with its adjacent element
and swaps if the adjacent element is smaller.
- Simplest sorting algorithm
'''

arr=list(map(int,input("Enter Array ").split()))

for i in range(len(arr)):
    for j in range(i+1,len(arr)):
        #swaps if the adjacent element is smaller
        if arr[i]>arr[j]:
            arr[i],arr[j]=arr[j],arr[i]

print("Sorted Array",arr)
