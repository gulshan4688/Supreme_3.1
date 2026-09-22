#include <iostream>
#include<unordered_map>
#include<list>
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
    cout<<"Hello world";
    cout<<endl;
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    int n = 4;
    g.printGraph(n);
    return 0;
}