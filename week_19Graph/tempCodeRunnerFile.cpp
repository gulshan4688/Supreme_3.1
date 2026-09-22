stack<int> s;
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.topoSort(s, i, visited);
        }
    }
