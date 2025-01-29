// problem link: https://leetcode.com/problems/k-closest-points-to-origin/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        // max heap
        priority_queue<vector<int>> pq;
        
        for (auto it: points) {
            int x = it[0], y = it[1];
            pq.push({x * x + y * y, x, y});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        for (int i = 0; i < k; i++) {
            vector<int> temp = pq.top();
            pq.pop();
            res.push_back({temp[1], temp[2]});
        }
        return res;
    }
};

// time complexity: O(nlog(K))
// space complexity: O(n) + O(K)