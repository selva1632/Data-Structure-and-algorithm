// problem link: https://leetcode.com/problems/combination-sum/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    void f(int ind, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& res, int target) {
        if (ind == candidates.size()) {
            if (target == 0) {
                res.push_back(ds);
            }
            return;
        }
        // not take 
        f(ind + 1, candidates, ds, res, target);

        // take
        if (candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            f(ind, candidates, ds, res, target - candidates[ind]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        f(0, candidates, ds, res, target);
        return res;
    }
};