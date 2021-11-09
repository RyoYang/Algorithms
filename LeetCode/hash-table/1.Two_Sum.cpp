class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n = nums.size();
        if(n < 2) return {};
        for(int i = 0; i < n; ++i)
        {
            if(map.count(target - nums[i]))
            {
                return {map[target - nums[i]], i};
            }else{
                map[nums[i]] = i;
            }
        }
        return {};
    }
};
