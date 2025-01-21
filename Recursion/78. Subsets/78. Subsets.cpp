// problem link: https://leetcode.com/problems/subsets/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    void f(int i, vector<int>& nums, vector<vector<int>>& res,
           vector<int>& ds) {
        if (i == nums.size()) {
            res.push_back(ds);
            return;
        }

        // not take
        f(i + 1, nums, res, ds);

        // take
        ds.push_back(nums[i]);
        f(i + 1, nums, res, ds);
        ds.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        f(0, nums, res, ds);
        return res;
    }
};