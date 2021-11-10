class Solution {
public:
    vector<string> res;
    unordered_map<char, string> hash = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void dfs(string & digits, int cur, int len, string tmp)
    {
        if(cur == len) res.push_back(tmp);

        for(auto c: hash[digits[cur]])
        {
            dfs(digits, cur + 1, len, tmp + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0) return res;
        dfs(digits, 0, n, "");

        return res;
    }
};