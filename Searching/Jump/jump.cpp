/*
Jump Search:

i) Picks a jump value j (square root of length of array - n)
ii) Jumps ahead in every iteration skipping j indices until 
    finds the element greater than the key
iii) Jumps back to the previous jump point and performs linear search
*/

#include <iostream>
#include <math.h>
using namespace std;

int jump_search(int arr[], int n, int key)
{

    //setting jump value
    int jump = sqrt(n);
    int i = 0, j = 0;
    while (i < n)
    {

        //if the element is lesser than key, jump j steps
        if (arr[i] < key)
        {
            i += jump;
            continue;
        }

        //if element is greater than key, jump back j steps
        else if (arr[i] > key)
        {
            i = i - jump;
            break;
        }

        //if element is equal to key, return i
        else
        {
            return i;
        }
    }

    //perform linear search from the closer jump point
    for (int j = i; j < i + jump; j++)
    {
        if (arr[j] == key)
        {
            return j;
        }
    }
    return -1;
}

int main()
{

    int n, key, result;
    cout << "Enter the length of array ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements ";
    for (auto i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the key ";
    cin >> key;

    //calling jump_search method
    result = jump_search(arr, n, key);
    if (result == -1)
    {
        cout << "\nKey not found";
    }
    else
    {
        cout << "Key found at position " << result + 1;
    }

    return 0;
}