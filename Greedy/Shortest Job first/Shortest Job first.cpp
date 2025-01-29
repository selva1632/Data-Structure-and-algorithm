// problem link: https://www.geeksforgeeks.org/problems/shortest-job-first/1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        long long waittime = 0;
        long long cputime = 0;
        sort(bt.begin(), bt.end());
        
        for (int i = 0; i < bt.size(); i++) {
            waittime += bt[i];
            cputime += bt[i];
        }
        
        return waittime / bt.size();
    }
};