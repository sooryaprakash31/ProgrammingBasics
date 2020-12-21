#include<iostream>
#include<list>
using namespace std;

class Graph{

    int v;
    list<int> *adj;
    
    public:
        Graph(int v){
            this->v = v;
            adj = new list<int>[v];
        }

        void addEdge(int v, int w){
            
            adj[v].push_back(w);
        }

        void BFS(int s){
            bool *visited = new bool[v];
            list<int> queue;
            for(int i =0; i<v;i++)
                visited[i] = false;

            queue.push_back(s);
            cout<<s<<"\t";
            visited[s]=true;
            list<int>::iterator i;

            while(!queue.empty()){
            
                int temp = queue.front();
                queue.pop_front();
                for(i = adj[temp].begin(); i!= adj[temp].end();i++){
                    if(!visited[*i]){
                        visited[*i] = true;
                        queue.push_back(*i);
                        cout<<*i<<"\t";
                    }
                }
            }
        
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
    g.BFS(2);
    return 0;
}