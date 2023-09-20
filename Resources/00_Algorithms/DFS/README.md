# DFS

Implementation of Depth-First Search (DFS) in C++ for traversing a graph:

```cpp
#include <iostream>
#include <vector>
#include <stack>

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

    // Recursive DFS traversal starting from a given vertex
    void DFSRecursive(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " "; // Process the current vertex

        for (int neighbor : adjList[start]) {
            if (!visited[neighbor]) {
                DFSRecursive(neighbor, visited);
            }
        }
    }

    // DFS traversal using an iterative approach (stack)
    void DFSIterative(int start) {
        vector<bool> visited(vertices, false);
        stack<int> stk;

        visited[start] = true;
        stk.push(start);

        while (!stk.empty()) {
            int current = stk.top();
            stk.pop();

            cout << current << " "; // Process the current vertex

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stk.push(neighbor);
                }
            }
        }
    }

    // Perform DFS traversal from all unvisited vertices
    void performDFS() {
        vector<bool> visited(vertices, false);

        // Start DFS from each unvisited vertex
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                cout << "Starting DFS from vertex " << i << ": ";
                DFSRecursive(i, visited);
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

    cout << "DFS Traversal (Recursive): ";
    g.DFSRecursive(0, vector<bool>(6, false));
    cout << endl;

    cout << "DFS Traversal (Iterative): ";
    g.DFSIterative(0);
    cout << endl;

    cout << "Performing DFS from all unvisited vertices:" << endl;
    g.performDFS();

    return 0;
}
```

This C++ program defines a `Graph` structure and provides both recursive and iterative implementations of Depth-First Search (DFS) for traversing a graph. It also demonstrates how to perform DFS from all unvisited vertices in the graph.

## Connected Components Python

Representing connected components in a matrix of 0s and 1s can be done using a Depth-First Search (DFS) or Breadth-First Search (BFS) algorithm. You can approach it like this in Python:

```python
# Assuming you have already read the matrix into a 2D list named 'grid'

def dfs(row, col):
    # Check if the current cell is outside the grid or is not part of the component
    if row < 0 or col < 0 or row >= n or col >= n or grid[row][col] == '0':
        return

    # Mark the current cell as visited by changing it to '0'
    grid[row][col] = '0'

    # Recursively visit all neighboring cells
    for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, -1), (1, -1), (-1, 1)]:
        dfs(row + dr, col + dc)

def count_connected_components(grid):
    n = len(grid)
    components = 0

    for i in range(n):
        for j in range(n):
            if grid[i][j] == '1':
                dfs(i, j)
                components += 1

    return components

# Example usage:
n = 8  # Replace this with the actual size of the grid if its square
grid = [
    "11000111",
    "01001001",
    "10000011",
    "11100100",
    "11000011",
    "10011000",
    "11111110",
    "01010100"
]

components = count_connected_components(grid)
print("Number of connected components:", components)
```

In this code, we perform a depth-first search starting from each '1' in the grid, marking all connected '1's as '0' to avoid double counting. The `count_connected_components` function counts the number of connected components in the grid.

## Connected Components C++

Here's an example in C++:

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Assuming you have already read the matrix into a 2D vector of characters named 'grid'

int n; // Replace this with the actual size of the grid

void dfs(int row, int col, vector<vector<char>>& grid) {
    // Check if the current cell is outside the grid or is not part of the component
    if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] == '0') {
        return;
    }

    // Mark the current cell as visited by changing it to '0'
    grid[row][col] = '0';

    // Recursively visit all neighboring cells
    int dr[] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dc[] = {0, 0, 1, -1, 1, -1, -1, 1};

    for (int i = 0; i < 8; i++) {
        dfs(row + dr[i], col + dc[i], grid);
    }
}

int count_connected_components(vector<vector<char>>& grid) {
    n = grid.size();
    int components = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                dfs(i, j, grid);
                components++;
            }
        }
    }

    return components;
}

int main() {
    // Example usage:
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0', '1', '1', '1'},
        {'0', '1', '0', '0', '1', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '1', '1'},
        {'1', '1', '1', '0', '0', '1', '0', '0'},
        {'1', '1', '0', '0', '0', '0', '1', '1'},
        {'1', '0', '0', '1', '1', '0', '0', '0'},
        {'1', '1', '1', '1', '1', '1', '1', '0'},
        {'0', '1', '0', '1', '0', '1', '0', '0'}
    };

    int components = count_connected_components(grid);
    cout << "Number of connected components: " << components << endl;

    return 0;
}
```
