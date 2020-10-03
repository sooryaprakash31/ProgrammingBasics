/*
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

*/

#include<iostream>
using namespace std;
 
void swap(int *num1,int *num2){
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}

int partition(int arr[],int left, int right, int pivot){
    //left should always less than or equal to right
    //otherwise it will lead to out of bounds error
    while(left<=right){
        
        //finds the first element that is greater than pivot
        //from the start 
        while(arr[left]<pivot){
            left++;
        }

        //finds the first element that is lesser than pivot
        //from the end
        while(arr[right]>pivot){
            right--;
        }

        //swapping the elements at indices left and right
        if(left<=right){
            swap(&arr[left],&arr[right]);
            left++;
            right--;
        }
    }

    //returning the current index of the pivot element
    return left;
}

void quick_sort(int arr[], int left, int right){
    
    //checks if the block contains atleast two elements
    if(left<right){
        //Middle element is chosen as the pivot
        int pivot = arr[(left+right)/2];

        //gives the sorted pivot index
        int p=partition(arr,left,right,pivot);
        
        //calls quick_sort for elements left to the partition       
        quick_sort(arr,left,p-1);
        //calls quick_sort for elements right to the partition
        quick_sort(arr,p,right);
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter "<<n<<" elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nBefore sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<<"\n";
    quick_sort(arr,0,n-1);
    cout<<"\nAfter Quick Sort"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}