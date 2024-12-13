class Solution {
public:
    int maxNonDecreasingLength(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int last = 2; last >= 0; last--) {
                if (last == 2) {
                    dp[index][last] = max({
                        dp[index + 1][2], 
                        1 + dp[index + 1][0], 
                        1 + dp[index + 1][1]
                    });
                } else {
                    if(index > 0) {
                        int prev = (last == 0) ? a[index - 1] : b[index - 1];
                        if (prev <= a[index]) {
                            dp[index][last] = max(dp[index][last], 1 + dp[index + 1][0]);
                        }
                        if (prev <= b[index]) {
                            dp[index][last] = max(dp[index][last], 1 + dp[index + 1][1]);
                        }
                    }
                }
            }
        }

        return dp[0][2];
    }
};
