# Prims

Implementation of Prim's algorithm in C++ for finding a minimum spanning tree (MST) in a weighted graph:

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX; // Infinity value for initial distances

// Define a structure to represent edges in the graph
struct Edge {
    int to;
    int weight;
};

// Function to perform Prim's algorithm to find a minimum spanning tree (MST)
int prim(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false); // Keep track of visited nodes
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int minCost = 0; // Initialize the total cost of the MST

    // Push the start node into the priority queue with a distance of 0
    pq.push({0, start});

    while (!pq.empty()) {
        // Get the node with the minimum distance from the priority queue
        int u = pq.top().second;
        int currCost = pq.top().first;
        pq.pop();

        // If the current node has already been visited, skip it
        if (visited[u]) {
            continue;
        }

        // Mark the current node as visited
        visited[u] = true;

        // Add the current edge's weight to the total cost of the MST
        minCost += currCost;

        // Explore neighbors of the current node
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // If the neighbor hasn't been visited and the weight is smaller, add it to the priority queue
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    return minCost;
}

int main() {
    int n, m; // Number of nodes and edges in the graph
    cin >> n >> m;

    vector<vector<Edge>> graph(n); // Adjacency list representation of the graph

    // Read edges and weights
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight}); // For undirected graph, add reverse edges
    }

    int start; // Starting node for Prim's algorithm
    cin >> start;

    int minCost = prim(graph, start);

    cout << "Minimum Spanning Tree (MST) Cost: " << minCost << endl;

    return 0;
}
```

This C++ program implements Prim's algorithm to find the minimum spanning tree (MST) of a weighted graph. It uses an adjacency list representation for the graph and a priority queue (min heap) to efficiently select edges with the minimum weight. The MST cost is calculated and displayed as the output.