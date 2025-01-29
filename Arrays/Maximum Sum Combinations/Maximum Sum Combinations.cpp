// problem link: https://www.interviewbit.com/problems/maximum-sum-combinations/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> res;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int, pair<int, int>>> pq;
    int n = A.size();
    
    for (int i = 0; i < A.size(); i++) {
        pq.push({A[i] + B[n-1], {i, n-1}});
    }
    
    while (C-- > 0) {
        auto top = pq.top(); pq.pop();
        auto sum = top.first;
        auto x = top.second.first;
        auto y = top.second.second;
        
        res.push_back(sum);
        pq.push({A[x] + B[y-1], {x, y - 1}});
    }
    return res;
}
