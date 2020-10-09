'''
Insertion Sort

Takes an element and compares it with its previous elements
and inserts it at the correct position while moving other elements
to the right

Example:
arr = [6,4,3,1]

i) Takes 4. Compares it with 6. Moves 6 to the right and 
    inserts 4 at index 0.
    arr= [4,6,3,1]
ii) Now Takes 3 (not 6) because the check point moves right.
'''

arr=list(map(int,input("Enter array ").split()))

# looping from 1 to start from second element
for i in range(1,len(arr)):
    
    # storing the check point value in key
    key = arr[i]

    # In the while loop below, the elements are traversed in reverse
    # so i-1 (previous element of the check point)
    j=i-1
    
    while j>=0 and key<arr[j]:
        
        # moving elements to right until we find the right position to insert key
        arr[j+1]=arr[j]
        j=j-1
    
    # inserting key at right position
    arr[j+1]=key

print("Sorted Array:", *arr)