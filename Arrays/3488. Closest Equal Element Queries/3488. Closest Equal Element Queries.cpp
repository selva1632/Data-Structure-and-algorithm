// https://leetcode.com/problems/closest-equal-element-queries/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            unordered_map<int, int> leftseen, rightseen;
            int n = nums.size();
            vector<int> dis(n, 1e9);
    
            for (int i = 0; i < 2 * n; i++) {
                if (leftseen.find(nums[i % n]) != leftseen.end()) {
                    dis[i % n] = i - leftseen[nums[i % n]];
                }
                leftseen[nums[i % n]] = i;
            }
    
            for (int j = 2 * n - 1; j >= 0; j--) {
                if (rightseen.find(nums[j % n]) != rightseen.end()) {
                    dis[j % n] = min(dis[j % n], rightseen[nums[j % n]] - j);
                }
                rightseen[nums[j % n]] = j;
            }
    
            vector<int> res;
            for (auto query: queries) {
                if (dis[query] >= n) res.push_back(-1);
                else res.push_back(dis[query]);
            }
    
            return res;
        }
    };

// time complexity - O(N + K)
// space complexity - o(N)