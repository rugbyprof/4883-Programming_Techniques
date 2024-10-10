## 3102 - Minimize Manhattan Distances

[LeetCode Problem 3102](https://leetcode.com/problems/minimize-manhattan-distances/description/?envType=problem-list-v2&envId=geometry)

You are given an array points representing integer coordinates of some points on a 2D plane, where `points[i] = [xi, yi]`.

The distance between two points is defined as their Manhattan distance:

**The Manhattan Distance between two cells**

```python
 [(xi, yi) , (xj, yj)] = abs(xi - xj) + abs(yi - yj)
```

Return the minimum possible value for maximum distance between any two points by removing exactly one point.

## Approaches

### 1. **Brute Force Approach (Worst Approach)**

This approach involves removing each point one by one and calculating the maximum Manhattan distance between the remaining points. You repeat this process for each point, keeping track of the smallest maximum distance after removing each point.

**Steps:**

- For each point (P<sub>i</sub>) in the set, remove (P<sub>i</sub>).
- Calculate the pairwise Manhattan distances for all remaining points.
- Find the maximum of these distances for each removal.
- Return the minimum value of these maximum distances after testing each point's removal.

**Time Complexity:**

- `(O(n^3))` because for each point removed, you calculate the distance between every other pair of points, leading to a triple nested loop.

### 2. **Sort-Based Approach (Better Approach)**

In this approach, you first compute the Manhattan distance for every pair of points by considering that Manhattan distance between two points `((x_1, y_1))` and `((x_2, y_2))` is `(|x_1 - x_2| + |y_1 - y_2|)`. To simplify computations, you can split the problem into two one-dimensional problems (for x-coordinates and y-coordinates), sort the points, and calculate the maximum distances based on the sorted coordinates.

**Steps:**

- Sort the points by their x-coordinates and by their y-coordinates.
- Find the maximum distance between the first and last points in the sorted lists.
- Remove the first or last point from the sorted lists and recalculate the maximum distance.
- Repeat this process to find the smallest maximum distance after removing one point.

**Time Complexity:**

- `(O(n log n))` because you sort the points and then calculate distances in linear time.

### 3. **Convex Hull/Boundary-Based Heuristic (Best Heuristic)**

This approach takes advantage of the fact that the largest Manhattan distances between points are likely to be between points that are "extreme" (on the boundary or outermost points). The idea is to identify the points that form the boundary of the set of points in terms of their x and y coordinates (i.e., the convex hull of the point set) and consider removing one of these boundary points.

**Steps:**

- Identify the boundary points, which are the points that have the smallest and largest x-coordinates and y-coordinates (this forms a convex boundary around the points).
- Focus on removing one of these boundary points, as they are likely to cause the maximum distance between points.
- After removing each boundary point, calculate the maximum Manhattan distance between the remaining points.
- Return the smallest maximum distance after trying the removal of each boundary point.

**Time Complexity:**

- `(O(n))` for finding the boundary points, and then `(O(n))` for recalculating the maximum distance for each removal.

This heuristic significantly reduces the number of points to consider for removal and is more efficient than the brute force or sort-based approach.
