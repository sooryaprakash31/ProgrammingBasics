#include <iostream>
using namespace std;
int main()
{
    int *arr;
    int n, key;
    cout << "Enter the length of array ";
    cin >> n;
    cout << "Enter the array elements ";
    for (auto i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the key ";
    cin >> key;
    for (auto i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Found at position " << i + 1;
            break;
        }
        if (i == n - 1)
            cout << "Not Found";
    }
    return 0;
}