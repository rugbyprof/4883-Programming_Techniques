## Assignment 8 - Graphin Sleezy

#### Due: 12-06-2024 (Last Day of Class)

## Assignment Overview

Both DFS and BFS are foundational graph traversal algorithms that can be used in a variety of problems, including those involving connected components, tree traversals, and exploring graph-based data structures. Here are **5 LeetCode problems** that require **graph traversal** (DFS/BFS). I explicitly avoided shortest path or spanning tree algorithms.

## Requirements

Choose 1 of the following:

- [LeetCode 692: Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/)
- [LeetCode 347: Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
- [LeetCode 451: Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)
- [LeetCode 973: K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)
- [LeetCode 1046: Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)

## Problem Descriptions

1. **LeetCode 200: Number of Islands**  
   You need to traverse connected components (islands) in a 2D grid using DFS or BFS.  
   [Problem Link](https://leetcode.com/problems/number-of-islands/)

2. **LeetCode 733: Flood Fill**  
   This is a DFS/BFS problem where you traverse a 2D grid to fill in all connected pixels of the same color.  
   [Problem Link](https://leetcode.com/problems/flood-fill/)

3. **LeetCode 694: Number of Distinct Islands**  
   This builds on the "Number of Islands" problem but focuses on finding distinct island shapes using DFS/BFS traversal.  
   [Problem Link](https://leetcode.com/problems/number-of-distinct-islands/)

4. **LeetCode 841: Keys and Rooms**  
   Here, you traverse rooms represented as nodes in a graph, using DFS/BFS to see if all rooms can be unlocked.  
   [Problem Link](https://leetcode.com/problems/keys-and-rooms/)

5. **LeetCode 797: All Paths From Source to Target**  
   This problem asks you to find all possible paths from the source to the target in a directed acyclic graph using DFS.  
   [Problem Link](https://leetcode.com/problems/all-paths-from-source-to-target/)

---

### Data Structures for Graphs:

- **C++:**

  - A common way to store a graph in C++ is using an **adjacency list**, which can be represented with a vector of vectors or a vector of sets.
  - Example:
    ```cpp
    vector<vector<int>> graph(n); // For n nodes
    graph[0].push_back(1); // Edge from node 0 to node 1
    graph[1].push_back(2); // Edge from node 1 to node 2
    ```

- **Python:**
  - In Python, graphs are typically stored using dictionaries or lists of lists (adjacency lists).
  - Example:
    ```python
    graph = {0: [1, 2], 1: [2], 2: [0, 3]}  # Node 0 connects to 1, 2; etc.
    ```

---

### Pseudocode for Graph Traversal (DFS and BFS):

#### **DFS (Depth First Search)**:

```text
DFS(graph, node, visited):
    if node is not in visited:
        mark node as visited
        for neighbor in graph[node]:
            if neighbor is not visited:
                DFS(graph, neighbor, visited)

# To start DFS traversal:
visited = set()  # or a boolean array if nodes are numbered 0 to N
DFS(graph, start_node, visited)
```

#### **BFS (Breadth First Search)**:

```text
BFS(graph, start_node):
    create a queue and enqueue start_node
    mark start_node as visited
    while the queue is not empty:
        node = dequeue
        for neighbor in graph[node]:
            if neighbor is not visited:
                mark neighbor as visited
                enqueue neighbor
```

## Submission

- Make sure you put a folder called A08 in your Assignments folder.
- Of course make a readme based on [HERE](/Users/griffin/Sync/__currentCourses/4883-Programming_Techniques/Resources/03-Readmees/README.md)
- Ensure you get a problem accepted by Leetcode that you can feel good about submitting (its mostly your solution).
