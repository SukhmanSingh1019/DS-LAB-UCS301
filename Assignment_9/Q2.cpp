#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;                        
    vector<vector<int>> adj;         

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void DFSUtil(int s, vector<bool>& visited) {
        visited[s] = true;
        cout << s << " ";

        for (int neighbor : adj[s]) {
            if (!visited[neighbor])
                DFSUtil(neighbor, visited);
        }
    }

    void DFS(int s) {
        vector<bool> visited(V, false);
        DFSUtil(s, visited);
        cout << endl;
    }
};


