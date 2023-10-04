# Dijkstra's

Implementation of Dijkstra's algorithm in C++ for finding the shortest paths in a weighted graph:

**Dijkstra's Algorithm:**

**Input: **
- Graph G with nodes and weighted edges.
- Source node s.

**Output:**
- Shortest distance from s to all other nodes.
- Shortest paths from s to all other nodes.

**Initialization:**
- Create an empty set S to keep track of visited nodes.
- Create an array dist[] to store the shortest distances from s to each node.
  - Initialize dist[s] to 0, and dist[v] to infinity for all other nodes v.
- Create an array prev[] to store the previous node on the shortest path from s to each node.
  - Initialize prev[v] to undefined for all nodes.

**Algorithm:**
1. While S does not contain all nodes:
   - Select the node u not in S with the smallest dist[u].

2. Add u to S.

3. For each neighbor v of u:
   - Calculate a tentative distance new_dist = dist[u] + weight(u, v), where weight(u, v) is the weight of the edge between u and v.
   - If new_dist is less than dist[v]:
     - Update dist[v] = new_dist.
     - Set prev[v] = u.

4. Repeat steps 1-3 until S contains all nodes or if the smallest distance in the remaining nodes is infinity.

5. The algorithm is complete, and dist[] contains the shortest distances from s to all nodes, while prev[] contains the previous nodes on the shortest paths.

To find the shortest path from s to a specific node t, you can backtrack from t using prev[].

Note: Dijkstra's algorithm works with non-negative edge weights. If negative weights are present and there are negative weight cycles, consider using the Bellman-Ford algorithm.


```cpp

```

This C++ program implements Dijkstra's algorithm to find the shortest paths from a specified starting node to all other nodes in a weighted graph. It uses an adjacency list representation for the graph and a priority queue (min heap) to efficiently select nodes with the minimum distance.