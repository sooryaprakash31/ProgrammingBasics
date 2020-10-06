/*
Jump Search:

i) Picks a jump value j (square root of length of array - n)
ii) Jumps ahead in every iteration skipping j indices until 
    finds the element greater than the key
iii) Jumps back to the previous jump point and performs linear search
*/

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int jump_search(int arr[], int n, int key)
{
    //setting jump value
    int j = sqrt(n);
    int i = 0;
    int prev=0, step=j;
    
    //runs until the arr[i] is greater than key
    while(arr[min(step,n)-1]<key){
        prev=step;
        step+=j;
        if(prev>=n){
            return -1;
        }
    }

    //performs linear search for the particular block
    //i.e the previous jump point till the point with
    //element greater than key
    for(i=prev;i<=step;i++){
        if(arr[i]==key){
            return i;
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