// problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, ans = INT_MAX;

        while (l <= r) {
          int mid = l + (r - l) / 2;

          if (nums[l] <= nums[mid]) {
            ans = min(ans, nums[l]);
            l = mid + 1;
          } else {
            ans = min(ans, nums[mid]);
            r = mid - 1;
          }
        }
        return ans;
    }
};