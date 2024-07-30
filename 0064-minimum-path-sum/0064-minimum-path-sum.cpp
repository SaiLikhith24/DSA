class Solution {
public:
    int fun(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(dp[i][j] != -1) return dp[i][j];
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return INT_MAX;
        int left = INT_MAX;
        if(i > 0)
            left = grid[i][j] + fun(i - 1, j, grid, dp);
        int right = INT_MAX;
        if(j > 0)
            right = grid[i][j] + fun(i, j - 1, grid, dp);

        return dp[i][j] = min(left, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return fun(grid.size() - 1, grid[0].size() - 1, grid, dp);
    }
};