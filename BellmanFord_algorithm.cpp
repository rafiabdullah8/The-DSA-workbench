#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src) {

    // Step 1: Initialize distances
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    // Step 2: Relax all edges (V - 1) times
    for (int i = 1; i <= V - 1; i++) {

        for (auto edge: edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative weight cycle
    for (auto edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
            cout << "Negative weight cycle detected!" << endl;
            return {};
        }
    }

    return dist;
}

int main() {

    int V = 5;

    vector<vector<int>> edges = {
        {1, 3, 2},
        {4, 3, -1},
        {2, 4, 1},
        {1, 2, 1},
        {0, 1, 5}
    };

    int src = 0;

    vector<int> ans = bellmanFord(V, edges, src);

    cout << "Shortest distances from source " << src << ":\n";

    for (int d : ans)
        cout << d << " ";

    return 0;
}
