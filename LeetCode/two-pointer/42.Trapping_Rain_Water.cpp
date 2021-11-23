class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if(n <= 1) return 0;
        int l = 0, r = n - 1;
        int h_l = height[l], h_r = height[r];
        int res = 0;

        while(l < r)
        {
            if(h_l <= h_r)
            {
                res += h_l - height[l++];
                h_l = max(h_l, height[l]);
            }else{
                res += h_r - height[r--];
                h_r = max(h_r, height[r]);
            }
        }
        return res;
    }
};