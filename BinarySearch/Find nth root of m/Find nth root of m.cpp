// problem link: https://bit.ly/3zWNyrL

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    int getRoot(int mid, int n, int m) {
        long long ans = 1;
        
        for (int i = 1; i <= n; i++) {
            ans*= mid;
            if (ans > m) { return 2;}
        }
        
        if (ans == m) return 1;
        return 0;
    }
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int l = 1, r = m;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            int power = getRoot(mid, n, m);
            if (power == 2) {
                r = mid - 1;
            } else if (power == 1) {
                return mid;
            } else {
                l = mid + 1;
            }
        }
        
        return -1;
    }
};