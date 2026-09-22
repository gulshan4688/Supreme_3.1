#include <iostream>
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
    void LevelOrderTraversal(int src){
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
};

int main(){
    cout<<"Hello world";
    cout<<endl;
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(0,5,1);
    g.addEdge(2,4,1);
    int n = 4;
    g.printGraph(n);
    g.LevelOrderTraversal(0);
    return 0;
}