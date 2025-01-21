// problem link: https://leetcode.com/problems/search-insert-position/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ans = nums.size();

        while (l <= r) {
            int mid = l + (r-l) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } 
        return ans;
    }
};