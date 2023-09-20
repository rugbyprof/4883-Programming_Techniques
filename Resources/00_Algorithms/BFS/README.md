# BFS

Implementation of Breadth-First Search (BFS) in C++ for traversing a graph:

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define a structure to represent a graph (adjacency list)
struct Graph {
    int vertices;
    vector<vector<int>> adjList;

    Graph(int V) : vertices(V) {
        adjList.resize(vertices);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // BFS traversal starting from a given vertex
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " "; // Process the current vertex

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // Perform BFS traversal from all unvisited vertices
    void performBFS() {
        vector<bool> visited(vertices, false);

        // Start BFS from each unvisited vertex
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                cout << "Starting BFS from vertex " << i << ": ";
                BFS(i);
                cout << endl;
            }
        }
    }
};

int main() {
    // Create a sample graph
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout << "BFS Traversal: ";
    g.BFS(0);
    cout << endl;

    cout << "Performing BFS from all unvisited vertices:" << endl;
    g.performBFS();

    return 0;
}
```

This C++ program defines a `Graph` structure and provides an implementation of Breadth-First Search (BFS) for traversing a graph. It also demonstrates how to perform BFS from all unvisited vertices in the graph.