// problem link: https://leetcode.com/problems/squares-of-a-sorted-array/

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, n = nums.size();
        vector<int> res(n, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[r]) > abs(nums[l])) {
                res[i] = nums[r] * nums[r];
                r--;
            } else {
                res[i] = nums[l] * nums[l];
                l++;
            }
        }
        return res;
    }
};

/*
    time complexity - O(N)
    space complexity - O(1)
*/