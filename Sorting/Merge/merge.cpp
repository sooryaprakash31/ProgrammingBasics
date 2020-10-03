/*
Merge Sort:

- Divides the set of elements(array) into two blocks recursively and 
sorts them one by one by comparing elements from left and right block
- Divide and conquer strategy
*/


#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    //Start of left block
    int left = l;
    //Start of right block
    int right = mid + 1;
    //Temporary array
    int temp[r];
    //Index for temporary array
    int index = l;
    
    while (left <= mid && right <= r)
    {
        //if left block element is smaller than right block element 
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            left++;
            index++;
        }
        //if right block element is smaller than left block element 
        else
        {
            temp[index] = arr[right];
            right++;
            index++;
        }
    }

    //Copying the left out elements in left block to temp array
    while (left <= mid)
    {
        temp[index] = arr[left];
        left++;
        index++;
    }
    //Copying the left out elements in right block to temp array
    while (right <= r)
    {
        temp[index] = arr[right];
        right++;
        index++;
    }
    //Storing temp elements to main array in sorted order
    for (int s = l; s <= r; s++)
    {
        arr[s] = temp[s];
    }
}

//Calls itself recursively until the block reduces to one element
void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        //Left block
        merge_sort(arr, l, mid);
        //Right block
        merge_sort(arr, mid + 1, r);

        //Merging blocks in sorted order
        merge(arr, l, mid, r);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int myarr[n];
    cout << "Enter "<<n<<" elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> myarr[i];
    }
    cout << "\nBefore sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << myarr[i]<<" ";
    }
    merge_sort(myarr, 0, n - 1);
    cout << "\nAfter Merge sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << myarr[i]<<" ";
    }
    return 0;
}