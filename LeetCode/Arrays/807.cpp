class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int skylines_i[51] = {0}; // height of each skyline
        int skylines_j[51] = {0};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                skylines_i[i] = max(skylines_i[i], grid[i][j]);
                skylines_j[j] = max(skylines_j[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] <= min(skylines_i[i], skylines_j[j])) {
                    res += min(skylines_i[i], skylines_j[j]) - grid[i][j];
                }
            }
        }
        return res;
    }
};