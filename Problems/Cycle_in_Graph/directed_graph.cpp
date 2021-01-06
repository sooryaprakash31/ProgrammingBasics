/*
Algorithm:
    i) Create visited and recursionStack arrays which will hold bool values
    ii) Initialize visited and recursionStack with false values
    iii) Run loop for every vertex in the graph
    iv) If the vertex is unvisited, 
        a) mark it as visited
        b) push it to recursionStack
        c) return true if any of its adjacent vertices are visited
        d) return true if any of its adjacent vertices are in recursion stack
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
            //recursionStack to store the parent vertex    
            bool *visited = new bool[V];
            bool *recursionStack = new bool[V];

            //initialize visited and recursionStack with false
            for(int i=0;i<V;i++){
                visited[i] = false;
                recursionStack[i] = false;
            }

            //run loop for every vertex
            for(int i=0;i<V;i++){

                // if any of the adjacent vertices of vertex i contains backedge, return true
                //isCyclicUntil checks if any of the adjacent vertices of i contains backedge
                if(isCyclicUntil(i,visited,recursionStack)){
                    return true;
                }
            }
            // otherwise return false
            return false;
        }

        bool isCyclicUntil(int v, bool visited[], bool recursionStack[]){
            
            //the vertex must be unvisited
            if(visited[v]==false){ 

                //mark it as visited
                visited[v] = true;
                //push it to recursionStack
                recursionStack[v] = true;

                list<int>::iterator i;

                //run loop for all its adjacent vertices
                for(i = adj[v].begin(); i!= adj[v].end();i++){
                    
                    //if the adjacent vertex i is already visited, then its a backedge. Return true
                    //isCyclicUntil is called for all the adjacent vertices of i recursively
                    if(!visited[*i] && isCyclicUntil(*i, visited, recursionStack)){
                        return true;
                    }
                    //if the adjacent vertex i of v is already in recursionStack, then return true
                    else if(recursionStack[*i]){
                        return true;
                    }
                }
            }
            //remove the vertex from the stack
            recursionStack[v] = false;
            return false;
        }


};

int main(){

    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    if(g.isCyclic()) 
        cout << "Graph contains cycle\n"; 
    else
        cout << "Graph doesn't contain cycle\n";

    return 0;
}