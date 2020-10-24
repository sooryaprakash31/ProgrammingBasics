

#include<iostream>
using namespace std;

int binary_search(int arr[], int l, int h, int key){

    if(l<=h){
        int mid = (l+h)/2;

        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key)
        {
            return binary_search(arr,l,mid,key);
        }
        else{
            return binary_search(arr,mid+1,h,key);
        }
        
    }
    return -1;
}

int exponential_search(int arr[],int n, int key){

    if (arr[0]==key){
        return 0;
    }

    int i = 1;
    while(i<n && arr[i]<=key){
        i = i*2;
    }

    return binary_search(arr,i/2,min(i,n-1),key);

}

int main(){

    int n, key, result;
    cout << "Enter the length of array ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements ";
    for (auto i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the key ";
    cin >> key;

    result = exponential_search(arr,n,key);
    if(result==-1){
        cout<<"\nKey not found";
    }
    else{
        cout<<"Key found at position "<<result+1;
    }
    return 0;
}