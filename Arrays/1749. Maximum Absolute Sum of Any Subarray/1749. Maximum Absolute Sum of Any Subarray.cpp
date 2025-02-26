// problem link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int curMin = 0, curMax = 0, minSum = 0, maxSum = 0;
    
            for (int num: nums) {
                curMin = min(num, num + curMin);
                curMax = max(num, num + curMax);
    
                minSum = min(curMin, minSum);
                maxSum = max(curMax, maxSum);
            }
    
            return max(abs(minSum), abs(maxSum));
        }
    };

// time  complexity - O(N)
// space complexity - O(1)