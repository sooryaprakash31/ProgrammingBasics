/*
Bubble Sort:

- Compares every element with its adjacent element
and swaps if the adjacent element is smaller.
- Simplest sorting algorithm
*/

#include <iostream>
using namespace std;

void swap(int *big, int *small)
{
    int *temp;
    temp = big;
    big = small;
    small = temp;
}

int main()
{
    int *arr;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter array elements: ";
    for (auto i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (auto i = 0; i < n; i++)
    {
        for (auto j = i + 1; j < n; j++)
        {   
            //Swaps if the adjacent element is smaller
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    cout<<"Sorted Array: ";
    for (auto i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}