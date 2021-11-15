class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, base = -1;
        stack<int> st;
        int n = s.size();

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }else{
                if(st.empty()) base = i;
                else{
                    st.pop();
                    res = max(res, i - (st.empty()?base:st.top()));
                }
            }
        }
        return res;
    }
};