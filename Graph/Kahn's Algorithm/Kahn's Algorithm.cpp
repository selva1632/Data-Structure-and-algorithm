// problem link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    bool topoSort(vector<vector<int>> &adj, int v) {
        vector<int> indegree(v);
        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i); 
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return cnt == v ? false : true;
    }
};