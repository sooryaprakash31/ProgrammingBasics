'''
Binary Search:

Compares the key with the middle element and
i) if the key is greater than middle element,
    compares key with the middle element of the right block
ii) if the key is lesser than middle element,
    compares key with the middle element of the left block
Repeats this process recursively

- Requires sorted array
'''

#binary search method
def binary_search(arr,l,h,key):
    
    #Always l must be less than h, 
    #otherwise leads to out of bounds error
    if l<=h:
        
        #calculating middle element of the array
        mid=(l+h)//2

        #if key is equal to mid, return mid
        if key==arr[mid]:
            return mid

        #calls binary_search for left block, if key is lesser
        elif key<arr[mid]:
            return binary_search(arr,l,mid,key)
        
        #calls binary_search for right block, if key is greater
        else:
            return binary_search(arr,mid+1,h,key)

    #if l is greater than h, it means all elements have been compared with key
    else:
        return -1

arr=list(map(int,input("Enter array ").split()))
key=int(input("Enter key "))

#calling binary_search function
result=binary_search(arr,0,len(arr)-1,key)
if result==-1:
    print("Not found")
else:
    print("Key found at position ",result+1)