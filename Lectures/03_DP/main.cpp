#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to calculate the minimum edit distance between two strings
int min_edit_distance(const string& seq1, const string& seq2) {
    int m = seq1.size();
    int n = seq2.size();

    // Create a 2D vector to store edit distances
    vector<vector<int> > dp(m + 1, vector<int>(n + 1));

    // Initialize the base cases
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;  // Deleting all characters from seq1
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;  // Inserting all characters into seq1
    }

    // Fill in the dp table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // No change needed if characters are the same
            } else {
                int substitution = dp[i - 1][j - 1];  // Substitution cost
                int insertion    = dp[i][j - 1];      // Insertion cost
                int deletion     = dp[i - 1][j];      // Deletion cost
                dp[i][j]         = 1 + min({substitution, insertion, deletion});
            }
        }
    }

    // Return the final result
    return dp[m][n];
}

int main() {
    // string seq1 = "AGTCTGACCTAC";
    // string seq2 = "TATAGTCATGAC";

    // int distance = min_edit_distance(seq1, seq2);
    // cout << "Minimum edit distance between the sequences: " << distance << endl;

    int l1, l2;
    string s1, s2;

    while (cin >> l1 >> s1 >> l2 >> s2) {
        int distance = min_edit_distance(s1, s2);
        cout << distance << endl;
    }

    return 0;
}