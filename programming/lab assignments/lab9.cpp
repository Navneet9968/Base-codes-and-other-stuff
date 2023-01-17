#include <bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int>* adj;  // this is a pointer to an array containg all the adjaceny Lists

    // a utility function that is used by topological sort 

    void topologicalSortUtil(int v,bool visited[],stack <int> &Stack);

    public:
    //constructor
    Graph(int V);

    void addEdge(int v ,int w){
        //this will just add the w to end of that v numbers list present at v index in adj arr
        adj[v].push_back(w);
    }
    //this prints the complete topological sort of the Graph
    void topologicalSort();

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph:: topologicalSortUtil(int v,bool visited[],stack <int> &Stack){
    //marking the curent node as visited in the graph
    visited[v]=true;
    list<int>::iterator i;
    for( i = adj[v].begin(); i!= adj[v].end(); ++i){
        if(!visited[*i]){
            topologicalSortUtil(*i,visited,Stack);
        }
    }
    Stack.push(v);
}
void Graph :: topologicalSort(){
    stack<int>Stack;

    bool * visited =new bool[V];
    for(int i =0;i<V;i++){
        if(visited[i]==false){
            topologicalSortUtil(i,visited,Stack);
        }
    }
    while(!Stack.empty()){
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
}

int main() {
// Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Topological Sort : "
            "graph \n";
 
    // Function Call
    g.topologicalSort();

    return 0;
}