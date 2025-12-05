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

    void BFS(int s) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
          
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};



