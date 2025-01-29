// problem link: https://leetcode.com/problems/jump-game-ii/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), start = 0, end = 0, step = 0;

        while (end < n - 1) {
            step++;
            int maxend = end + 1;
            for (int i = start; i <= end; i++) {
                if (i + nums[i] >= n - 1) return step;
                maxend = max(maxend, i + nums[i]);
            }
            start = end + 1;
            end = maxend;
        }
        return step;
    }
};