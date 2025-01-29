// problem link: https://leetcode.com/problems/top-k-frequent-elements/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (auto it: nums) {
            mpp[it]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // nlog(k) -> pushing the k element into the pq
        for (auto it: mpp) {
            pq.push({it.second, it.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // k
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};


// time complexity: O(nlog(k))
// space complexity: O(n) + O(k)