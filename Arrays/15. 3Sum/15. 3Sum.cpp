// problem link: https://leetcode.com/problems/3sum/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i];
                sum += nums[j];
                sum += nums[k];

                if (sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return res;
    }
};