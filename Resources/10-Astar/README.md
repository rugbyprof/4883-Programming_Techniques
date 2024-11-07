## A-Star

The A* (A-Star) algorithm helps in problems that require finding shortest paths, traversing grid layouts, or navigation through obstacles. Here are a few problems from UVA where A* would be an appropriate approach.

### UVa Problems

1. UVa 762 - We Ship Cheap

- Description: This problem involves finding the shortest path between cities with connections represented as an undirected graph. While a simple BFS can solve it, using A\* can help optimize pathfinding in larger graphs, especially if a heuristic (like geographical distance if coordinates were provided) could be incorporated.

2. UVa 10462 - Is There a Second Way Left?

- Description: In this problem, you need to find the shortest path in a graph, but also identify the second-shortest path. Using A\* is beneficial here, as you can apply it with modifications to efficiently find the optimal and near-optimal paths without needing to perform a full search repeatedly.

3. UVa 10181 - 15-Puzzle Problem

- Description: The 15-puzzle problem requires finding the minimum moves to reach the solved configuration. This is a classic use case for A\* since it’s essentially a pathfinding problem in a state space. The heuristic is typically the Manhattan distance between each tile’s current position and its goal position.

4. UVa 11367 - Full Tank?

- Description: This problem involves finding the minimum cost to travel from one city to another with fuel limitations at each city. A\* with a cost heuristic (e.g., distance to destination adjusted for fuel cost) can be used to explore the shortest-cost path more efficiently than traditional Dijkstra or BFS.

5. UVa 2251 - Alien vs. Hunter

- Description: This problem involves navigating a 3D grid (a maze) to find the shortest path from a starting point to an endpoint. A\* is well-suited for 3D grid-based pathfinding, where the heuristic could be the Euclidean or Manhattan distance in the 3D space.

6. UVa 12047 - Highest Paid Toll

- Description: Here, you need to find the shortest path with a toll constraint. The goal is to maximize tolls within the shortest path constraints. A\* can be applied here with a heuristic based on toll values, guiding the search toward paths that meet the requirements optimally.

### Tips for Implementing A\* on UVa Problems

- Grid-Based Problems: For problems on a grid, use Manhattan or Euclidean distance as your heuristic to guide the search.
- Graph-Based Problems: If cities or nodes are connected without clear coordinates, consider using A\* with a simpler heuristic, like the number of edges to the target.
- State-Space Problems: For puzzles like the 15-puzzle, the heuristic should measure the “distance” between each state and the target (e.g., misplaced tiles or Manhattan distance for each tile).

A\* can sometimes be overkill for problems solvable by simpler algorithms like BFS or Dijkstra. However, it shines in more complex or larger instances, especially where an admissible heuristic can significantly reduce the search space.

## A-Star

Like the previous section mentioned, the A-Star algorithm uses a heuristic (e.g. like manhattan distance) to make decisions with. The typical implementation finds the shortest path, even around obstacles, from a starting point to a target point in a 2D grid. However, we could use A-Star to traverse a graph as well and use number of edges as our distance metric especially if edge weights don't exist.

- This implementation is pretty standard: Obstacles are represented as 1's in the grid and paths are represented by 0's in the grid.
- This code uses a Manhattan distance heuristic, which is suitable for grids where movements are restricted to four directions (up, down, left, right).

**A\* Algorithm in C++**

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
    int f, g, h;
    Node* parent;

    Node(int x, int y, int g = 0, int h = 0, Node* parent = nullptr)
        : x(x), y(y), g(g), h(h), f(g + h), parent(parent) {}

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

// Manhattan distance heuristic
int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Check if a point is within the grid and walkable
bool is_valid(int x, int y, const vector<vector<int>>& grid) {
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0;
}

// Reconstruct path from end node
vector<pair<int, int>> reconstruct_path(Node* node) {
    vector<pair<int, int>> path;
    while (node) {
        path.push_back({node->x, node->y});
        node = node->parent;
    }
    reverse(path.begin(), path.end());
    return path;
}

