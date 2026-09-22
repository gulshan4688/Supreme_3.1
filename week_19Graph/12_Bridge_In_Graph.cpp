#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
class Graph {
  public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction) {
        if (direction == 1) {
            adjList[u].push_back(v);
        } else {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    void printAdjList(int n) {
        cout << "Printing Graph : " << endl;
        for (int i = 0; i < n; i++) {
            cout << i << " : { ";
            for (auto &nbr : adjList[i]) {
                cout << nbr << " ";
            }
            cout << "}" << endl;
        }
    }
    void topoSort(stack<int> &s, int node, unordered_map<int, bool> &visited) {
        visited[node] = true;

        for (auto const &nbr : adjList[node]) {
            if (!visited[nbr]) {
                topoSort(s, nbr, visited);
            }
        }
        // backtrack
        s.push(node);
    }
    
    void countBridges(int src,int parent, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &visited, int &timer){
        timer++;
        visited[src] = true;
        tin[src] = timer;
        low[src] = timer;
        // neigbhour se travel krte hai 
        for(auto &nbr : adjList[src]){
            // since its undirected graph there can be parent in nbr 
            if(nbr == parent){
                continue;
            }else if(!visited[nbr]){
                // normal traversal and check for bridges
                countBridges(nbr, src, tin, low, visited, timer);
                // returned from this function now do bridge check 

                low[src] = min(low[src], low[nbr]);
                if(low[nbr] > tin[src]){
                    // bridge exists
                    cout<<"Bridge found"<<endl;
                    cout<<nbr<<" - "<<src<<endl;
                }
            }else{
                // already visited and not parent 
                // low time ko update krdo 
                low[src] = min(low[src], low[nbr]);
            }
        } 
    }

};
int main() {
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(0, 2, 0); 
    g.addEdge(1, 3, 0);
    g.addEdge(3, 4, 0);
    int n = 5;
    g.printAdjList(n);
    int timer = 0;
    int src = 0;
    int parent = -1;
    vector<int> low(n);
    vector<int> tin(n);
    unordered_map<int, bool> visited;
    g.countBridges(src, parent, tin, low, visited, timer);
    return 0;
}