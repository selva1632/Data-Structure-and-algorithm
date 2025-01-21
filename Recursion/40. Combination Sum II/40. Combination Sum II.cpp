// problem link: https://leetcode.com/problems/combination-sum-ii/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    void f(int ind, int target, vector<int>& candidates, vector<int>&ds, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(ds);
            return;
        }
        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i-1]) continue; 
                if (target < candidates[i]) continue;
                ds.push_back(candidates[i]);
                f(i + 1, target - candidates[i], candidates, ds, res);
                ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        f(0, target, candidates, ds, res);
        return res;
    }
};