// problem link: 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> res;

        for (auto x: nums1) {
            pq.push({x + nums2[0], 0});  // Klog(k)
        }

        while (k-- && !pq.empty()) {  // klog(k)
            int sum = pq.top().first; 
            int pos = pq.top().second;
            pq.pop();
            res.push_back({sum - nums2[pos], nums2[pos]});

            if (pos + 1 < nums2.size()) {
                pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
            }
        }
        return res;
    }
};

/*
    time complexity - O(Klog(k))

    space complexity - O(k)

*/