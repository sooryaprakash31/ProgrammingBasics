/*
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
*/

#include <iostream>
using namespace std;

int main()
{
    int *arr;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the array: ";
    for (auto i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // looping from 1 to start from second element
    for (auto i = 1; i < n; i++)
    {
        // storing the check point value in key
        int key = arr[i];

        /* In the while loop below, the elements are traversed in reverse
        so i-1 (previous element of the check point) */
        int j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            // moving elements to right until we find the right position to insert key
            arr[j + 1] = arr[j];
            j--;
        }
        // inserting key at right position
        arr[j + 1] = key;
    }
    cout << "Sorted Array: ";
    for (auto i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}