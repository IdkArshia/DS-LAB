#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int src, const vector<vector<pair<int,int>>>& adj, vector<int>& parent) {
    const int INF = 1e9;
    int n = adj.size();
    vector<int> dist(n, INF);
    parent.assign(n, -1);
    dist[src] = 0;
    // min-heap of (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    // Map nodes to indices: A=0, B=1, C=2, D=3, E=4, F=5
    auto idx = [&](char c)->int {
        switch(c) {
            case 'A': return 0;
            case 'B': return 1;
            case 'C': return 2;
            case 'D': return 3;
            case 'E': return 4;
            case 'F': return 5;
        }
        return -1;
    };

    int n = 6;
    vector<vector<pair<int,int>>> adj(n);

    // add undirected edges (both directions)
    auto addEdge = [&](char u, char v, int w){
        int iu = idx(u), iv = idx(v);
        adj[iu].push_back({iv,w});
        adj[iv].push_back({iu,w});
    };

    addEdge('B','A',4);
    addEdge('A','D',8);
    addEdge('B','C',9);
    addEdge('C','D',6);
    addEdge('C','E',14);
    addEdge('D','F',4);
    addEdge('E','F',3);

    int source = idx('B');
    int target = idx('E');
    vector<int> parent;
    vector<int> dist = dijkstra(source, adj, parent);

    // Print distances from source
    cout << "Distances from B:\n";
    char names[] = {'A','B','C','D','E','F'};
    for (int i = 0; i < n; ++i) {
        if (dist[i] >= 1e9) cout << names[i] << ": INF\n";
        else cout << names[i] << ": " << dist[i] << "\n";
    }

    // Reconstruct path B -> ... -> E
    if (dist[target] >= 1e9) {
        cout << "\nNo path from B to E.\n";
    } else {
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) path.push_back(v);
        reverse(path.begin(), path.end());

        cout << "\nShortest path from B to E (distance = " << dist[target] << "):\n";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << names[path[i]];
            if (i + 1 < path.size()) cout << " -> ";
        }
        cout << "\n";
    }

    return 0;
}
