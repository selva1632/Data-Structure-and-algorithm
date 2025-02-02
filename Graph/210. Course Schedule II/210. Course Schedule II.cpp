// problem link: https://leetcode.com/problems/course-schedule-ii/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto p: prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        vector<int> indegree(numCourses, 0), res;
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            for (auto it: adj[i]) {
                indegree[it]++;
            }
        }

        for (int i = numCourses - 1; i >= 0; i--) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            cnt++;
            res.push_back(node);

            for(auto it: adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if (cnt != numCourses) return {};
        reverse(res.begin(), res.end());
        return res;
    }
};

/*
    time complexity - O(V + E)
    space complexity - O(V) + O(V * V)
*/