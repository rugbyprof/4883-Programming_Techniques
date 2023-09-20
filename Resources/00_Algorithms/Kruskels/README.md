# Kruskels

Implementation of Kruskal's algorithm in C++ for finding a minimum spanning tree (MST) in a weighted graph:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent edges in the graph
struct Edge {
    int from;
    int to;
    int weight;
};

// Define a structure to represent a disjoint-set (union-find) data structure
struct DisjointSet {
    vector<int> parent;

    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Initialize each element as its own parent
        }
    }

    // Find the representative (root) of a set
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    // Merge two sets by updating the parent of one to the other
    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

// Function to perform Kruskal's algorithm to find a minimum spanning tree (MST)
vector<Edge> kruskal(vector<Edge>& edges, int n) {
    vector<Edge> mst; // To store the edges of the MST

    // Sort the edges in ascending order based on their weights
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DisjointSet dsu(n); // Create a disjoint-set data structure

    for (const Edge& edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int weight = edge.weight;

        // Check if adding this edge forms a cycle in the MST
        if (dsu.find(u) != dsu.find(v)) {
            mst.push_back(edge); // Add the edge to the MST
            dsu.merge(u, v);     // Merge the sets of u and v
        }
    }

    return mst;
}

int main() {
    int n, m; // Number of nodes and edges in the graph
    cin >> n >> m;

    vector<Edge> edges(m); // Store the edges of the graph

    // Read edges and weights
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    vector<Edge> mst = kruskal(edges, n);

    cout << "Minimum Spanning Tree (MST) Edges:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.from << " " << edge.to << " " << edge.weight << endl;
    }

    return 0;
}
```

This C++ program implements Kruskal's algorithm to find the minimum spanning tree (MST) of a weighted graph. It uses a disjoint-set (union-find) data structure to efficiently determine whether adding an edge creates a cycle in the MST. The MST edges are then printed as output.