/*
Dijkstra's Shortest Path

    Finding the shortest path from single source to all vertices in a graph


*/


#include<iostream>
using namespace std;
#define V 9
#define max 999

//returns the minimum unprocessed index in the dist array
int minDistance(int dist[], bool pSet[]){

    int min = max, min_index;

    for(int i = 0; i<V; i++){
        if(dist[i]<=min && pSet[i]==false){
            min_index = i;
            min = dist[i];
        }
    }
    return min_index;
}


void dijsktra(int graph[V][V], int start){

    //creates an integer array of size V to store the distances from the source 
    //and bool array of size V to store the processed status 
    int dist[V];
    bool pSet[V];

    //initialize dist array with max value and pSet array with false
    for(int i=0;i<V;i++){
        dist[i] = max;
        pSet[i] = false;
    }

    //always distance of source/start is zero
    dist[start] = 0;

    
    for(int i=0; i<V-1; i++){
        //assign the minimum distance from the dist array to u
        int u = minDistance(dist, pSet);
        cout<<u;
        //mark u as processed
        pSet[u] = true;

        //loop from 0 to V to update the dist values of the vertices adjacent to u
        for(int v=0; v<V; v++){
            
            //The following conditions to be satisfied
            //1. There must be an edge between u and v
            //2. The sum of distance from source to v must be less than the distance in v
            //3. v should not be processed already
            //4. Distance of u must not be equal to max

            if(
                graph[u][v] && 
                dist[u] + graph[u][v] < dist[v] &&
                !pSet[v] &&
                dist[u] != max 
            ){
                //assign the new minimum distance to dist[v]
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    cout<<"Vertex\tDistance\n";
    for(int i=0;i<V;i++){
        cout<<i<<"\t"<<dist[i]<<"\n";    
    }
}

int main(){

    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },     
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    dijsktra(graph,0);
    return 0;
}