/*
Breadth First Search (BFS):
    - Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. 
    It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key'), 
    and explores all of the neighbour nodes at the present depth prior to moving on to the nodes at the next depth level.

Steps:
    i) Visit a node V.
    ii) Find the adjacent nodes(W) of the node (V) and Visit all of them.
    iii) Visit a node (V) from the adjacent nodes (W).
    iv) Repeat ii and iii until there is no adjacent node(W) for a node (V). 

Algorithm:
    i) Enqueue the start node to the queue
    ii) Dequeue the queue and mark it as visited
    iii) Find the adjacent nodes for the marked node, enqueue them to the queue 
         and mark them as visited
    iv) Repeat ii and iii until the queue is empty

*/


#include<iostream>
#include<list>
#include<queue>
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

        void BFS(int start){

            //visited list to store visited status
            bool *visited = new bool[v];

            //initializing false for all nodes
            for(int i =0; i<v;i++)
                visited[i] = false;
            
            //queue structure to store the traversal
            queue<int> q;
            q.push(start);
            cout<<start<<"\t";
            

            //iterator to traverse through a single node in the adjaceny list
            list<int>::iterator i;

            while(!q.empty()){
                
                //step ii from algorithm
                int temp = q.front();
                q.pop();
                visited[temp]=true;

                //step iii from algorithm
                for(i = adj[temp].begin(); i!= adj[temp].end();i++){
                    if(!visited[*i]){
                        visited[*i] = true;
                        q.push(*i);

                        //visiting a vertex/node
                        cout<<*i<<"\t";
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

    //calling BFS method with start vertex/node
    g.BFS(2);

    return 0;
}