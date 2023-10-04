# Floyd Warshall

Here's a high-level description of the algorithm:


**Input:**
- Graph G with nodes and weighted edges.

**Output:**
- Shortest distances between all pairs of nodes.

**Initialization:**
- Create a 2D array `dist[][]` where `dist[i][j]` represents the shortest distance from node `i` to node `j`. Initialize all values to infinity except for `dist[i][i]`, which should be set to 0.

**Algorithm:**
1. For each intermediate node `k` in the range of all nodes:
   a. For each pair of nodes `i` and `j` (where `i` is not equal to `j`):
      - Calculate a candidate shortest distance `new_dist = dist[i][k] + dist[k][j]`.
      - If `new_dist` is less than the current `dist[i][j]`, update `dist[i][j]` with `new_dist`.

2. Repeat step 1 for all possible intermediate nodes `k`.

3. The `dist[][]` array now contains the shortest distances between all pairs of nodes in the graph.

**Key Points:**
- The algorithm iteratively considers all nodes as potential intermediates to find shorter paths between any two nodes.
- It uses dynamic programming to maintain and update the shortest distances between pairs of nodes.
- The algorithm works for both directed and undirected graphs, and it can handle negative edge weights, but it does not work with negative cycles.

In summary, Floyd-Warshall is a versatile algorithm for finding all-pairs shortest paths in a weighted graph. It is efficient for small to medium-sized graphs but becomes less practical for very large graphs due to its time complexity of O(V^3), where V is the number of nodes in the graph.

## Implementation

Implementation of the Floyd-Warshall algorithm in C++:

```cpp
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; // A large value to represent infinity

void floydWarshall(vector<vector<int>>& dist, int n) {
    // Initialize the distance matrix with initial values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                dist[i][j] = 0; // Distance from a node to itself is 0
            } else {
                dist[i][j] = INF; // Initialize other distances to infinity
            }
        }
    }

    // Populate the distance matrix based on given inputs (roads)
    int r;
    cin >> r;
    for (int i = 0; i < r; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        dist[u][v] = t; // Update distance for the road from u to v
    }

    // Floyd-Warshall algorithm to compute shortest paths
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    // If there's a shorter path from i to j through k, update the distance
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, q;
    int caseNum = 1;
    while (cin >> n >> q && (n || q)) {
        vector<vector<int>> dist(n, vector<int>(n, 0));

        floydWarshall(dist, n);

        if (caseNum > 1) {
            cout << endl; // Output an empty line between test cases
        }

        cout << "Case #" << caseNum << endl;
        for (int i = 0; i < q; ++i) {
            int s, d;
            cin >> s >> d;
            if (dist[s][d] == INF) {
                cout << "no path" << endl;
            } else {
                cout << dist[s][d] << endl;
            }
        }

        ++caseNum;
    }

    return 0;
}
```

This C++ program takes input for multiple test cases, each representing a city with locations and roads. It uses the Floyd-Warshall algorithm to compute the shortest times between all pairs of locations and then answers queries about the minimum travel time between specified source and destination locations.

Make sure to adjust the input and output methods as needed based on the problem statement and input format for UVa 11463 or any other specific problem.