Here are some **LeetCode problems** that commonly require **Depth-First Search (DFS)** or **Breadth-First Search (BFS)** to solve:

### Problems that Use DFS:

1. **LeetCode 200: Number of Islands**

   - **Problem**: Given a 2D grid of '1's (land) and '0's (water), count the number of islands (clusters of connected '1's).
   - **DFS**: You can use DFS to explore each island completely by traversing in all four directions (up, down, left, right) from each cell that contains a '1'.

2. **LeetCode 130: Surrounded Regions**

   - **Problem**: Capture all regions surrounded by 'X' on a 2D grid.
   - **DFS**: This problem involves searching for 'O's on the boundary of the grid and marking connected regions. DFS helps explore connected regions and ensure the proper cells are marked.

3. **LeetCode 695: Max Area of Island**

   - **Problem**: Given a grid, calculate the largest connected area of '1's (islands).
   - **DFS**: Similar to "Number of Islands," but you need to track the size of each connected component using DFS to compute the largest area.

4. **LeetCode 114: Flatten Binary Tree to Linked List**

   - **Problem**: Convert a binary tree into a flattened linked list.
   - **DFS**: A DFS traversal helps modify the binary tree in place by rearranging pointers in a postorder fashion.

5. **LeetCode 79: Word Search**
   - **Problem**: Given a grid of letters, check if a given word can be constructed by sequentially adjacent letters.
   - **DFS**: Use DFS to explore all possible paths in the grid starting from each letter and check if they can form the required word.

---

### Problems that Use BFS:

1. **LeetCode 133: Clone Graph**

   - **Problem**: Given a node in an undirected graph, return a deep copy (clone) of the graph.
   - **BFS**: BFS is commonly used to clone each node and traverse the graph level by level while keeping track of cloned nodes.

2. **LeetCode 102: Binary Tree Level Order Traversal**

   - **Problem**: Traverse a binary tree level by level.
   - **BFS**: A classic BFS problem where you explore all nodes at each level of the binary tree before moving to the next level.

3. **LeetCode 994: Rotting Oranges**

   - **Problem**: Given a grid of fresh and rotten oranges, find how long it takes for all fresh oranges to rot, or return -1 if impossible.
   - **BFS**: Use BFS to simulate the rotting process, treating rotten oranges as starting points and spreading out in all directions level by level.

4. **LeetCode 752: Open the Lock**

   - **Problem**: Given a lock represented by a string of digits, find the minimum number of moves to reach the target configuration from "0000".
   - **BFS**: This is a classic shortest-path problem, which can be solved efficiently using BFS by exploring all possible moves level by level.

5. **LeetCode 127: Word Ladder**
   - **Problem**: Transform one word into another, changing one letter at a time, such that each transformation is a valid word in a given list.
   - **BFS**: Use BFS to find the shortest transformation sequence by exploring all possible one-letter transformations level by level.

---

### When to Use DFS vs BFS:

- **DFS**: Useful when exploring deep connections, traversing all nodes in a component, or searching for all possible paths. DFS is often implemented with recursion or an explicit stack.
- **BFS**: Useful for finding the shortest path or level-order traversal of graphs/trees. BFS ensures that all nodes at the current level are processed before moving to the next level, which is important for problems that require minimal steps.
