## Assignment 9 - Convex Hull

#### Due: 12-06-2024 (Last Day of Class)

## Assignment Overview

1. **[Erect the Fence (LeetCode 587)](https://leetcode.com/problems/erect-the-fence/)**

   - This problem is a direct convex hull problem where you need to find the smallest convex polygon that encloses all the given points. You can solve it using **Graham's Scan** or **Andrew's Monotone Chain** algorithm. It involves determining the outer boundary of a set of points, much like a traditional convex hull problem [Solution](https://ttzztt.gitbooks.io/lc/jingchiai/erect-the-fence.html).

2. **[The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/)**
   - This problem involves determining the outline of buildings in a 2D plane. Though not explicitly about convex hulls, it requires similar spatial reasoning and geometric approaches to determine the critical points of the "skyline" formed by overlapping buildings [The Skyline solution - LeetCode](https://leetcode.com/problems/the-skyline-problem/solutions/61256/convex-hull/).

These problems focus on spatial data and are suitable for those looking to practice computational geometry and related topics like convex hulls.

## Convex Hull

Here is a Python implementation of **Graham's Scan** algorithm for finding the convex hull of a set of points. This algorithm sorts the points by polar angle with respect to a reference point (usually the one with the lowest y-coordinate), and then processes the points to eliminate those that don't form part of the convex hull.

### Python Implementation of Graham's Scan:

```python
import math

# Helper function to calculate the orientation of three points (p, q, r)
# 0 -> p, q, r are collinear
# 1 -> Clockwise
# 2 -> Counterclockwise
def orientation(p, q, r):
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if val == 0:
        return 0  # collinear
    elif val > 0:
        return 1  # clockwise
    else:
        return 2  # counterclockwise

# Function to compute the square of the distance between two points
def distance(p1, p2):
    return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2

# Graham's scan convex hull algorithm
def graham_scan(points):
    # Step 1: Find the point with the lowest y-coordinate (or leftmost in case of tie)
    start = min(points, key=lambda p: (p[1], p[0]))

    # Step 2: Sort points based on polar angle with 'start' point
    def polar_angle(p):
        return math.atan2(p[1] - start[1], p[0] - start[0])

    sorted_points = sorted(points, key=lambda p: (polar_angle(p), distance(start, p)))

    # Step 3: Initialize the convex hull with the first three points
    hull = [start, sorted_points[1]]

    for p in sorted_points[2:]:
        while len(hull) > 1 and orientation(hull[-2], hull[-1], p) != 2:
            hull.pop()  # Pop last point if we turn clockwise or if collinear
        hull.append(p)

    return hull

# Example usage
points = [(0, 3), (2, 2), (1, 1), (2, 1), (3, 0), (0, 0), (3, 3)]
convex_hull = graham_scan(points)

print("Convex Hull:", convex_hull)
```

### Explanation:

1. **`orientation(p, q, r)`**: This function determines the relative orientation of three points. It returns:

   - `0` if the points are collinear,
   - `1` if they make a clockwise turn,
   - `2` if they make a counterclockwise turn.

2. **`distance(p1, p2)`**: This helper function computes the squared distance between two points (no need for square roots, which are computationally more expensive).

3. **`graham_scan(points)`**: This is the main function that implements Graham's scan. The key steps include:

   - Finding the point with the lowest y-coordinate (to serve as the starting point).
   - Sorting the remaining points by the polar angle relative to the start point.
   - Iterating through the sorted points, adding them to the convex hull, and removing any point that makes a non-left turn (i.e., turns clockwise).

4. **Output**: The function returns a list of points that form the vertices of the convex hull in counterclockwise order.

### Example Input/Output:

For the input points `[(0, 3), (2, 2), (1, 1), (2, 1), (3, 0), (0, 0), (3, 3)]`, the algorithm will output:

```
Convex Hull: [(0, 0), (3, 0), (3, 3), (0, 3)]
```

These are the vertices of the convex hull that enclose all the input points.

### Time Complexity:

- Sorting the points based on polar angle takes **O(n log n)**.
- The main loop that processes the points takes **O(n)**.
  Thus, the overall time complexity is **O(n log n)**, where `n` is the number of input points.
