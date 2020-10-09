'''
Merge Sort:

- Divides the set of elements(array) into two blocks recursively and 
sorts them one by one by comparing elements from left and right block
- divide and conquer strategy
'''

def merge_sort(arr):
    #checks if the array contains atleast two elements
    if len(arr)>1:
        mid = len(arr)//2
        left = arr[:mid]
        right=arr[mid:]
        #calls merge_sort function for left block
        left=merge_sort(left)
        #calls merge_sort function for right block
        right=merge_sort(right)

        #clears the array
        arr=[]
        while len(left)>0 and len(right)>0:
            
            #checks if first element in left block is 
            #smaller than first element in right block
            if left[0]<right[0]:
                arr.append(left[0])
                #pops the first element after inserting it to result array
                left.pop(0)
            
            else:
                arr.append(right[0])
                right.pop(0)

        #copies the left out elements from both left and right blocks
        for i in left:
            arr.append(i)
        for i in right:
            arr.append(i)
    return arr

arr=list(map(int,input("Enter array ").split()))
print("Before sort:",*arr)
#calling sort function
result=merge_sort(arr)
print("Sorted array:",*result)