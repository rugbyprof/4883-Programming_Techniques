#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

// Define a structure to represent a graph edge
struct Edge {
    int destination;
    int weight;
};

// Define a structure to represent a graph node
struct Node {
    int  id;
    int  distance;
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

// Dijkstra's algorithm function
void dijkstra(vector< vector< Edge > >& graph, int source) {
    int            N = graph.size();
    vector< int >  distance(N, numeric_limits< int >::max());
    vector< int >  parent(N, -1);
    vector< bool > visited(N, false);

    priority_queue< Node, vector< Node >, greater< Node > > minHeap;
    minHeap.push({source, 0});
    distance[source] = 0;

    while (!minHeap.empty()) {
        Node currentNode = minHeap.top();
        minHeap.pop();

        int u = currentNode.id;
        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                minHeap.push({v, distance[v]});
            }
        }
    }

    // Print the shortest distances and paths
    for (int i = 0; i < N; ++i) {
        if (i != source) {
            cout << "Shortest distance from " << source << " to " << i << ": " << distance[i] << endl;

            // Print the shortest path
            int currentNode = i;
            cout << "Shortest path: " << currentNode;
            while (parent[currentNode] != -1) {
                cout << " <- " << parent[currentNode];
                currentNode = parent[currentNode];
            }
            cout << endl;
        }
    }
}

int main() {
    int N, M, start;
    cin >> N >> M >> start;

    vector< vector< Edge > > graph(N);

    for (int i = 0; i < M; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
    }

    // Run Dijkstra's algorithm
    dijkstra(graph, start);

    return 0;
}
