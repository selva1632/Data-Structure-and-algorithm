// problem link: https://leetcode.com/problems/combination-sum/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    void f(int ind, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &res) {
        if (ind == candidates.size()) {
            if (target == 0) {
                res.push_back(ds);
            }
            return;
        }
        // not take
        f(ind + 1, candidates, target, ds, res);
        // take
        if (candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            f(ind, candidates, target - candidates[ind], ds, res);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        f(0, candidates, target, ds, res);
        return res;
    }
};