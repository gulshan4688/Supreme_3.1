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
    bool detectCycle(int src, unordered_map<int, bool> &visited){
        queue<int> q;
        unordered_map<int, int> parent;
        

        // initial state 
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(const auto &e : adjList[front]){
                if(!visited[e]){
                    q.push(e);
                    visited[e] = true;
                    parent[e] = front;
                }
                else if(parent[front] != e){
                    // cycle present 
                    return true;
                }
            }
        }
        return false;
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

        // for(const auto &m : adjList){
            
        //     cout<<m.first<<" : [";
        //     for(const auto &i : m.second){
        //         cout<<i<<" ";
        //     }
        //     cout<<"]"<<endl;
        // }
    }
};
int main(){
    cout<<"Hello world"<<endl;
    unordered_map<int, bool> visited;
    cout<<endl;
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(3,4,0);
    g.addEdge(3,0,0);
    int n = 4;
    g.printGraph(n);
    
    bool ans = false;
    for(int i = 0; i < n; i++){ // looping on every node
        if(!visited[i]){
            ans = g.detectCycle(i, visited);
            if(ans == true){
                break;
            }
        }
    }
    if(ans == true){
        cout<<"Cycle Found";
    }else{
        cout<<"Cycle Not Found";
    }

    return 0;
}