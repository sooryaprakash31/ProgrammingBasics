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
            
            bool *visited = new bool[V];
            bool *recusionStack = new bool[V];


            for(int i=0;i<V;i++){
                visited[i] = false;
                recusionStack[i] = false;
            }


            for(int i=0;i<V;i++){
                if(isCyclicUntil(i,visited,recusionStack)){
                    return true;
                }
            }
            return false;
        }

        bool isCyclicUntil(int v, bool visited[], bool recusionStack[]){

            if(visited[v]==false){

                visited[v] = true;
                recusionStack[v] = true;

                list<int>::iterator i;
                for(i = adj[v].begin(); i!= adj[v].end();i++){
                    
                    if(!visited[*i] && isCyclicUntil(*i, visited, recusionStack)){
                        return true;
                    }
                    else if(recusionStack[*i]){
                        return true;
                    }
                }
            }

            recusionStack[v] = false;
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