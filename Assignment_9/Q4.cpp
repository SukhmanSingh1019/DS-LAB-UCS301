#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

int main() {
    int V = 6;
    vector< pair<int,int> > adj[6];

    vector<int> dist(V, INF);

    int source = 0;
    dist[source] = 0;

    set< pair<int,int> > st;
    st.insert(make_pair(0, source));

    while(!st.empty()) {

        pair<int,int> top = *st.begin();
        st.erase(st.begin());

        int currDist = top.first;
        int u = top.second;

        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if(currDist + weight < dist[v]) {

                if(dist[v] != INF) {
                    st.erase( make_pair(dist[v], v) );
                }

                dist[v] = currDist + weight;

                st.insert( make_pair(dist[v], v) );
            }
        }
    }

    cout << "Shortest distances from node " << source << ":\n";
    for(int i = 0; i < V; i++) {
        cout << source << " -> " << i << " = " << dist[i] << "\n";
    }
}

