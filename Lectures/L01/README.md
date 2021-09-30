10023 - Square 

- Largest and smallest elements in array
  - https://www.sanfoundry.com/cpp-program-find-largest-smallest-elements-array/
- k<sup>th</sup> smallest element
  - https://www.tutorialspoint.com/cplusplus-program-to-find-kth-smallest-element-by-the-method-of-partitioning-the-array
- Largest gap in the array
  - https://www.geeksforgeeks.org/largest-gap-in-an-array/

- https://stackoverflow.com/questions/41904746/why-is-the-maximum-sum-subarray-brute-force-on2


```cpp
for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
        int sum = 0;
        for (int k = i; k <= j; k++)
            sum += a[k];
        if (sum > max)
            max = sum;
    }
If we start at all positions and calculate running sums, it is O(n^2):

....
for(int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
        sum += a[j];
        if (sum > max)
            max = sum;
    }
}
```