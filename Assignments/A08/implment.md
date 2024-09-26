## DFS and BFS Examples

|  #  | Name                                   | Description                               |
| :-: | :------------------------------------- | :---------------------------------------- |
|  1  | [implment.md](implment.md)             | [DFS and BFS Examples](implment.md)       |
|  2  | [other_problems.md](other_problems.md) | [DFS and BFS Problems](other_problems.md) |

**Depth-First Search (DFS)** or **Breadth-First Search (BFS)** to traverse
a matrix representation of a graph.

#### Matrix Representation

```python
grid = [["1", "1", "1", "1", "0"],
        ["1", "1", "0", "1", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "0", "0", "0"]]

```

### 1. **DFS (Depth-First Search)**:

DFS explores as far as possible along each branch before backtracking. This can be implemented using recursion or an explicit stack.

#### DFS Implementation:

```python
def dfs(grid, i, j):
    # Check for out of bounds or if the current cell is already visited ('0')
    if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == '0':
        return

    # Mark the current cell as visited
    grid[i][j] = '0'

    # Traverse the neighbors (up, down, left, right)
    dfs(grid, i + 1, j)  # down
    dfs(grid, i - 1, j)  # up
    dfs(grid, i, j + 1)  # right
    dfs(grid, i, j - 1)  # left

# Example usage
grid = [["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"],
        ["1", "1", "0", "0", "0"], ["0", "0", "0", "0", "0"]]

# Traverse the entire grid
for i in range(len(grid)):
    for j in range(len(grid[0])):
        if grid[i][j] == '1':
            dfs(grid, i, j)
```

### 2. **BFS (Breadth-First Search)**:

BFS explores all nodes at the present "depth" level before moving on to nodes at the next depth level. It can be implemented using a queue.

#### BFS Implementation:

```python
from collections import deque

def bfs(grid, i, j):
    queue = deque([(i, j)])
    grid[i][j] = '0'  # Mark the starting cell as visited

    # Directions for up, down, left, right
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    while queue:
        x, y = queue.popleft()

        # Traverse neighbors
        for dx, dy in directions:
            new_x, new_y = x + dx, y + dy

            # Check bounds and if the neighbor is land ('1')
            if 0 <= new_x < len(grid) and 0 <= new_y < len(grid[0]) and grid[new_x][new_y] == '1':
                queue.append((new_x, new_y))
                grid[new_x][new_y] = '0'  # Mark as visited

# Example usage
grid = [["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"],
        ["1", "1", "0", "0", "0"], ["0", "0", "0", "0", "0"]]

# Traverse the entire grid
for i in range(len(grid)):
    for j in range(len(grid[0])):
        if grid[i][j] == '1':
            bfs(grid, i, j)
```

### Explanation of Traversal:

- **DFS**: Explores as deep as possible by going in one direction (e.g., down or right) until it hits a boundary or visited cell, then backtracks and explores other directions. Useful for exploring all connected components of a graph.
- **BFS**: Processes all neighbors first before moving to their neighbors, layer by layer. It uses a queue to keep track of nodes to visit, ensuring all nodes at the current level are visited before moving to the next level.

### Key Concepts:

- **Grid Boundaries**: You need to check that you’re not accessing indices outside of the grid’s boundaries.
- **Visited Marking**: To avoid revisiting the same node, you should mark cells as visited (usually by changing their value, e.g., from `'1'` to `'0'`).
