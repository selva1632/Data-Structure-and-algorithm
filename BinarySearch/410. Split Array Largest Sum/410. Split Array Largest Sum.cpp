// problem link: https://leetcode.com/problems/split-array-largest-sum/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
private:
    int findIndex(vector<int>& arr, int sum) {
        int index = 1, curSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (curSum + arr[i] <= sum) {
                curSum += arr[i];
            } else {
                index++;
                curSum = arr[i];
            }
        }
        return index;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int index = findIndex(nums, mid);
            if (index > k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};