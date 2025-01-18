// problem link: https://leetcode.com/problems/sort-colors/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, mid = 0, r = nums.size() - 1;

        while(mid <= r) {
            if (nums[mid] == 0) {
                swap(nums[l], nums[mid]);
                l++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[r]);
                r--;
            }
        }   
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};