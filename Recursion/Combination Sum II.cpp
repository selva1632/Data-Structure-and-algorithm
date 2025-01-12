// problem link:  https://leetcode.com/problems/combination-sum-ii/

class Solution {
private:
    void f(int ind, vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& ds) {
            if (target == 0) {
                res.push_back(ds);
                return;
            }

        for (int i = ind; i < candidates.size(); i++) {
            if (ind < i && candidates[i] == candidates[i-1]) continue;
            if (target >= candidates[i]) {
                ds.push_back(candidates[i]);
                f(i + 1, candidates, target - candidates[i], res, ds);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        f(0, candidates, target, res, ds);
        return res;
    }
};