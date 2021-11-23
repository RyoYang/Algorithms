class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> sub;
        dfs(res, candidates, target, 0, sub, 0);

        return res;
    }

    void dfs( vector<vector<int>> &res, vector<int>& candidates, int target, int sum, vector<int>& sub, int idx)
    {
        if(sum == target)
        {
            res.push_back(sub);
            return ;
        }

        if(sum > target) return ;

        for(int i = idx; i < candidates.size(); i++)
        {
            if(target >= sum + candidates[i])
            {
                sub.push_back(candidates[i]);
                dfs(res, candidates, target, sum + candidates[i], sub, i);
                sub.pop_back();
            }
        }
    }
};