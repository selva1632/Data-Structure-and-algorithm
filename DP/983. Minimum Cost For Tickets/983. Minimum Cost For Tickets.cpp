// problem link: https://leetcode.com/problems/minimum-cost-for-tickets/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int f(int ind, int reachability, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (ind == days.size()) return 0;
        if (reachability >= days[ind]) return f(ind + 1, reachability, days, costs, dp);
        if (dp[ind] != -1) return dp[ind];

        return dp[ind] = min({
            costs[0] + f(ind + 1, days[ind], days, costs, dp),
            costs[1] + f(ind + 1, days[ind] + 6, days, costs, dp),
            costs[2] + f(ind + 1, days[ind] + 29, days, costs, dp)
        });
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, -1);
        return min({
            costs[0] + f(0, days[0], days, costs, dp),
            costs[1] + f(0, days[0] + 6, days, costs, dp),
            costs[2] + f(0, days[0] + 29, days, costs, dp)
        });
    }
};