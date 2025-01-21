// problem link: https://leetcode.com/problems/koko-eating-bananas/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    long long helper(vector<int>& piles, int banana) {
        long long totalTime = 0;

        for (int i = 0; i < piles.size(); i++) {
            totalTime += ceil((double) piles[i] / (double) banana);
        }

        return totalTime;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1000000000;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long x = helper(piles, mid);
            if (x <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};