class Solution {
public:
    int LCS(string &str1, string &str2, int n, int m, vector<vector<int>>& dp) {
        if (n == 0 || m == 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];

        if (str1[n - 1] == str2[m - 1]) {
            return dp[n][m] = 1 + LCS(str1, str2, n - 1, m - 1, dp);
        } else {
            return dp[n][m] = max(LCS(str1, str2, n - 1, m, dp), LCS(str1, str2, n, m - 1, dp));
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        LCS(str1, str2, n, m, dp);

        int i = n, j = m;
        string scs = "";

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs += str1[i - 1];
                i--;
            } else {
                scs += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            scs += str1[i - 1];
            i--;
        }
        while (j > 0) {
            scs += str2[j - 1];
            j--;
        }
        reverse(scs.begin(), scs.end());
        return scs;
    }
};
