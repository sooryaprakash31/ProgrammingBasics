'''
Interpolation Search:

Uses the position formula to obtain the closest index to the key
and searches the key using that index

pos = low + ( (key - arr[low]) * (high - low) / (arr[high]-arr[low]) )
- Requires sorted array

Special case:
    If the array is uniformly distributed, 
    it requires just one step to find the position of key
        - An array is uniformly distributed if the difference between any 
          two consecutive elements is constant
          Example:
          arr = [3,5,7,9,11,13]
'''


def interpolation_search(arr,l,h,key):
    
    #Always l<=h otherwise it leads to out of bounds error
    while l<=h:

        #calculates the pos using the formula
        pos = l+int((key-arr[l])*(h-l)/(arr[h]-arr[l]))
        
        #if pos is not within the end points then return
        if pos>h or pos<l:
            return -1
        
        #if key is lesser than element at pos,
        #then calls interpolation search for left block 
        if key<arr[pos]:
            return interpolation_search(arr,l,pos-1,key)
        
        #if key is greater than element at pos,
        #then calls interpolation search for right block 
        elif key>arr[pos]:
            return interpolation_search(arr,pos+1,h,key)
        
        #if key is equal to element at pos, return pos
        else:
            return pos
    
    #returns -1 if key is not in the array
    return -1    

def interpolation_uniform_search(arr,l,h,key):

    pos = l+int((key-arr[l])*(h-l)/(arr[h]-arr[l]))
    if arr[pos]==key:
        return pos
    return -1

arr=list(map(int,input("Enter array ").split()))
key = int(input("Enter key "))
#calls interpolation_search
result = interpolation_search(arr, 0, len(arr)-1,key)

#calls interpolation_uniform_search if the array is uniformly distributed
#result=interpolation_uniform_search(arr,0,len(arr)-1,key)

if result ==-1:
    print("Key not found")
else:
    print("Key found at position",result+1)
