// problem link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int>& bloom, int days, int k, int m) {
        int cnt = 0, noOfD = 0;

        for (int i = 0; i < bloom.size(); i++) {
            if (bloom[i] <= days) {
                cnt++; 
            } else {
                noOfD += (cnt / k);
                cnt = 0;
            }
        }
        noOfD += (cnt / k);
        return noOfD >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long rq = m * 1ll * k * 1ll;
        if (rq > bloomDay.size()) return -1;
        int l = 0, r = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            l = min(l, bloomDay[i]);
            r = max(r, bloomDay[i]);
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(bloomDay, mid, k, m)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};