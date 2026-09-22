#include <iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public: 
    unordered_map<int, list<int>> adjList;

    unordered_map<int, list<pair<int, int>>> adjListW;

    void addEdgeSimple(int u, int v, bool isDirected){
        // isDirected -> 0 > undirected graph
        // isDirected -> 1 > directed graph
        if(isDirected == 0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }else{
            adjList[u].push_back(v);
        }

    }
    void addEdgeW(int u, int v, int wt, bool isDirected){
        if(isDirected == 0){
            adjListW[u].push_back({v, wt});
            adjListW[v].push_back({u, wt});
        }else{
            adjListW[u].push_back({v, wt});
        }

    }
    void printWeightedGraph(int n){  
        for(int i = 0; i < n ;i++ ){
            cout<<i<<" : {";
            list<pair<int, int>> temp = adjListW[i];
            for(const auto &p : temp){
                cout<<"("<<p.first<<", "<<p.second<<"),";
            }
            cout<<"}"<<endl;
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
    // g.addEdge(0,1,1);
    // g.addEdge(0,2,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,3,1);
    int n = 4;
    // g.printGraph(n);
    g.addEdgeW(1,2,4,1);
    g.addEdgeW(1,3,6,1);
    g.addEdgeW(2,3,5,1);
    g.addEdgeW(3,4,7,1);
    g.printWeightedGraph(n);
    return 0;
}