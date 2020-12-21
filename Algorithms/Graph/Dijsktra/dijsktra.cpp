/*
Dijkstra's Shortest Path

    Finding the shortest path from single source to all vertices in a graph


*/


#include<iostream>
using namespace std;
#define V 9
#define max 999

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

    int dist[V];
    bool pSet[V];
    for(int i=0;i<V;i++){
        dist[i] = max;
        pSet[i] = false;
    }

    dist[start] = 0;

    for(int i=0; i<V-1; i++){

        int u = minDistance(dist, pSet);
        pSet[u] = true;

        for(int v=0; v<V; v++){
            if(
                graph[u][v] && 
                dist[u] + graph[u][v] < dist[v] &&
                !pSet[v] &&
                dist[u] != max 
            ){
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