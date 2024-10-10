## LeetCode 335 - Line Crossing

[LeetCode 335: Self Crossing](https://leetcode.com/problems/self-crossing/description/?envType=problem-list-v2&envId=geometry)

You are given an array of integers distance.

You start at the point `(0, 0)` on an `X-Y` plane, and you move `distance[0]` meters to the north, then `distance[1]` meters to the west, `distance[2]` meters to the south, `distance[3]` meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.

Return true if your path crosses itself or false if it does not.

Example 1:

<img src="https://assets.leetcode.com/uploads/2022/12/21/11.jpg">

Input: distance = `[2,1,1,2]`
Output: true
Explanation: The path crosses itself at the point (0, 1).
Example 2:

<img src="https://assets.leetcode.com/uploads/2022/12/21/22.jpgv">

Input: distance = `[1,2,3,4]`
Output: false
Explanation: The path does not cross itself at any point.
Example 3:

<img src="https://assets.leetcode.com/uploads/2022/12/21/33.jpg">

Input: distance = `[1,1,1,2,1]`
Output: true
Explanation: The path crosses itself at the point (0, 0).

#### Constraints:

`1 <= distance.length <= 105`
`1 <= distance[i] <= 105`

---

## Approaches

Here are several approaches to solving this problem of checking whether the path crosses itself on the X-Y plane, from worst to best in terms of efficiency:

### 1. **Brute Force Approach (Worst Approach)**

In this approach, you will track each point visited and check after every move whether the new point has already been visited. The brute-force way to do this would involve storing all points in a list and checking for every point if it has already been visited.

**Steps**:

1. Start from (0, 0) and initialize an empty list to store visited points.
2. For every move in `distance`, calculate the new position.
3. After each move, check if the new point already exists in the list of visited points.
4. If it does, return **True** (the path crosses itself). Otherwise, add the point to the list.
5. If no point is revisited, return **False** after processing all moves.

**Time Complexity**:

- **`(O(n^2))`** because checking if a point has already been visited requires searching through all previously visited points, and there are `(n)` points.

### 2. **Using a Set for Tracking (Better Approach)**

A set allows for **constant-time lookups** (on average), so instead of using a list to track visited points, you can use a set. This will drastically reduce the time it takes to check if a point has already been visited.

**Steps**:

1. Initialize the current position as (0, 0) and create a set to store visited points.
2. For each move in `distance`, compute the new position.
3. After each move, check if the new position is in the set of visited points.
4. If it is, return **True**. Otherwise, add the point to the set.
5. After processing all moves, return **False** if no self-crossing occurs.

**Time Complexity**:

- **`(O(n))`** because both inserting into a set and checking membership in a set are `(O(1))` on average.

### 3. **Using Geometric Boundaries or Bounding Box (Best Approach)**

A more advanced method involves recognizing that the path will cross itself if any horizontal or vertical line segment (formed during movement) intersects with another segment. This can be done without explicitly tracking every single point but rather focusing on the **bounding box** formed by the lines. You can keep track of the segments and check for intersections as you generate new segments.

**Steps**:

1. Initialize the position and maintain the coordinates of the lines (both horizontal and vertical) that are formed as you move.
2. As you move, keep track of the direction and the segments formed by the movements.
3. For each new segment, check if it intersects with any previous segments. If there’s an intersection, return **True**.
4. If all segments are generated without intersections, return **False**.

**Time Complexity**:

- **`(O(n))`**: Each move requires generating a new segment and checking for intersections with previous segments, but this can be done efficiently by only checking for possible intersections in the relevant directions.

### Summary of Approaches:

1. **Brute Force**: `(O(n^2))`, the slowest but easiest to implement. Tracks every visited point in a list.
2. **Set for Tracking**: `(O(n))`, more efficient by using a set for constant-time lookups of visited points.
3. **Geometric Boundaries**: `(O(n))`, the best approach, focusing on detecting intersections between segments directly.

The set-based approach is usually preferred for practical purposes due to its simplicity and efficiency. The geometric boundary method can be more complex to implement but offers additional insights into the nature of the problem (i.e., line segment intersections).
