#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
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
    void shorTestPathBFS(int src, int dest){
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> q;

        // maintain intial state 
        q.push(src);
        parent[src] = -1;
        visited[src] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto &nbr : adjList[front]){
               if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                    parent[nbr] = front;
               }
            }
        }
        // Now our parent array is ready 
        vector<int> path;
        int node = dest;
        while(node != -1){
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        cout<<"Path : ";
        for(auto &i : path){
            cout<<i<<"->";
        }
    }
};

int main(){
    cout<<"Hello world"<<endl;
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(2,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,3,0);

    int src = 0;
    int dest = 3;
    g.shorTestPathBFS(src, dest);
    return 0;
}