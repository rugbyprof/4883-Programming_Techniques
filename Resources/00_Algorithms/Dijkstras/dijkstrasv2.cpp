#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = INT_MAX;  // Infinity value for initial distances

// Define a structure to represent edges in the graph
struct Edge {
    int to;
    int weight;
};

// Function to perform Dijkstra's algorithm to find shortest paths
void dijkstra(vector< vector< Edge > >& graph, int start, vector< int >& dist) {
    int n = graph.size();
    dist.assign(n, INF);  // Initialize distances to infinity
    dist[start] = 0;      // Distance from start to itself is 0

    // Create a priority queue (min heap) to select the minimum distance node
    priority_queue< pair< int, int >, vector< pair< int, int > >, greater< pair< int, int > > > pq;

    // Push the start node into the priority queue
    pq.push({0, start});

    while (!pq.empty()) {
        // Get the node with the minimum distance from the priority queue
        int u = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        // If the current distance is greater than the stored distance, skip it
        if (currDist > dist[u]) {
            continue;
        }

        // Explore neighbors of the current node
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // Calculate the new distance from start to v via u
            int newDist = dist[u] + weight;

            // If the new distance is shorter than the stored distance, update it
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});  // Add v to the priority queue
            }
        }
    }
}

int main() {
    int n, m;  // Number of nodes and edges in the graph
    cin >> n >> m;

    vector< vector< Edge > > graph(n);  // Adjacency list representation of the graph

    // Read edges and weights
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});  // For undirected graph, add reverse edges
    }

    int start;  // Starting node for Dijkstra's algorithm
    cin >> start;

    vector< int > dist;  // To store the shortest distances from the start node
    dijkstra(graph, start, dist);

    // Output shortest distances from the start node to all other nodes
    for (int i = 0; i < n; ++i) {
        cout << "Shortest distance from " << start << " to " << i << ": ";
        if (dist[i] == INF) {
            cout << "Infinity" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}