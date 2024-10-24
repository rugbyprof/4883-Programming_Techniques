import sys

memo = {}


def min_edit_distance_trace(seq1, seq2):
    if (seq1, seq2) in memo:
        return memo[(seq1, seq2)]

    # Base cases
    if not seq1:
        return len(seq2), ["Insert " + seq2[i] for i in range(len(seq2))]
    if not seq2:
        return len(seq1), ["Delete " + seq1[i] for i in range(len(seq1))]

    # Recursion with memoization
    if seq1[0] == seq2[0]:
        distance, ops = min_edit_distance_trace(seq1[1:], seq2[1:])
        memo[(seq1, seq2)] = (distance, ops)
    else:
        # Substitution
        substitution, sub_ops = min_edit_distance_trace(seq1[1:], seq2[1:])
        sub_ops = ["Substitute {} with {}".format(seq1[0], seq2[0])] + sub_ops

        # Deletion
        deletion, del_ops = min_edit_distance_trace(seq1[1:], seq2)
        del_ops = ["Delete " + seq1[0]] + del_ops

        # Insertion
        insertion, ins_ops = min_edit_distance_trace(seq1, seq2[1:])
        ins_ops = ["Insert " + seq2[0]] + ins_ops

        # Choose the operation with the minimum cost
        min_cost = min(substitution, deletion, insertion)
        if min_cost == substitution:
            memo[(seq1, seq2)] = (1 + substitution, sub_ops)
        elif min_cost == deletion:
            memo[(seq1, seq2)] = (1 + deletion, del_ops)
        else:
            memo[(seq1, seq2)] = (1 + insertion, ins_ops)

    print(f"seq1: {seq1}, seq2: {seq2}, memo: {memo[(seq1, seq2)]}")
    return memo[(seq1, seq2)]


# # Example usage
# seq1 = "AGTCTGACCTAC"
# seq2 = "TATAGTCATGAC"
# distance, operations = min_edit_distance_trace(seq1, seq2)
# print("Minimum edit distance:", distance)
# print("Operations:")
# for op in operations:
#     print(op)

# Read from stdin
for line in sys.stdin:
    ln, str1 = line.strip().split()
    ln2, str2 = input().strip().split()
    print(str1)
    print(str2)
    print(min_edit_distance_trace(str1, str2))

print(memo)
