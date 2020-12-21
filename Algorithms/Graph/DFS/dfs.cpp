#include<iostream>
#include<stack>
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

        void DFS(int start){

            stack<int> s;
            bool *visited = new bool[v];

            for(int i=0;i<v;i++)
                visited[i]=false;
            s.push(start);

            list<int>::iterator i;
            while(!s.empty()){
                int temp = s.top(); 
                s.pop();
                visited[temp]=true;
                cout<<temp<<"\t";
                for(i = adj[temp].begin();i!=adj[temp].end();i++ ){
                    if(!visited[*i]){
                        s.push(*i);
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
    g.DFS(0);
    return 0;
}