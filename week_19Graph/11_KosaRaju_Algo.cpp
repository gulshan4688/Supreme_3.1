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
    void dfs(int src, unordered_map<int, bool> &visited,
             unordered_map<int, list<int>> &adjNew) {
        visited[src] = true;
        cout << src << " ";
        for (auto &nbr : adjNew[src]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, adjNew);
            }
        }
    }
    int countSCC(int n) {

        // step 1 : find the topo Logical ordering
        stack<int> st;
        unordered_map<int, bool> visitedforSCC;
        for (int i = 0; i < n; i++) {
            if (!visitedforSCC[i]) {
                topoSort(st, i, visitedforSCC);
            }
        }

        // since we have a topo order ready
        // step 2 : will reverse all edges
        unordered_map<int, list<int>> adjNew;
        for (auto &i : adjList) {
            for (auto &j : i.second) {
                int u = i.first;
                int v = j;
                // to reverse the array we have to make a new edge in adjNew
                adjNew[v].push_back(u);
            }
        }
        // traversal and count bridges between group nodes

        int count = 0;

        unordered_map<int, bool> visited;

        while (!st.empty()) {
            int src = st.top();
            st.pop();
            if (!visited[src]) {
                cout << "SCC : ";
                dfs(src, visited, adjNew);
                // ek poora component/ group traverse ho chuka hai now , like
                // the "no. of islands question"
                cout << endl;
                count++;
            }
        }
        return count;
    }
};
int main() {
    Graph g;
    g.addEdge(0, 3, 1);
    g.addEdge(3, 2, 1);
    g.addEdge(2, 1, 1);
    g.addEdge(1, 0, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 7, 1);
    int n = 8;
    // g.printAdjList(n);

    int count = g.countSCC(n);
    cout << "SCC Count : " << count << endl;

    // cout<<"Printing graph in topo Logical order : "<<endl;
    // while(!s.empty()){
    //     cout<<s.top()<<", ";
    //     s.pop();
    // }

    return 0;
}