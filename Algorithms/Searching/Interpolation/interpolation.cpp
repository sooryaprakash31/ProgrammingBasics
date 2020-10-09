/*
Interpolation Search:

Uses the position formula to obtain the closest index to the key
and searches the key using that index

pos = low + ( (key - arr[low]) * (high - low) / (arr[high]-arr[low]) )
- Requires sorted array

Special case:
    If the array is uniformly distributed, 
    it requires just one step to find the position of key
        - An array is uniformly distributed if the difference between any 
          two consecutive elements is constant
          Example:
          arr = [3,5,7,9,11,13]
*/


#include<iostream>
using namespace std;

int interpolation_search(int arr[], int l, int h, int key){
        
    //Always l<=h otherwise it leads to out of bounds error
    if(l<=h){
        //calculates the pos using the formula
        int pos = l+((key-arr[l])*(h-l)/(arr[h]-arr[l]));
        //if pos is not within the end points then return
        if(pos>h || pos<l){
            cout<<arr[pos];
            return -1;
        }
        //if key is lesser than element at pos,
        //then calls interpolation search for left block 
        if(key<arr[pos]){
            return interpolation_search(arr, l, pos-1,key);
        }
        //if key is greater than element at pos,
        //then calls interpolation search for right block
        else if(key>arr[pos]){
            return interpolation_search(arr,pos+1,h,key);
        }
        //if key is equal to element at pos, return pos
        else{
            return pos;
        }
    }
    //returns -1 if key is not in the array
    return -1;
}

int interpolation_uniform_search(int arr[],int l,int h, int key){

    //Calculats position using the formula
    int pos = l+((key-arr[l])*(h-l)/(arr[h]-arr[l]));
    
    //checks if the element at pos is equal to key
    if(arr[pos]==key){
        return pos;
    }
    //returns -1 if key is not in the array
    return -1;
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

    //calling interpolation_search method
    result = interpolation_search(arr,0, n-1, key);
    
    //calling interpolation search if the array is uniformly distributed
    //result = interpolation_uniform_search(arr,0,n-1,key);
    
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