class Solution {
public:
    void fun(int i, int target, int sum, vector<int> temp, vector<vector<int>>&res, vector<int> &candidates){
        if(i == candidates.size()){
            if(sum == target) res.push_back(temp);
            return;
        }
        if(sum <= target){
            temp.push_back(candidates[i]);
            fun(i, target, sum + candidates[i], temp, res, candidates);
            temp.pop_back();
        }
        fun(i + 1, target, sum, temp, res, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        fun(0, target, 0, temp, res, candidates);
        return res;
    }
};