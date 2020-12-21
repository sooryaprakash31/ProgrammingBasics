/*
Depth First Search (DFS):
    - Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures. 
      The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) 
      and explores as far as possible along each branch before backtracking.

Steps:
    i) Visit the vertex V.
    ii) Finds its adjacent nodes (W) and visit any of these nodes (V).
    iii) Repeat i and ii until there is no adjacent node(W) for a node(V). 

Algorithm:
    i) Push the starting node to the stack
    ii) Pop the top from the stack and mark it as visited
    iii) Find all the adjacent nodes from the marked node and push them to the stack
    iv) Repeat ii and iii until the stack is empty

*/


#include<iostream>
#include<stack>
#include<list>

using namespace std;

class Graph{

    //number of vertices/nodes
    int v;
    list<int> *adj;

    public:

        Graph(int v){
            this->v = v;

            //list of v lists for creating the adjaceny list
            adj = new list<int>[v];  
        }

        void addEdge(int v, int w){

            //adjacent node W is added for node V
            adj[v].push_back(w);
        }

        void DFS(int start){


            //visited list to store visited status
            bool *visited = new bool[v];
            
            //initializing false for all nodes
            for(int i=0;i<v;i++)
                visited[i]=false;
            
            //stack structure to store the traversal
            stack<int> s;
            s.push(start);

            //iterator to traverse through a single node in the adjaceny list
            list<int>::iterator i;
            
            
            while(!s.empty()){
                
                //step ii from algorithm
                int temp = s.top(); 
                s.pop();
                visited[temp]=true;

                //visiting a vertex/node
                cout<<temp<<"\t";
                
                //step iii from algorithm
                for(i = adj[temp].begin();i!=adj[temp].end();i++ ){
                    if(!visited[*i]){
                        s.push(*i);
                    }
                }
            }
        }
};


int main(){

    //instantiating Graph with number of vertices
    Graph g(4);

    //Adding edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    //calling DFS method with start node/vertex
    g.DFS(0);

    return 0;
}