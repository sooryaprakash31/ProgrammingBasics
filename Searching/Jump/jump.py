'''
Jump Search:

i) Picks a jump value j (square root of length of array - n)
ii) Jumps ahead in every iteration skipping j indices until 
    finds the element greater than the key
iii) Jumps back to the previous jump point and performs linear search

- Requires sorted array
'''

from math import sqrt

def jump_search(arr, key):
    
    #setting jump value
    j = int(sqrt(len(arr)))
    
    prev=0
    step = j

    #runs until the arr[i] is greater than key
    while arr[int(min(step,len(arr))-1)]<key:
        prev=step
        step+=j
        if prev>=len(arr):
            return -1

    # performs linear search for the particular block
    # i.e the previous jump point till the point with
    # element greater than key
    for i in range(prev,step+1):
        if arr[i]==key:
            return i
    return -1

arr=list(map(int,input("Enter array ").split()))
key = int(input("Enter key "))

#calls jump_search
result = jump_search(arr,key)
if result ==-1:
    print("Key not found")
else:
    print("Key found at position",result)