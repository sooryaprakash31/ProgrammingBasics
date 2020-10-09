'''
Quick Sort:

- Picks a pivot element (can be the first/last/random element) from the array
and places it in the sorted position such that the elements before the pivot
are lesser and elements after pivot are greater.
- Repeats this until all the elements are placed in the right position
- Divide and conquer strategy

Example:
arr=[3,6,4,5,9]

Takes pivot as arr[2] (i.e (first_index+last_index)/2)
pivot is 4. 

After 1st partition
arr=[3,4,6,5,9]
i) The elements before pivot are lesser then pivot and
    the elements after pivot are greater than pivot

- quick_sort method calls itself for left and right blocks having
partition as the midpoint until all the elements are sorted.

'''

def partition(arr, left,right,pivot):
    #left should always less than or equal to right
    #otherwise it will lead to out of bounds error
    while left<=right:

        #finds the first element that is greater than pivot
        #from the start 
        while arr[left]<pivot:
            left=left+1
        
        #finds the first element that is lesser than pivot
        #from the end
        while arr[right]>pivot:
            right=right-1

        #swapping the elements at indices left and right
        if left<=right:
            arr[left],arr[right]=arr[right],arr[left]
            left=left+1
            right=right-1

    #returning the current index of the pivot element
    return left

def quick_sort(arr,left,right):

    #checks if the block contains atleast two elements
    if left<right:

        #Middle element is chosen as the pivot
        pivot=arr[(left+right)//2]

        #gives the sorted pivot index
        p = partition(arr,left,right,pivot)

        #calls quick_sort for elements left to the partition
        quick_sort(arr,left,p-1)
        #calls quick_sort for elements right to the partition
        quick_sort(arr,p,right)


arr=list(map(int,input("Enter array ").split()))
print("Before sort:",*arr)

#calling sort function
quick_sort(arr,0,len(arr)-1)

print("Sorted array:",*arr)