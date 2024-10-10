## LeetCode 973 - K Closest Points to Origin

[LeetCode Problem 973](https://leetcode.com/problems/k-closest-points-to-origin/description/?envType=problem-list-v2&envId=geometry)

Given an array of points where `points[i] = [xi, yi]` represents a point on the `X-Y` plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the X-Y plane is the Euclidean distance (i.e., `√(x1 - x2)2 + (y1 - y2)2)`.

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:

<img src="https://assets.leetcode.com/uploads/2021/03/03/closestplane1.jpg" width="300">

Input: `points = [[1,3],[-2,2]], k = 1`
Output: `[[-2,2]]`
Explanation:
The distance between `(1, 3)`and the origin is sqrt(10).
The distance between `(-2, 2)` and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), `(-2, 2)` is closer to the origin.
We only want the closest `k = 1` points from the origin, so the answer is just `[[-2,2]]`.

---

Example 2:

Input: points = `[[3,3],[5,-1],[-2,4]]`, `k = 2`
Output: `[[3,3],[-2,4]]`
Explanation: The answer `[[-2,4],[3,3]]` would also be accepted.

**Constraints:**

`1 <= k <= points.length <= 104`
`-104 <= xi, yi <= 104`

---

## Approaches

This problem of finding the **k closest points to the origin** has multiple possible approaches, each varying in terms of efficiency and complexity. The problem itself is a variation of the classic **"closest points"** problem, so multiple algorithms can be applied. Here's a breakdown of three different approaches, ranked from simplest to most efficient:

### 1. Brute Force + Sorting (Worst Approach)

This is the most straightforward approach:

- **Compute the distance** of every point from the origin using the Euclidean distance formula: `(d = sqrt(x^2 + y^2))`. Since comparing distances directly with square roots is computationally expensive, we can compare **squared distances**: `(d^2 = x^2 + y^2)`.
- **Store the distances** in an auxiliary list or dictionary along with their corresponding points.
- **Sort the list** based on the distances.
- **Return the first k points** from the sorted list.

**Steps**:

1. Calculate the squared distance for each point.
2. Sort the points based on the squared distance.
3. Return the first `(k)` points.

**Time Complexity**:

- Sorting dominates this approach with a time complexity of **`(O(n log n))`**, where `(n)` is the number of points.

### 2. **Max Heap Approach (Better Approach)**

Using a **max heap** (priority queue) helps to reduce unnecessary sorting. Instead of sorting all points, you only need to keep track of the closest `(k)` points.

**Steps**:

1. Create a **max heap** of size `(k)`. Each time you add a point, calculate its distance from the origin and insert it into the heap.
2. If the heap size exceeds `(k)`, remove the farthest point (i.e., the one with the largest distance).
3. Once all points are processed, the heap will contain the `(k)` closest points.

**Key Detail**: A max heap helps in efficiently maintaining the `(k)` smallest elements because it allows you to always remove the farthest point in constant time.

**Time Complexity**:

- Building the heap takes **`(O(k))`** initially, and each insertion/removal operation takes **`(O(log k))`**. Since this is done for `(n)` points, the overall time complexity is **`(O(n log k))`**, which is more efficient than sorting for larger `(n)`.

### 3. **Quickselect (Best Approach)**

This approach is based on the **Quickselect** algorithm, which is similar to the **QuickSort** partitioning method. The idea is to find the `(k)`-th smallest element (in terms of distance from the origin) and partition the points around it. This allows you to find the `(k)` closest points without fully sorting the array.

**Steps**:

1. Use the **Quickselect algorithm** to partition the points based on their distance from the origin.
2. After partitioning, the first `(k)` points in the array will be the closest points.
3. There is no need to fully sort the points; Quickselect only partially sorts them.

**Time Complexity**:

- On average, Quickselect runs in **`(O(n))`** time. In the worst case, it can degrade to **`(O(n^2))`**, but with good pivot choices, the expected time is linear.

### Summary of Approaches:

1. **Brute Force + Sorting**: `(O(n log n))` — simplest but least efficient.
2. **Max Heap**: `(O(n log k))` — more efficient, suitable for larger datasets and small `(k)`.
3. **Quickselect**: `(O(n))` on average — most efficient for finding `(k)` closest points.

### Conclusion:

If you're looking for the simplest solution with minimal implementation overhead, the brute force + sorting method works fine. However, if you're looking for more efficiency, the max heap approach or Quickselect will yield better performance, especially when dealing with large datasets or small values of `(k)`.

---

## Code

### C++ Implementation of Quickselect:

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to calculate the squared distance from the origin
int distanceFromOrigin(const vector<int>& point) {
    return point[0] * point[0] + point[1] * point[1];
}

// Partition function for quickselect
int partition(vector<vector<int>>& points, int left, int right, int pivot_index) {
    int pivot_distance = distanceFromOrigin(points[pivot_index]);
    // Move pivot to the end
    swap(points[pivot_index], points[right]);

    int store_index = left;
    for (int i = left; i < right; ++i) {
        if (distanceFromOrigin(points[i]) < pivot_distance) {
            swap(points[store_index], points[i]);
            ++store_index;
        }
    }

    // Move pivot to its final place
    swap(points[right], points[store_index]);
    return store_index;
}

// Quickselect algorithm
void quickselect(vector<vector<int>>& points, int left, int right, int k) {
    if (left < right) {
        // Choose a random pivot index
        int pivot_index = left + rand() % (right - left + 1);

        // Perform partition
        pivot_index = partition(points, left, right, pivot_index);

        // If the pivot is in its correct position
        if (pivot_index == k)
            return;
        else if (pivot_index < k)
            quickselect(points, pivot_index + 1, right, k);
        else
            quickselect(points, left, pivot_index - 1, k);
    }
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    quickselect(points, 0, points.size() - 1, k);
    return vector<vector<int>>(points.begin(), points.begin() + k);
}

int main() {
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    vector<vector<int>> closest_points = kClosest(points, k);

    cout << "The " << k << " closest points to the origin are:\n";
    for (const auto& point : closest_points) {
        cout << "[" << point[0] << ", " << point[1] << "]\n";
    }

    return 0;
}
```

### Python Implementation of Quickselect:

```python
import random

# Function to calculate the squared distance from the origin
def distance_from_origin(point):
    return point[0] ** 2 + point[1] ** 2

# Partition function for quickselect
def partition(points, left, right, pivot_index):
    pivot_distance = distance_from_origin(points[pivot_index])
    # Move pivot to the end
    points[pivot_index], points[right] = points[right], points[pivot_index]

    store_index = left
    for i in range(left, right):
        if distance_from_origin(points[i]) < pivot_distance:
            points[store_index], points[i] = points[i], points[store_index]
            store_index += 1

    # Move pivot to its final place
    points[right], points[store_index] = points[store_index], points[right]
    return store_index

# Quickselect algorithm
def quickselect(points, left, right, k):
    if left < right:
        # Choose a random pivot index
        pivot_index = random.randint(left, right)

        # Perform partition
        pivot_index = partition(points, left, right, pivot_index)

        # If the pivot is in its correct position
        if pivot_index == k:
            return
        elif pivot_index < k:
            quickselect(points, pivot_index + 1, right, k)
        else:
            quickselect(points, left, pivot_index - 1, k)

def k_closest(points, k):
    quickselect(points, 0, len(points) - 1, k)
    return points[:k]

# Example usage
points = [[3, 3], [5, -1], [-2, 4]]
k = 2

closest_points = k_closest(points, k)
print(f"The {k} closest points to the origin are: {closest_points}")
```

### Explanation of the Approach:

- **Partition Function**: The partition function rearranges the points so that all points closer than the pivot (in terms of Euclidean distance) are on the left, and all points farther are on the right.
- **Quickselect**: Similar to QuickSort, but instead of fully sorting the array, it only partially sorts it so that the `k-th` closest point is correctly placed, and all closer points are to its left.

### Time Complexity:

- **Average case**: `O(n)` where `n` is the number of points.
- **Worst case**: `O(n^2)` in rare cases, but you can optimize with better pivot choices.
