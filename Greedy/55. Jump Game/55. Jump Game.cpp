// problem link: https://leetcode.com/problems/jump-game/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int i = 0;
        for (; i < nums.size() && i <= reach; i++) {
            reach = max(reach, i + nums[i]);
        }
        return i == nums.size();
    }
};