#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
  public:
    unordered_map<int, list<int>> adjList;

    unordered_map<int, list<pair<int, int>>> adjListW;

    void addEdgeSimple(int u, int v, bool isDirected) {
        // isDirected -> 0 > undirected graph
        // isDirected -> 1 > directed graph
        if (isDirected == 0) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        } else {
            adjList[u].push_back(v);
        }
    }
    void addEdgeW(int u, int v, int wt, bool isDirected) {
        if (isDirected == 0) {
            adjListW[u].push_back({v, wt});
            adjListW[v].push_back({u, wt});
        } else {
            adjListW[u].push_back({v, wt});
        }
    }
    void printWeightedGraph(int n) {
        for (int i = 0; i < n; i++) {
            cout << i << " : {";
            list<pair<int, int>> temp = adjListW[i];
            for (const auto &p : temp) {
                cout << "(" << p.first << ", " << p.second << "),";
            }
            cout << "}" << endl;
        }
    }
    void printGraph(int n) {
        for (int i = 0; i < n; i++) {
            cout << i << ": [";
            list<int> temp = adjList[i];
            for (const auto &e : temp) {
                cout << e << " ";
            }
            cout << "]" << endl;
        }
    }

    void FlyodWarshal(int n) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        // step : 1 , diagonal pe zero
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        // step : 2, copy all distances from graph to matrix

        for (auto a : adjListW) {
            for (auto b : a.second) {
                int u = a.first;
                int v = b.first;
                int wt = b.second;
                dist[u][v] = wt;
            }
        }

        // main logic
        for (int helper = 0; helper < n; helper++) {
            for (int src = 0; src < n; src++) {
                for (int dest = 0; dest < n; dest++) {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                    // if (dist[src][helper] != 1e9 && dist[helper][dest] != 1e9) {
                    //     dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                    // }
                }
            }
        }

        cout << "Printing Flyod result : " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << dist[i][j] << "  ";
            }
            cout << endl;
        }
    }
};
int main() {
    cout << "Hello world";
    cout << endl;
    Graph g;

    // Set isDirected = 1 for directed edges with negative weights
    g.addEdgeW(0, 2, -2, 1);
    g.addEdgeW(1, 0, 4, 1);
    g.addEdgeW(1, 2, 3, 1);
    g.addEdgeW(3, 1, -1, 1);
    g.addEdgeW(2, 3, 2, 1);

    g.FlyodWarshal(4);
    return 0;
    return 0;
}