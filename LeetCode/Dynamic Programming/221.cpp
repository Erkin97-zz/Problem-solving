class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int dp[1000][1000] = {0}, max_dp = 0;
        int maximum_area = 0;
        for (int x1 = 0; x1 < matrix.size(); x1++) {
            for (int y1 = 0; y1 < matrix[x1].size(); y1++) {
                if (matrix[x1][y1] == '1') {
                    if (x1 == 0 || y1 == 0) {
                        dp[x1][y1] = 1;
                    } else {
                        dp[x1][y1] = min(dp[x1 - 1][y1 - 1], 
                                         min(dp[x1 - 1][y1], dp[x1][y1 - 1])) + 1;
                    }
                    max_dp = max(max_dp, dp[x1][y1]);
                }
            }
        }
        return max_dp * max_dp;
    }
};