#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<char, vector<char>> graph = {
    {'A', {'B','C'}},
    {'B', {'D','E'}},
    {'C', {'F'}},
    {'D', {}},
    {'E', {'F'}},
    {'F', {}}
};

vector<char> nodes = {'A','B','C','D','E','F'};

void printAdjList() {
    cout << "Adjacency List:\n";
    for (auto &p : graph) {
        cout << p.first << " -> ";
        for (char x : p.second) cout << x << " ";
        cout << endl;
    }
}

void printAdjMatrix() {
    cout << "\nAdjacency Matrix:\n";
    int n = nodes.size();
    int mat[10][10] = {0};

    for (int i = 0; i < n; i++) {
        for (char v : graph[nodes[i]]) {
            int j = find(nodes.begin(), nodes.end(), v) - nodes.begin();
            mat[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

vector<char> BFS(char start) {
    vector<char> order;
    queue<char> q;
    map<char, bool> vis;

    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        char u = q.front(); q.pop();
        order.push_back(u);

        for (char v : graph[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return order;
}

void DFSUtil(char u, map<char,bool> &vis, vector<char> &order) {
    vis[u] = true;
    order.push_back(u);

    for (char v : graph[u])
        if (!vis[v])
            DFSUtil(v, vis, order);
}

vector<char> DFS(char start) {
    map<char, bool> vis;
    vector<char> order;
    DFSUtil(start, vis, order);
    return order;
}

int main() {
    printAdjList();
    printAdjMatrix();

    auto bfsOrder = BFS('A');
    auto dfsOrder = DFS('A');

    cout << "\nBFS: ";
    for (char x : bfsOrder) cout << x << " ";

    cout << "\nDFS: ";
    for (char x : dfsOrder) cout << x << " ";
}
