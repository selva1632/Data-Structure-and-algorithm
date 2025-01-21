// problem link: https://bit.ly/3dEvWJD

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        int l = 0, r = nums.size() - 1, ans = INT_MAX, pos = -1;

        while (l <= r) {
          int mid = l + (r - l) / 2;

          if (nums[l] <= nums[mid]) {
            if (ans > nums[l]) {
                pos = l;
                ans = nums[l];
            }
            l = mid + 1;
          } else {
            if (ans > nums[mid]) {
                pos = mid;
                ans = nums[mid];
            }
            r = mid - 1;
          }
        }
        return pos;
    }
};