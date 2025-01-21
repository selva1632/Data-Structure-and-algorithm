// problem link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = findFirst(nums, target);
        if (lb == -1) {
            return {-1, -1};
        }
        int rb = findLast(nums, target);
        
        return {lb, rb};
    }
private:
    int findFirst(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (arr[mid] == target) {
                ans = mid;
                r = mid - 1;
            } else if (arr[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
    int findLast(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1, ans = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (arr[mid] == target) {
                    ans = mid;
                    l = mid + 1;
                } else if (arr[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            return ans;
    }
};