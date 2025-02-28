class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<vector<char>> d(n + 1, vector<char>(m + 1, 'U')); // Corrected size
        
        // LCS Calculation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    d[i][j] = 'C'; // Diagonal move (match)
                } else {
                    if (dp[i - 1][j] >= dp[i][j - 1]) {
                        dp[i][j] = dp[i - 1][j]; // Take from above
                        d[i][j] = 'U';  // Up direction
                    } else {
                        dp[i][j] = dp[i][j - 1]; // Take from left
                        d[i][j] = 'L';  // Left direction
                    }
                }
            }
        }

        // Backtracking to build the shortest common supersequence
        int i = n, j = m;
        string res = "";
        
        while (i > 0 && j > 0) {
            if (d[i][j] == 'C') {
                res += str1[i - 1];
                i--; j--; // Move diagonally
            } else if (d[i][j] == 'U') {
                res += str1[i - 1];
                i--; // Move up
            } else { // 'L'
                res += str2[j - 1];
                j--; // Move left
            }
        }

        // Add remaining characters
        while (i > 0) {
            res += str1[i - 1];
            i--;
        }
        while (j > 0) {
            res += str2[j - 1];
            j--;
        }

        // Reverse the result as we built it in reverse order
        reverse(res.begin(), res.end());

        return res;
    }
};
