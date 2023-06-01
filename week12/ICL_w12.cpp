#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(vector<vector<int>>& graph, int source) {
    int n = graph.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, INT_MAX);

    pq.push(make_pair(0, source));
    dist[source] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; ++v) {
            // If there is an edge between u and v and the total distance from source to v through u is shorter
            if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "Shortest time between City " << source << " to City " << i << ": ";
        if (dist[i] == INT_MAX) {
            cout << "Not reachable" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

        dijkstra(graph, 0);
        cout << endl;
    

    return 0;
}
