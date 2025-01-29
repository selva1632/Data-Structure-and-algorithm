// problem link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto it: nums) {
            add(it);
        }
    }
    
    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
        } else {
            if (pq.top() < val) {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};


// time complexity: O(nlog(k))
// space complexity: O(K)