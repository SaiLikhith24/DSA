class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> s;
        for(int i : nums) s.insert(i);
        int cnt = 0;
        int longest = 1;
        for(int i : s){
            if(s.find(i - 1) != s.end()) continue;
            else{
                cnt = 1;
                while(s.find(i + 1) != s.end()){
                    cnt += 1;
                    i += 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};