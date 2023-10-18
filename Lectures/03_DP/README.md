## String Distance Metrics

Here are several popular string distance or similarity metrics similar to Levenshtein distance. Here are a few of them:

1. **Edit Distance (Levenshtein Distance)**:
   - The Levenshtein distance measures the minimum number of single-character edits (insertions, deletions, or substitutions) required to change one word into another.

2. **Hamming Distance**:
   - Hamming distance is used to compare two strings of equal length and measures the number of positions at which the corresponding characters differ.

3. **Jaccard Similarity**:
   - Jaccard similarity measures the similarity between two sets by dividing the size of their intersection by the size of their union. It's often used for text document comparison.

4. **Cosine Similarity**:
   - Cosine similarity measures the cosine of the angle between two vectors in a high-dimensional space. It's commonly used for comparing the similarity of text documents represented as vectors.

5. **Jaro-Winkler Distance**:
   - Jaro-Winkler distance is a string similarity metric that considers the number of matching characters and transpositions. It's often used for comparing names or short strings.

6. **Dice Coefficient**:
   - The Dice coefficient is used to measure the similarity between two strings by considering the number of common bigrams (two consecutive characters) between them.

7. **Smith-Waterman Algorithm**:
   - Smith-Waterman is an algorithm for local sequence alignment, often used for comparing biological sequences. It finds the best local alignment (subsequence) between two strings.

8. **Needleman-Wunsch Algorithm**:
   - Similar to Smith-Waterman, the Needleman-Wunsch algorithm is used for global sequence alignment, finding the best alignment between two strings by introducing gaps.

9. **Damerau-Levenshtein Distance**:
   - Damerau-Levenshtein distance extends the Levenshtein distance by including transpositions (swapping adjacent characters) as a valid edit operation.

10. **Gotoh Algorithm**:
   - The Gotoh algorithm is an extension of the Needleman-Wunsch algorithm for global sequence alignment, with adjustments for affine gap penalties.

11. **Minkowski Distance**:
    - Minkowski distance is a generalized distance metric that includes Euclidean distance and Manhattan distance as special cases. It's often used for numerical data but can be adapted for text analysis.

These distance metrics and similarity measures are used in various applications, including spell checking, text comparison, information retrieval, and more, depending on the specific requirements of the task at hand.


## UVA 1207 - AGTC

This problem involves finding the minimum number of operations (insertions, deletions, substitutions) required to transform one DNA sequence into another. 


#### Iterative Min Edit Distance:

```python
def EditDistance(s1, s2):
    # Initialize a matrix to store distances
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    # Initialize the first row and first column
    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j

    # Fill in the matrix
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            cost = 0 if s1[i - 1] == s2[j - 1] else 1
            dp[i][j] = min(
                dp[i - 1][j] + 1,  # Deletion
                dp[i][j - 1] + 1,  # Insertion
                dp[i - 1][j - 1] + cost  # Substitution
            )

    # The bottom-right cell contains the Levenshtein distance
    return dp[m][n]

# Example usage:
word1 = "kitten"
word2 = "sitting"
distance = levenshtein_distance(word1, word2)
print(f"Levenshtein distance between '{word1}' and '{word2}': {distance}")
```

This implementation defines a function `levenshtein_distance` that takes two input strings, `s1` and `s2`, and computes the Levenshtein distance between them. The dynamic programming matrix `dp` is used to store intermediate distances, and the final result is found in `dp[m][n]`, where `m` and `n` are the lengths of the input strings.


## Dynamic Programming 

Many dynamic programming solutions, including the one for calculating edit distance (e.g., Levenshtein distance), can be expressed recursively. The recursive approach is often the most natural way to conceptualize the problem. However, recursive solutions can be inefficient because they may involve redundant computations, recalculating the same subproblems multiple times.

To address this inefficiency, dynamic programming techniques, including memoization and bottom-up (iterative) approaches, are commonly used. The function I provided, `min_edit_distance`, is essentially a bottom-up dynamic programming solution, which avoids redundancy by filling in a table (`dp` array) iteratively.

The versatility of the edit distance algorithm allows it to be applied to various problems beyond just string comparison. It's a fundamental technique for measuring the similarity or dissimilarity between sequences of elements, whether they are characters, numbers, or other entities.

## Recursive Vs Iterative

There are different approaches to solving dynamic programming problems. One is a recursive "top down" approach and the other is an iterative "bottom up" approach.

**Dynamic Programming (DP):**
- Dynamic programming involves solving a problem by breaking it down into smaller subproblems and solving each subproblem only once.
- DP uses a table (typically a 2D array) to store the results of subproblems so that they can be reused when needed.
- The bottom-up approach starts with the smallest subproblems and builds up to the final solution iteratively.

**Memoization:**
- Memoization is a top-down approach where you solve a problem by recursively breaking it into smaller subproblems.
- The key difference is that memoization caches (or memoizes) the results of subproblems in a data structure (e.g., a dictionary) to avoid redundant computations.
- When a subproblem is encountered again, you first check if its result is already memoized. If it is, you retrieve the cached result; otherwise, you solve it and store the result for future use.

#### Recursive Min Edit Distance (memoization):

```python
def min_edit_distance_memoized(seq1, seq2, memo={}):
    if (seq1, seq2) in memo:
        return memo[(seq1, seq2)]

    if not seq1:
        return len(seq2)
    if not seq2:
        return len(seq1)

    if seq1[0] == seq2[0]:
        memo[(seq1, seq2)] = min_edit_distance_memoized(seq1[1:], seq2[1:], memo)
    else:
        substitution = 1 + min_edit_distance_memoized(seq1[1:], seq2[1:], memo)
        deletion = 1 + min_edit_distance_memoized(seq1[1:], seq2, memo)
        insertion = 1 + min_edit_distance_memoized(seq1, seq2[1:], memo)
        memo[(seq1, seq2)] = min(substitution, deletion, insertion)

    return memo[(seq1, seq2)]

# Example usage:
seq1 = "AGTCTGACCTAC"
seq2 = "TATAGTCATGAC"
distance = min_edit_distance_memoized(seq1, seq2)
print("Minimum edit distance between the sequences:", distance)
```

In this memoized version, we use a dictionary `memo` to cache the results of subproblems, and we check if the result for a specific pair of sequences `(seq1, seq2)` is already memoized. If it is, we return the cached result; otherwise, we calculate it and store it in `memo`. This avoids redundant calculations and makes the algorithm more efficient for large sequences.