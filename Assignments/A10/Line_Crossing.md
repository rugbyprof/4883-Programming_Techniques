## Line Crossing

[LeetCode 335: Self Crossing](https://leetcode.com/problems/self-crossing/description/?envType=problem-list-v2&envId=geometry)

### Math Required:

1. **Cartesian Coordinates**: Each movement in the list alters the current position on the X-Y plane. You start at `(0, 0)` and move in a **counter-clockwise direction** based on the distances provided.

   - **North**: Moving `distance[0]` meters changes the position by `(0, +distance[0])`.
   - **West**: Moving `distance[1]` meters changes the position by `(-distance[1], 0)`.
   - **South**: Moving `distance[2]` meters changes the position by `(0, -distance[2])`.
   - **East**: Moving `distance[3]` meters changes the position by `(+distance[3], 0)`.
   - This pattern repeats for subsequent movements in the array.

2. **Line Intersection**: The key mathematical concept here is detecting whether two line segments in a 2D plane intersect. Each movement from one point to another defines a line segment. You must check whether the new line segment formed after each move intersects any of the previous line segments.

3. **Geometric Condition for Intersection**:
   - For two line segments defined by points `(x1, y1)` to `(x2, y2)` and `(x3, y3)` to `(x4, y4)`, there are well-known geometric conditions that can determine if they intersect. This involves checking relative orientations of the points using **cross products** and comparing endpoints to detect overlap.

### High-Level Approach:

1. **Track the Coordinates**: Start at `(0, 0)` and keep track of the current position after every move. For each direction, compute the new position based on the distance and direction (North, West, South, or East).
2. **Store Previous Segments**: Maintain a list of previous line segments (each defined by the starting and ending coordinates after each move).

3. **Check for Intersections**: As you move, check whether the new line segment intersects any of the previous segments. This can be done using geometric formulas that detect intersections between line segments.

4. **Return Result**: If an intersection is detected at any point, return `True` (the path crosses itself). If you complete the entire movement without any intersection, return `False`.

### Algorithm Outline:

1. **Initialize**:

   - Start at `(0, 0)`.
   - Store the current position and maintain a list of previous segments.

2. **Move**:

   - For each move in the `distance[]` array, update the position based on the direction (counter-clockwise: North, West, South, East, repeat).
   - Add the newly formed segment (from the previous position to the new position) to a list of segments.

3. **Check Intersection**:
   - For every new segment formed, check if it intersects with any of the previously stored segments using line segment intersection logic.
4. **Return**:
   - Return `True` if an intersection is found.
   - If no intersections are detected after all moves, return `False`.

### Example:

If the `distance[]` array is `[2, 1, 1, 2]`, the movements would look like this:

1. Move North by 2 → `(0, 0)` to `(0, 2)`
2. Move West by 1 → `(0, 2)` to `(-1, 2)`
3. Move South by 1 → `(-1, 2)` to `(-1, 1)`
4. Move East by 2 → `(-1, 1)` to `(1, 1)`

At this point, the path crosses itself because the segment from `(-1, 1)` to `(1, 1)` intersects with the first segment from `(0, 0)` to `(0, 2)`.

### Cross products

Sure! To determine if two line segments intersect in 2D space, we can use **cross-products** to check the relative orientation of the points that define the segments. Let's break this down step by step.

### Line Segment Definitions:

- Line Segment 1: Points `( A(x_1, y_1) ) and ( B(x_2, y_2) )`
- Line Segment 2: Points `( C(x_3, y_3) ) and ( D(x_4, y_4) )`

### Cross Product and Orientation:

For any two vectors, the cross product helps determine their relative orientation. Specifically, for 2D points, the **sign** of the cross product between vectors tells us whether the angle formed is clockwise, counterclockwise, or collinear.

For three points `( A(x_1, y_1) ), ( B(x_2, y_2) ), and ( C(x_3, y_3) )`, the orientation can be determined using the following determinant:

Orientation`(A, B, C) = (x_2 - x_1) * (y_3 - y_1) - (y_2 - y_1) * (x_3 - x_1)`

- **Positive value**: Points `( A )`, `( B )`, and `( C )` are **counterclockwise**.
- **Negative value**: Points `( A )`, `( B )`, and `( C )` are **clockwise**.
- **Zero**: Points `( A )`, `( B )`, and `( C )` are **collinear**.

### Line Segment Intersection:

When checking if two line segments intersect using the **orientation method**, we check the relative orientation of four points:

- Line segment 1: Points `(A(x_1, y_1)) and (B(x_2, y_2))`
- Line segment 2: Points `(C(x_3, y_3)) and (D(x_4, y_4))`

### Orientation:

Orientation is determined using the cross product between vectors, which gives us the relative position (clockwise, counterclockwise, or collinear) of three points.

1. **Counterclockwise (CCW)**: Points make a left turn.
2. **Clockwise (CW)**: Points make a right turn.
3. **Collinear**: Points are in a straight line.

### Conditions for Intersection:

For two line segments `(AB)` and `(CD)` to intersect, the following conditions must hold:

1. **General Case**:

   - The points `(A)` and `(B)` must have **different orientations** relative to line segment `(CD)`.
   - The points `(C)` and `(D)` must have **different orientations** relative to line segment `(AB)`.

   In this case, the line segments intersect because the two pairs of points lie on opposite sides of each other.

   - Compute orientations:

     - Orientation of `(A)`, `(B)`, and `(C)` (`O1`)
     - Orientation of `(A)`, `(B)`, and `(D)` (`O2`)
     - Orientation of `(C)`, `(D)`, and `(A)` (`O3`)
     - Orientation of `(C)`, `(D)`, and `(B)` (`O4`)

   - If:

     `O1 != O2 && O3 != O4`

     the segments **intersect**.

2. **Special Case (Collinearity)**:
   If the points are **collinear**, the cross product between vectors is zero. In this case, additional checks are needed to see if the segments overlap on the same line.

   For collinear cases:

   - Check if the **x** or **y** coordinates of one segment fall within the range of the other segment to detect overlap.

### Conditions for Line Intersection (Take 2):

Two line segments `( AB )` and `( CD )` intersect if:

1. The points `( A )` and `( B )` are on opposite sides of the line segment `( CD )` (i.e., `( C )`, `( D)`, and `( A )`, `( B )` form different orientations).
2. Similarly, the points `( C )` and `( D)` are on opposite sides of the line segment `( AB )`.

### Example with Cross Products:

Let's take two line segments:

- Segment 1: `( A(1, 1) ), ( B(4, 4) )`
- Segment 2: `( C(1, 8) ), ( D(2, 4) )`

Now let's compute the orientations:

#### 01

- Orientation of `( A )`, `( B )`, and `( C )`:
  - Orientation(A, B, C) = `(4 - 1) * (8 - 1) - (4 - 1) * (1 - 1) = 3 * 7 - 3 * 0 = 21`
  - Since the result is positive, the points are **counterclockwise**.

#### 02

- Orientation of `( A )`, `( B )`, and `( D)`:
  - Orientation(A, B, D) = `(4 - 1) * (4 - 1) - (4 - 1) * (2 - 1) = 3 * 3 - 3 * 1 = 6`
  - This is also positive, so the points are **counterclockwise**.

#### 03

- Orientation of `( C )`, `( D)`, and `( A )`:
  - Orientation(C, D, A) = `(2 - 1) * (1 - 8) - (4 - 8) * (1 - 1) = 1 * (-7) - (-4) * 0 = -7`
  - The result is negative, so the points are **clockwise**.

#### 04

- Orientation of `( C )`, `( D)`, and `( B )`:
- Orientation(C, D, B) = `(2 - 1) * (4 - 8) - (4 - 8) * (4 - 1) = 1 * (-4) - (-4) * 3 = -4 + 12 = 8`
- This is positive, so the points are **counterclockwise**.

### Result:

- (O1) is **counterclockwise** and (O2) is **counterclockwise**.
- (O3) is **clockwise** and (O4) is **counterclockwise**.

Since **O1 = O2** (both are counterclockwise), and **O3 ≠ O4**, the segments do **not intersect**.

### General Algorithm for Line Segment Intersection:

1. Compute the orientation for the four combinations of points.
2. If the orientations differ for the two pairs, the segments intersect.
3. Additionally, handle the special case where some points are collinear and overlap on the same line segment.
