// problem link: https://leetcode.com/problems/rearrange-array-elements-by-sign/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1;
        vector<int> res(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res[pos] = nums[i];
                pos+=2;
            } else {
                res[neg] = nums[i];
                neg+=2;
            }
        }
        return res;
    }
};