

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

#exponential search
def exponential_search(arr, n, key):
    
    #if the key present at 0, returns 0
    if key==arr[0]:
        return 0
    
    #Takes initial value for i as 1
    i=1
    
    #The value of i is incremented until i is lesser than n
    #and element at index i is lesser than or equal to key
    while i<n and arr[i]<=key:
        i = i*2
    
    #The last value of i is the upper bound of the range
    #The lower bound for the range is taken as i/2 (previous i value)
    #binary search() is called for the obtained range
    return binary_search(arr,i//2,min(i,n-1),key)


arr=list(map(int,input("Enter array ").split()))
key=int(input("Enter key "))

#calling exponential_search()
result=exponential_search(arr,len(arr),key)
if result==-1:
    print("Not found")
else:
    print("Key found at position ",result+1)