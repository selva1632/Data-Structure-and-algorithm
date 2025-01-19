// problem link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    int helper(int weight, vector<int>& weights) {
        int sum = 0, noOfday = 1;

        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] <= weight) {
                sum += weights[i];
            } else {
                sum = weights[i];
                noOfday++;
            }
        }
        return noOfday;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (helper(mid, weights) <= days) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};