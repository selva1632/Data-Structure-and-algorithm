// problem link: https://leetcode.com/problems/top-k-frequent-words/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    typedef pair<int, string> pis;

    struct cmp {
        bool operator()(const pis& a, const pis& b) const {
            if (a.first == b.first) {
                return a.second < b.second;
            } return a.first > b.first;
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pis, vector<pis>, cmp> pq; // min heap
        unordered_map<string, int> mpp;

        for (auto it: words) {
            mpp[it]++;
        }

        for (auto it: mpp) { // O(N)
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> res;
        while (!pq.empty()) {  // Nlog(k)
            auto top = pq.top();
            res.push_back(top.second);
            pq.pop();
        }

        reverse(res.begin(), res.end()); // O(k)
        return res;
    }
};

/*

    time complexity - O(Nlog(k))
    space complexity - O(N) + O(K)

*/