// A* search function
vector<pair<int, int>> a_star(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size(), cols = grid[0].size();

    // Priority queue to hold nodes with the lowest f scores
    priority_queue<Node*, vector<Node*>, greater<Node*>> open_set;

    // Open set and closed set for tracking nodes
    unordered_map<int, Node*> open_map, closed_map;

    // Start node
    Node* start_node = new Node(start.first, start.second, 0, manhattan_distance(start.first, start.second, goal.first, goal.second));
    open_set.push(start_node);
    open_map[start.first * cols + start.second] = start_node;

    // Directions for moving in the grid (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!open_set.empty()) {
        Node* current = open_set.top();
        open_set.pop();
        int current_index = current->x * cols + current->y;

        // Goal check
        if (current->x == goal.first && current->y == goal.second) {
            vector<pair<int, int>> path = reconstruct_path(current);

            // Cleanup dynamic memory
            for (auto& entry : open_map) delete entry.second;
            for (auto& entry : closed_map) delete entry.second;

            return path;
        }

        // Move node from open set to closed set
        open_map.erase(current_index);
        closed_map[current_index] = current;

        // Explore neighbors
        for (auto& dir : directions) {
            int new_x = current->x + dir.first;
            int new_y = current->y + dir.second;

            if (!is_valid(new_x, new_y, grid)) continue;

            int new_g = current->g + 1;
            int new_h = manhattan_distance(new_x, new_y, goal.first, goal.second);
            Node* neighbor = new Node(new_x, new_y, new_g, new_h, current);

            int neighbor_index = new_x * cols + new_y;

            // Skip if already in closed set with a lower or equal f cost
            if (closed_map.count(neighbor_index) && closed_map[neighbor_index]->f <= neighbor->f) {
                delete neighbor;
                continue;
            }

            // Add to open set if not present, or update if a better path is found
            if (!open_map.count(neighbor_index) || open_map[neighbor_index]->f > neighbor->f) {
                open_set.push(neighbor);
                open_map[neighbor_index] = neighbor;
            } else {
                delete neighbor;
            }
        }
    }

    // Cleanup in case of no path found
    for (auto& entry : open_map) delete entry.second;
    for (auto& entry : closed_map) delete entry.second;

    return {};  // Return empty path if no path exists
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    pair<int, int> start = {0, 0};
    pair<int, int> goal = {4, 4};

    vector<pair<int, int>> path = a_star(grid, start, goal);

    if (path.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Path found: ";
        for (const auto& p : path) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
```

### Explanation of Key Components

1. **Node Structure**:

- Each node represents a position on the grid and holds the following:
  - `x` and `y` coordinates.
  - `f`, `g`, and `h` values (`f = g + h`).
  - A pointer to its parent node to reconstruct the path.

2. **Manhattan Distance Heuristic:**

- `manhattan_distance` calculates the heuristic, which is the sum of the absolute differences between the current node’s coordinates and the goal node’s coordinates.
- This heuristic is admissible and works well for grid-based movements restricted to four directions.

3. **Open and Closed Sets**:

- `open_set`: A priority queue that holds nodes to explore, ordered by the lowest `f` value.
- `closed_map`: An unordered map that stores nodes already explored, preventing revisiting.

4. **Path Reconstruction**:

- `reconstruct_path`: traces back from the goal node to the start node by following each node’s parent pointers.

5. **Main A\* Loop**:

- The algorithm iterates by expanding the node with the lowest `f` value in the open set.
- For each neighbor:
  - It checks if it’s already in the closed set with a lower or equal `f` cost.
  - If not, it’s added to the open set or updated if a better path is found.

6. **Dynamic Memory Management**:

- After pathfinding, all dynamically allocated nodes are deleted to prevent memory leaks.

### Running the Program

- The grid variable represents the map, where `0` denotes a walkable cell and `1` denotes an obstacle.
- Modify `start` and `goal` to set different start and end positions.
- The program will print the path found from `start` to `goal`, or indicate if no path exists.

### Notes

- Adaptability: This implementation is designed for 2D grid pathfinding but can be adapted to other types of graphs by modifying the neighbor generation and heuristic functions.
- Memory Management: Ensure proper deletion of dynamically allocated nodes, especially when handling larger grids.
