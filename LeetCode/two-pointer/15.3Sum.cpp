class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 2) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++)
        {
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                int target = nums[l] + nums[r] + nums[i];
                if(target == 0)
                {
                    vector<int> tmp;
                    tmp.emplace_back(nums[l]);
                    tmp.emplace_back(nums[r]);
                    tmp.emplace_back(nums[i]);

                    res.emplace_back(tmp);
                    while(l < r && nums[l] == tmp[0]) l++;
                    while(l < r && nums[r] == tmp[1]) r--;
                }else if(target < 0){
                    l++;
                }else{
                    r--;
                }
                while(i < n - 2 && nums[i] == nums[i + 1]) i++;
            }
        }
        return res;
    }
};