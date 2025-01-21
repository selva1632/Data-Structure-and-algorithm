// problem link: https://leetcode.com/problems/combination-sum-iii/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    void f(int ind, int &k, int target, vector<int>& ds, vector<vector<int>>& res)  {
        if (ds.size() == k) {
            if (target == 0) {
                res.push_back(ds);
            return;
        }
            return;
        }

        for (int i = ind; i <= 9; i++) {
            if (target >= i) {
                ds.push_back(i);
                f(i + 1, k, target - i, ds, res);
                ds.pop_back();
            } 
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ds;
        f(1, k, n, ds, res);
        return res;
    }
};