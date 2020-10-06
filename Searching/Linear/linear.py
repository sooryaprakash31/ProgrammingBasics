arr=list(map(int,input("Enter array ").split()))
key = int(input("Enter key "))

for i in range(len(arr)):
    if arr[i] == key:
        print("Found at {} position".format(i+1))
        break
    if i == len(arr)-1:
        print("Not Found")