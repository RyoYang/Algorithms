class Solution {
public:
    int get_next(vector<int>& nums1, vector<int>& nums2, int& p1, int& p2)
    {
        if(p1 >= nums1.size()) return nums2[p2++];
        if(p2 >= nums2.size()) return nums1[p1++];

        if(nums1[p1] < nums2[p2]) return nums1[p1++];
        return nums2[p2++];

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), mid = (n + m + 1) >> 1, len = m + n;
        int l = 0, r = 0, res = 0;
        for(int i = 0; i < mid; i++) res = get_next(nums1, nums2, l, r);

        if(len & 1) return res;

        return (res + get_next(nums1, nums2, l, r))/2.0;
    }
};