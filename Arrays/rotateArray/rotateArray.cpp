/*
Given a set of space separated integers, this program rotates
the array based on the rotation value.

The array {1,2,3,4,5,6} with rotation value 2 will result in
{3,4,5,6,1,2}
*/
#include <iostream>
#include<vector>
using namespace std;

void rotateArray(int size, int rotation){
    int l=0,count=0;
    vector<int> var;
    vector<int> final;
    for(int j=0;j<size;j++){
        int k;
        cin>>k;
        var.push_back(k);
    }
    /*
    Transferring the array from rotation point to end and then 
    from the beginning to the rotation point into a another array
    */
    l=var.size();
    for(int i=rotation;i<l;i++){
        
        final.push_back(var[i]);
        if(i==var.size()-1 && count<var.size())
        {
            i=-1;
            l=rotation;
        }
        count++;
    }
    for(int i=0; i<final.size();i++){
        cout<<final[i]<<" ";
    }
    cout<<"\n"; 
    final.clear();
    var.clear();
}

//main function
int main() {
    int test_cases;
    cin>>test_cases;
    for(int i=0;i<test_cases;i++){
        int size,rotation;
        cin>>size>>rotation;    
        rotateArray(size,rotation);
    }
	return 0;
}
//end