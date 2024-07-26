class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
    if (n == 0) return 0;

    //sort the array:
    sort(nums.begin(), nums.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (nums[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = nums[i];
        }
        else if (nums[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
    }
};