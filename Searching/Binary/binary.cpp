/*
Binary Search:

Compares the key with the middle element and
i) if the key is greater than middle element,
    compares key with the middle element of the right block
ii) if the key is lesser than middle element,
    compares key with the middle element of the left block
Repeats this process recursively

- Works only with sorted array inputs
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

int main(){
    int n,key,result;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nEnter key: ";
    cin>>key;

    //calling binary_search function
    result=binary_search(arr,0,n-1,key);

    if(result==-1){
        cout<<"\nNot found";
    }
    else{
        cout<<"\nKey found at position "<<result+1;
    }
    return 0;
}