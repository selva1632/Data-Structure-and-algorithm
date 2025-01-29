// problem link: https://leetcode.com/problems/minimum-size-subarray-sum

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;

        int left = 0, right = 0, sum = 0, n = nums.size();

        while (right < n) {
            if (nums[right] == target) {
                  return 1;
            }

            sum += nums[right];
            while (sum >= target) {
                  ans = min(ans, right - left + 1);
                  sum -= nums[left];
                  left++;
            }
            right++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};