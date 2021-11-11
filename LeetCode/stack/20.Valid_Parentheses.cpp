class Solution {
public:
    unordered_map<char, char> map = {{'}', '{'}, {')', '('},{']', '['}};
    bool isValid(string s) {
        stack<char> st;

        for(auto c: s)
        {
            if(c == '[' || c == '{' || c == '(')
            {
                st.push(c);
            }else{
                if(st.empty() || st.top() != map[c]) return false;
                else{
                    st.pop();
                }
            }
        }
        if(st.size() != 0) return false;
        return true;
    }
};