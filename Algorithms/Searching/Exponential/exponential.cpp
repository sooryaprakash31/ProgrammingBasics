/*
Exponential Search:

    i) Finds the range where the key may present in the sorted array
        a) Takes 1 as initial value  i and compares the key and element at index i
        b) If element at index i is greater than key, then takes lower bound as i/2
        c) Else multiplies it with 2 and repeats the previous step
    ii) Performs binary search for that range to find the position of the key

    - Requires sorted array
*/

#include<iostream>
using namespace std;


//Binary seach method
int binary_search(int arr[],int l,int h,int key){
    
    //#Always l must be less than h, 
    //otherwise leads to out of bounds error
    if(l<=h){
        
        //calculating middle element of the array
        int mid=(l+h)/2;

        //if key is equal to mid, return mid
        if(key==arr[mid]){
            return mid;
        }

        //calls binary_search for left block, if key is lesser
        else if(key<arr[mid]){
            return binary_search(arr,l,mid,key);
        }
        //calls binary_search for left block, if key is greater
        else{
            return binary_search(arr,mid+1,h,key);
        }
    }

    //if l is greater than h, it means all elements have been compared with key
    else{
        return -1;
    }
}

//exponential search
int exponential_search(int arr[],int n, int key){

    //if the key present at 0, returns 0
    if (arr[0]==key){
        return 0;
    }

    //Takes initial value for i as 1
    int i = 1;

    //The value of i is incremented until i is lesser than n
    // and element at index i is lesser than or equal to key
    while(i<n && arr[i]<=key){
        i = i*2;
    }

    //The last value of i is the upper bound of the range
    //The lower bound for the range is taken as i/2 (previous i value)
    //binary search() is called for the obtained range
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

    //calling exponential search()
    result = exponential_search(arr,n,key);
    if(result==-1){
        cout<<"\nKey not found";
    }
    else{
        cout<<"Key found at position "<<result+1;
    }
    return 0;
}