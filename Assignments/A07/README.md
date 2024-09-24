# Assignment A07 - Priority Queezy

#### Due: 12-06-2024 (Last Day of Class)

## Assignment Overview

- This weeks assignment is focusing on `Priority Queues` (remember `min heap`, `max heap` are basically synonyms for a PQ).
- Queues typically are FIFO, and `PQ's` still are accept based on a "priority" you could get to move closer to the front or get passed up. 

## Requirements

Choose 1 of the following:

- [LeetCode 215: Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- [LeetCode 703: Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
- [LeetCode 295: Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)
- [LeetCode 239: Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
- [LeetCode 502: IPO](https://leetcode.com/problems/ipo/)

## Problem Descriptions

Here are 4-5 **LeetCode problems** that explicitly benefit from using a **priority queue** (min-heap or max-heap):

1. **LeetCode 215: Kth Largest Element in an Array**  
   This problem can be solved efficiently using a priority queue by maintaining a heap of size K to always keep track of the Kth largest element.  
   [Link to problem](https://leetcode.com/problems/kth-largest-element-in-an-array/)

2. **LeetCode 703: Kth Largest Element in a Stream**  
   This is a streaming version of the previous problem, where a priority queue is essential to dynamically maintain the Kth largest element as new numbers are added.  
   [Link to problem](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

3. **LeetCode 295: Find Median from Data Stream**  
   A priority queue is used to maintain two heaps (a max-heap for the lower half and a min-heap for the upper half) to efficiently calculate the median in a data stream.  
   [Link to problem](https://leetcode.com/problems/find-median-from-data-stream/)

4. **LeetCode 239: Sliding Window Maximum**  
   This problem can be optimized with a priority queue (or deque) to find the maximum in each sliding window of a list, maintaining a sliding window of elements in sorted order.  
   [Link to problem](https://leetcode.com/problems/sliding-window-maximum/)

5. **LeetCode 502: IPO**  
   This problem involves selecting projects with the highest profit under a capital constraint, and a priority queue is used to track the most profitable projects as you move through the list.  
   [Link to problem](https://leetcode.com/problems/ipo/)

Each of these problems benefits from the efficient insertion and extraction properties of a priority queue to solve complex tasks like finding the Kth largest element or maintaining dynamic medians.

## Submission

- Make sure you put a folder called A07 in your Assignments folder.
- Of course make a readme based on [HERE](/Users/griffin/Sync/__currentCourses/4883-Programming_Techniques/Resources/03-Readmees/README.md)
- Ensure you get a problem accepted by Leetcode that you can feel good about submitting (its mostly your solution).
