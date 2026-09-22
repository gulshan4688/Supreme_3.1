#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
#include <limits.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjListW;

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

    vector<int> topoSortBFS(int n)
    {
        unordered_map<int, int> indegree;
        // int n = adjList.size();
        queue<int> q;
        vector<int> s;

        // initialse every degree for node
        for (int i = 0; i < n; i++)
        {
            indegree[i] = 0;
        }
        // store indegree of each node
        for (int i = 0; i < n; i++)
        {
            for (auto &nbr : adjListW[i])
            {
                indegree[nbr.first]++;
            }
        }

        // Push all nodes having indegree 0
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // do level order with q to fill the stack
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            s.push_back(front);
            for (auto &nbr : adjListW[front])
            {
                indegree[nbr.first]--;
                if (indegree[nbr.first] == 0)
                {
                    q.push(nbr.first);
                }
            }
        }
        return s;
    }
    // void ShortestPath_Directed(int n, int src)
    // {
    //     vector<int> s = topoSortBFS(n);

    //     unordered_map<int, bool> visited;
    //     vector<int> dist(n, INT_MAX);

    //     // udpate the distance in the update array
    //     dist[src] = 0;

    //     for (auto &nbr : adjListW[src])
    //     {
    //         // nbr.first = node, nbr.second = weight
    //         int node = nbr.first;
    //         int weight = nbr.second;
    //         // udpate the distance accordingly
    //         if (dist[src] + weight < dist[node])
    //         {
    //             dist[node] = dist[src] + weight;
    //         }
    //     }

    //     // main logic to calculate the shortest array
    //     while (!s.empty())
    //     {
    //         int frontNode = s.top();
    //         s.pop();

    //         for (auto &nbr : adjListW[frontNode])
    //         {
    //             // nbr.first = node, nbr.second = weight
    //             int node = nbr.first;
    //             int weight = nbr.second;
    //             // udpate the distance accordingly
    //             if (dist[frontNode] + weight < dist[node])
    //             {
    //                 dist[node] = dist[frontNode] + weight;
    //             }
    //         }
    //     }

    //     cout<<"Printing distance array:"<<endl;
    //     for(int i = 0; i < dist.size(); i++){
    //         cout<<i<<" : "<<dist[i]<<endl;
    //     }
    // }

    void ShortestPath_Directed_BFS(int n, int src)
    {
        // Get topological sort as a vector: e.g., {0, 1, 4, 3, 2}
        vector<int> topoOrder = topoSortBFS(n);
        vector<int> dist(n, INT_MAX);

        // Initialize the source distance
        dist[src] = 0;

        // Traverse nodes in topological order
        for (int u : topoOrder)
        {
            // Only process edges if the current node is reachable from the source
            if (dist[u] != INT_MAX)
            {
                for (auto &nbr : adjListW[u])
                {
                    int node = nbr.first;
                    int weight = nbr.second;

                    if (dist[u] + weight < dist[node])
                    {
                        dist[node] = dist[u] + weight;
                    }
                }
            }
        }

        cout << "Printing distance array:" << endl;
        for (int i = 0; i < dist.size(); i++)
        {
            cout << i << " : " << dist[i] << endl;
        }
    }

    void topoSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[src] = true;

        for (const auto &nbr : adjListW[src])
        {
            if (!visited[nbr.first])
            {
                topoSortDFS(nbr.first, visited, s);
            }
        }

        s.push(src);
    }
    void shortestPath_Directed_DFS(int src)
    {
        stack<int> s;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        topoSortDFS(src, visited, s);

        int n = s.size();
        vector<int> distance(n, INT_MAX);

        // intial state
        src = s.top();
        s.pop();
        distance[src] = 0;
        parent[src] = -1;
        // update baki sab
        for (const auto &nbr : adjListW[src])
        {
            int node = nbr.first;
            int weight = nbr.second;

            if (distance[src] + weight < distance[node])
            {
                distance[node] = distance[src] + weight;
                parent[node] = src;
            }
        }

        // main logic
        while (!s.empty())
        {
            int front = s.top();
            s.pop();

            for (const auto &nbr : adjListW[front])
            {
                int node = nbr.first;
                int weight = nbr.second;
                if (distance[front] + weight < distance[node])
                {
                    distance[node] = distance[front] + weight;
                    parent[node] = front;
                }
            }
        }
        
        cout << "Printing path :" << endl;
        int dest = 2;
        while(dest != -1){  
            cout<<dest<<"<-";
            dest = parent[dest];
        }
        // cout << "Printing distance array:" << endl;
        // for (int i = 0; i < distance.size(); i++)
        // {
        //     cout << i << " : " << distance[i] << endl;
        // }
    }
};

int main()
{
    cout << "Hello world" << endl;
    Graph g;
    g.addEdgeW(0, 1, 5, 1);
    g.addEdgeW(0, 2, 13, 1);
    g.addEdgeW(0, 4, 3, 1);
    g.addEdgeW(1, 2, 7, 1);
    g.addEdgeW(1, 4, 1, 1);
    g.addEdgeW(4, 3, 6, 1);
    g.addEdgeW(3, 2, 2, 1);

    int src = 0;
    int dest = 3;
    
    cout<<"with BFS"<<endl;
    g.ShortestPath_Directed_BFS(5, 0);
    cout<<"with DFS"<<endl;
    g.shortestPath_Directed_DFS(0);

    // g.shorTestPathBFS(src, dest);
    return 0;
}