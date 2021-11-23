class Solution {
public:

    int low_bound(vector<int> nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] >= target)
            {
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return target == nums[l] ? l:-1;
    }

    int up_bound(vector<int> nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1; // mid 向上取整 防止[mid, r] mid + 1 == r 
            if(nums[mid] <= target)
            {
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return target == nums[l] ? l:-1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n <= 0) return {-1, -1};
        int a = low_bound(nums, target);
        if(a == - 1) return {-1, -1};
        int b = up_bound(nums, target);
        return {a, b};
    }
};