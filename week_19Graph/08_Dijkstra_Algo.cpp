#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    unordered_map<int, list<pair<int, int>>> adjListW;

    void addEdgeSimple(int u, int v, bool isDirected)
    {
        // isDirected -> 0 > undirected graph
        // isDirected -> 1 > directed graph
        if (isDirected == 0)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else
        {
            adjList[u].push_back(v);
        }
    }
    void addEdgeW(int u, int v, int wt, bool isDirected)
    {
        if (isDirected == 0)
        {
            adjListW[u].push_back({v, wt});
            adjListW[v].push_back({u, wt});
        }
        else
        {
            adjListW[u].push_back({v, wt});
        }
    }
    void printWeightedGraph(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " : {";
            list<pair<int, int>> temp = adjListW[i];
            for (const auto &p : temp)
            {
                cout << "(" << p.first << ", " << p.second << "),";
            }
            cout << "}" << endl;
        }
    }
    void printGraph(int n)
    {

        for (int i = 0; i < n; i++)
        {
            cout << i << ": [";
            list<int> temp = adjList[i];
            for (const auto &e : temp)
            {
                cout << e << " ";
            }
            cout << "]" << endl;
        }

        // for(const auto &m : adjList){

        //     cout<<m.first<<" : [";
        //     for(const auto &i : m.second){
        //         cout<<i<<" ";
        //     }
        //     cout<<"]"<<endl;
        // }
    }
    void DijkstraAlgo(int src, int n)
    {
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;

        // initial state
        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty())
        {
            auto topElement = *(st.begin()); // gives one pointer so we makes it a value by adding astrik to it
            int weight = topElement.first;   // weight from destination
            int topNode = topElement.second;

            // pop
            st.erase(st.begin());

            // neighbour par jao
            for (auto &nbr : adjListW[topNode])
            {
                // nbr is a pair
                // nbr = {a,b} where a = weight and b is the node
                // nbr is a type of {a, b }
                // a -> nbr Node
                // b -> weight from parent node to child node

                int nbrNode = nbr.first;
                int nbrDist = nbr.second;

                if (dist[topNode] + nbrDist < dist[nbrNode])
                {
                    // 2 kaam
                    // dist array me update
                    // set me update

                    auto result = st.find({dist[nbrNode], nbrNode}); // we get an iterator , here its result
                    if (result != st.end())
                    { // entry found
                        st.erase(result);
                    }
                    dist[nbrNode] = dist[topNode] + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        cout << "Printing the result : " << endl;

        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << " ";
        }
    }
    void bellManFordAlgo(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        // initial state
        dist[src] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (auto &a : adjListW)
            {
                for (auto &b : a.second)
                {
                    // a -> u
                    // a.second -> is a pair {node, dist} that is nbr of node u in adjList
                    // b -> pair<int, int>
                    // b.first -> v
                    // b.second -> wt

                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;

                    if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        bool negativeCylePresent = false;
        for (auto &a : adjListW)
        {
            for (auto &b : a.second)
            {
                int u = a.first;
                int v = b.first;
                int wt = b.second;

                if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                    negativeCylePresent = true;
                    break;
                }
            }
        }
        if (negativeCylePresent)
        {
            cout << "Negative Cycle Present." << endl;
        }
        else
        {
            cout << "No negative Cycle Present." << endl;
            cout << "Printing distance array : " << endl;
            for (int i = 0; i < n; i++)
            {
                cout << dist[i] << " ";
            }
        }
    }
};
int main()
{
    cout << "Hello world";
    cout << endl;
    Graph g;

    // g.addEdgeW(0, 1, -1, 1);
    // g.addEdgeW(1, 4, 2, 1);
    // g.addEdgeW(0, 2, 4, 1);
    // g.addEdgeW(3, 2, 5, 1);
    // g.addEdgeW(4, 3, -3, 1);
    // g.addEdgeW(1, 2, 3, 1);
    // g.addEdgeW(1, 2, 3, 1);
    // g.addEdgeW(1, 3, 2, 1);
    // g.addEdgeW(3, 1, 1, 1);

    g.addEdgeW(0, 1, -1, 0);
    g.addEdgeW(1, 0, -2, 0);

    // g.addEdgeW(2, 1, 7, 1);
    // g.printWeightedGraph(9);
    // g.DijkstraAlgo(0, 6);
    g.bellManFordAlgo(0, 5);
    return 0;
}