class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> map;
        int n = s.size();
        int res = 0;
        int l = 0, r = n - 1;
        // abc a 
        for(int l = 0, r = 0; r < n; r++)
        {
            map[s[r]]++;
            while(l < r && map[s[r]] > 1)
            {
                map[s[l++]]--;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
