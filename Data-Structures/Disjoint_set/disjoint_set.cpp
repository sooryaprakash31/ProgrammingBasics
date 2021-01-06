/*
Disjoint Set:

    - Used to perform two operations
        i) Find() - finds whether a item present in a subset
        ii) Union() - joins two subsets into one set

*/

#include<iostream>
using namespace std;

//Array and tree are the data structures used to construct disjoint set
class DisjointSet{

    //create rank to store height of the trees, parent to store the items' parents 
    //and n to hold number of items
    int *rank, *parent, n;

    public:

    DisjointSet(int n){
        
        this->n = n;
        this->rank = new int[n];
        this->parent = new int[n];

        //initialize parent array with their index values
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int x){

        //if x is not equal to parent[x] then call find for parent[x]
        //until the parent value for x is returned
        if(parent[x]!=x){

            //path compression - search time can be reduced 
            //if the parent of items is stored at their index position
            parent[x] = find(parent[x]);
        }
        //returning the parent value
        return parent[x];
    }

    void unionSet(int i, int j){

        //find the parent of i
        int iset = find(i);
        //find the parent of j
        int jset = find(j);

        //if they belong to same set, dont do anything
        if(iset==jset){
            return;
        }

        //if the rank of jset is greater, make jset as parent of iset
        if(rank[iset]<rank[jset]){
            parent[iset] = jset;
        }

        //if the rank of iset is greater, make iset as parent of jset
        else if(rank[iset]>rank[jset]){
            parent[jset]=iset;
        }
        
        //if the ranks are equal, make anyone as parent of the other
        //and increment the rank of the parent
        else{
            parent[iset] = jset;
            rank[jset]++; 
        }
    }

};

int main(){

    DisjointSet obj(5); 

    //adding items to the set
    obj.unionSet(0, 2); 
    obj.unionSet(4, 2); 
    obj.unionSet(3, 1); 

    //4 and 0 belong to the same set - Hence Yes
    if (obj.find(4) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
    
    //1 and 0 belong to different sets - Hence No
    if (obj.find(1) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 

    return 0;
}