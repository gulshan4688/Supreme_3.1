#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph{
    public: 
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool isDirected){
        // isDirected -> 0 > undirected graph
        // isDirected -> 1 > directed graph
        if(isDirected == 0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }else{
            adjList[u].push_back(v);
        }

    }
    
    void BFS(int src){
        unordered_map<int, bool> visited;
        queue<int> q;

        // initial state maintain 
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            cout<<front<<" ";
            // list<int> temp = adjList[front];
            for(const auto &i : adjList[front]){
                if(visited[i] == false){
                    q.push(i);
                    visited[i] = true;
                }
            }

        }
    }
    void dfsHelper(int src, unordered_map<int, bool> &visited){
        visited[src] = true;
        cout<<src<< " ";
        for(const auto &nbr : adjList[src]){
            if(visited[nbr] == false){
                dfsHelper(nbr, visited);
             }
        }
    }
    void DFS(int n){
        unordered_map<int, bool> visited;
        int src = 0;
        dfsHelper(src, visited);  // real logic behind DFS
        
        // what if there is disconnected graph so there will be different sources
        for(src = 0 ; src < n ; src++){
            if(!visited[src]) dfsHelper(src, visited);
        }
    }

    void printGraph(int n){ 

        for(int i = 0; i < n ; i++){
            cout<<i<<": [";
            list<int> temp = adjList[i];
            for(const auto &e : temp){
                cout<<e<<" ";
            }
            cout<<"]"<<endl;
        }
    }
};

int main(){
    cout<<"Hello world";
    cout<<endl;
    Graph g;
    g.addEdge(0,3,1);
    g.addEdge(0,5,1);
    g.addEdge(0,2,1);
    g.addEdge(3,5,1);
    g.addEdge(5,4,1);
    g.addEdge(5,6,1);
    g.addEdge(4,1,1);
    g.addEdge(6,1,1);
    int n = 6;
    g.printGraph(7);
    cout<<"BFS : ";
    g.BFS(0);
    cout<<"DFS : ";
    g.DFS(n);
    return 0;
}