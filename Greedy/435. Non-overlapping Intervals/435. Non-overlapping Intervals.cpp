// problem link: https://leetcode.com/problems/non-overlapping-intervals/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    static bool cmp(const vector<int> &A, const vector<int> &B) {
        return A[1] < B[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int overlap = 0;
        vector<vector<int>> res;
        for (auto interval: intervals) {
            if (res.size() == 0 || res.back()[1] <= interval[0]) {
                res.push_back(interval);
            } else {
                overlap++;
            }
        }
        return overlap;
    }
};