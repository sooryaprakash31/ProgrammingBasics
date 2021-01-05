/*
Floyd Warshall:

    - Finds the shortest distances between every pair of vertices in 
      a given edge weighted directed graph
    
Algorithm:

    i) create dist array and initialize with graph array values
    ii) loop k to V (All vertices as intermediate one by one)
            loop i to V (All vertices as source one by one)
                loop j to V (All vertices as destination one by one)
                    update the distance if the distance is greated than the 
                    sum of distances of i to k and k to j
                    

*/


#include<iostream>
using namespace std;
#define INF 9999

void floydWarshall(int graph[4][4]){
    //create dist array to store the shortest distances
    int dist[4][4], i,j,k;

    //initialize the dist array with the values from graph array
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            dist[i][j] = graph[i][j];
        }
    }
    //find if there is any intermediate vertex (k) between i and j
    //and compare the distance with the sum of i to k and k to j
    //Update the distance if the distance through intermediate vertex is lesser
    for ( k = 0; k < 4; k++)
    {
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                
                //compares the sum of i to k and k to j with the old distance
                if(dist[i][k]+dist[k][j] <dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    //print the dist array which contains shortest distances 
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(dist[i][j]==INF){
                cout<<"-"<<" ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }

}


int main(){

    int graph[4][4] = {
        {0, 5, INF, 10},  
        {INF, 0, 3, INF},  
        {INF, INF, 0, 1},  
        {INF, INF, INF, 0}  
    };

    floydWarshall(graph);

    return 0;
}