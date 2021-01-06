#include<iostream>
using namespace std;

class DisjointSet{

    int *rank, *parent, n;

    public:

    DisjointSet(int n){
        
        this->n = n;
        this->rank = new int[n];
        this->parent = new int[n];

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int x){

        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void unionSet(int i, int j){

        int iset = find(i);
        int jset = find(j);

        if(iset==jset){
            return;
        }


        if(rank[iset]<rank[jset]){
            parent[iset] = jset;
        }
        else if(rank[iset]>rank[jset]){
            parent[jset]=iset;
        }
        else{
            parent[iset] = jset;
            rank[jset]++; 
        }
    }

};

int main(){

    DisjointSet obj(5); 
    obj.unionSet(0, 2); 
    obj.unionSet(4, 2); 
    obj.unionSet(3, 1); 
    if (obj.find(4) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
    if (obj.find(1) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 

    return 0;
}