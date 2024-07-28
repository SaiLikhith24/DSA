class Solution {
public:
    int fun(int i, int prev, vector<int> &nums, vector<vector<int>> &dp){
        if(i == nums.size()){
            return 0;
        }
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int take = INT_MIN;
        if(prev == -1 || nums[prev] < nums[i]){
            take = 1 + fun(i + 1, i, nums, dp);
        }
        int nottake = fun(i + 1, prev, nums, dp);
        dp[i][prev + 1] = max(take, nottake);
        return dp[i][prev + 1];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return fun(0, -1, nums, dp);
    }
};