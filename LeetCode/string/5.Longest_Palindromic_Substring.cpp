class Solution {
public:
    string res = "";
    string longestPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        for(int i = 0; i < n; i++)
        {
            expand(s, i, i + 1);
            expand(s, i, i);
        }
        return res;
    }

    void expand(string &s, int l, int r)
    {
        while(l >= 0 && r < s.size() && s[l] == s[r])
        {

            if((int)res.size() < r - l + 1)
            {
                res = s.substr(l, r - l + 1);
            }
            l--;
            r++;
        }
    }
};
