// problem link: https://leetcode.com/problems/subsets-ii/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    void f(int ind, vector<int> &arr, vector<int>& ds, vector<vector<int>>& res) {
        res.push_back(ds);

        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            f(i + 1, arr, ds, res);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ds;
        f(0, nums, ds, res);
        return res;
    }
};