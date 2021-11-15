class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] == target) return mid;
            if(nums[l] > nums[mid])  // 左大右小 5 4 1 2 3
            {
                if(nums[mid] <= target && nums[r] >= target)
                {
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }else{                 // 左小右大  3 5 4 1 2
                if(nums[l] <= target && nums[mid] >= target)
                {
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
        }
        return nums[l] == target ? l:-1;
    }
};