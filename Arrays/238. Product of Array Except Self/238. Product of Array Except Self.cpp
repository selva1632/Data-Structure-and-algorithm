// problem link : https://leetcode.com/problems/product-of-array-except-self

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int pre = 1, suf = 1;
            int n = nums.size();
            vector<int> arr(n);
    
            for (int i = 0; i < n; i++) {
                arr[i] = pre;
                pre *= nums[i];
            }
    
            for (int j = n - 1; j >= 0; j--) {
                arr[j] *= suf;
                suf *= nums[j];
            }
    
            return arr;
        }
    };

/*
    time complexity - O(N)
    space complexity - O(1)
*/