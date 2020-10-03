/*
Selection Sort:

Selects the minimum element from the unsorted array everytime 
and inserts it in the beginning
*/

#include<iostream>
using namespace std;

void swap(int * e, int * min){
    int* temp;
    temp=e;
    e=min;
    min=temp;
}
int main(){
    int *arr;
    int n;
    int min;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the Array elements: ";
    for (auto i = 0; i < n; i++)
        cin >> arr[i];
    for(auto i=0; i<n;i++){
        min = i;
        for(auto j=i+1;j<n;j++){
            // element at j is the minimum element in this iteration
            if(arr[min]>arr[j])
                min=j;
        }
        //Swapping minimum element with the element at first
        swap(arr[i],arr[min]);
    }
    cout<< "Sorted Array: ";
    for (auto i = 0; i < n; i++)
        cout<< arr[i]<<" ";
    return 0;
}