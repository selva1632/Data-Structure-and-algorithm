// problem link: https://leetcode.com/problems/trapping-rain-water/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, lmax = 0, rmax = 0;
        int water = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (lmax > height[l]) {
                    water += lmax - height[l];
                } else {
                    lmax = height[l];
                }
                l++;
            } else {
                if (rmax > height[r]) {
                    water += rmax - height[r];
                } else {
                    rmax = height[r];
                }
                r--;
            }
        }
        return water;
    }
};