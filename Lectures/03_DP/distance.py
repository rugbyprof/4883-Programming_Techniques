"""
Example usage:
word1 = "AGTCTGACGC"
word2 = "AGTAAGTAGGC"
distance = min_edit_distance(word1, word2)
print(f"Levenshtein distance between '{word1}' and '{word2}': {distance}")
"""


def min_edit_distance(seq1, seq2):
    m, n = len(seq1), len(seq2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if seq1[i - 1] == seq2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1)

    return dp[m][n]



with open("input") as f:
    strings = f.readlines()
    

for i in range(0,len(strings)-1,2):
    # print(strings[i].strip())
    # print(strings[i+1].strip())
    distance = min_edit_distance(strings[i].strip(), strings[i+1].strip())
    print(distance)
