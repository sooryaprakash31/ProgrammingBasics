/*
Algorithm:
    i) Create visited array and initialize it with false values
    iii) Run loop for every vertex in the graph
    iv) If the vertex is unvisited, 
        a) mark it as visited
        c) return true if any of its adjacent vertices are visited
        d) return true if any of its visited adjacent vertex is not its parent
        e) otherwise, return false 
    iv) Graph contains cycle if true
    v) Graph doesnt contain cycle if false
*/


#include<iostream>
#include<list>
using namespace std;

class Graph{

    int V;
    list<int> *adj;


    public:

        Graph(int V){
            this->V = V;
          adj = new list<int>[V];
        }

        void addEdge(int v, int w){
            adj[v].push_back(w);
        }

        bool isCyclic(){
            //create visited to store visited status and
            bool *visited = new bool[V];

            //initialize visited with false
            for(int i=0;i<V;i++){
                visited[i] = false;
            }

            //run loop for every vertex
            for(int i=0;i<V;i++){

                //only run loop for unvisited vertices
                if(!visited[i]){
                    //calling isCyclicUntil function for the vertex i, sending -1 as parent initially
                    //return true if there is a cycle
                    if(isCyclicUntil(i,visited,-1)){
                        return true;
                    }
                }
            }
            // otherwise return false
            return false;
        }

        bool isCyclicUntil(int v, bool visited[], int parent){
            
            //mark it as visited
            visited[v] = true;

            list<int>::iterator i;

            //run loop for all its adjacent vertices
            for(i = adj[v].begin(); i!= adj[v].end();i++){
                
                //If adjacent vertices of v is not visited, run isCyclicUntill 
                //by sending v as parent and i as the vertex 
                if(!visited[*i]){
                    if(isCyclicUntil(*i, visited, v)){
                        return true;
                    }
                } 

                //if the visited vertex is not the parent of i, then return true
                else if(*i != parent){
                    return true;
                }
            }
            //otherwise return false
            return false;
        }   
};

int main(){

    Graph g1(5); 
    //contains cycle
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    
  
    Graph g2(3); 
    //doesn't contain cycle
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    
    if(g2.isCyclic()) 
        cout << "Graph contains cycle\n"; 
    else
        cout << "Graph doesn't contain cycle\n";

    return 0;
}