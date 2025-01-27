// problem link: https://leetcode.com/problems/course-schedule/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        
        for (auto p: prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis, -1)) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &pathVis, int parent) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it: adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis, node)) {
                    return true;
                }
            } else if (pathVis[it] == 1) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
};