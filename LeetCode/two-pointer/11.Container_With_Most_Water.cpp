class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        int h = min(height[l], height[r]);

        res = max(res, (r - l) * h);

        while(l < r)
        {
            if(height[l] < height[r])
            {
                l++;
            }else{
                r--;
            }
            h = min(height[l], height[r]);
            res = max(res, (r - l) * h);
        }
        return res;
    }
};