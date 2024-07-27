class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int i : arr)
            m[i]++;
        int n = arr.size();
        int x = ceil(float(n) / 4.0);
        for(auto i : m){
            if(i.second >= x)
                return i.first;
        }
        return 0;
    }
};