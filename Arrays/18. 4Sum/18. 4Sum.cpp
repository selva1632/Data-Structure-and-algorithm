// problem link: https://leetcode.com/problems/4sum/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i-1] == nums[i]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 && nums[j] == nums[j-1]) continue;

                int l = j + 1, m = n - 1;

                while (l < m) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[l];
                    sum += nums[m];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[m]});
                        l++;
                        m--;

                        while (l < m && nums[l] == nums[l-1]) l++;
                        while (l < m && nums[m] == nums[m+1]) m--;
                    } else if (sum > target) {
                        m--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};