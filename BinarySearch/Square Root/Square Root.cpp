// problem link: https://bit.ly/3JXtGcE

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
  public:
    int floorSqrt(int n) {
      int l = 0, r = n, ans = -1;

      while (l <= r) {
        int mid = l + (r-l) / 2;

        if (mid * mid <= n) {
          ans = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      return ans;
    }
};