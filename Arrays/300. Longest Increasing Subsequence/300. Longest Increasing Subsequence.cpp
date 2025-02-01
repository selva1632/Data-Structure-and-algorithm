// problem link: https://leetcode.com/problems/longest-increasing-subsequence/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        int len = 1;
        temp.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (temp.back() < nums[i]) {
                temp.push_back(nums[i]);
                len++;
            } else {
                int lb = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[lb] = nums[i];
            }
        }
        return len;
    }
};

/*
    time complexity - O(nlogn)
    space complexity - O(N)
*/