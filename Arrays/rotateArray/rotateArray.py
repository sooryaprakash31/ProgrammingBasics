'''
Given a set of space separated integers, this program rotates
the array based on the rotation value.

The array {1,2,3,4,5,6} with rotation value 2 will result in
{3,4,5,6,1,2}
'''


def rotateArray(size,rotation):
    arr = input().split()
    #printing from rotation to end and then from start to rotation
    final = arr[rotation:size]
    final = final + arr[:rotation]
    print(" ".join(final))

test_cases = int(input())
for _ in range(test_cases):
    size,rotation = map(int,input().split())
    rotateArray(size,rotation)
