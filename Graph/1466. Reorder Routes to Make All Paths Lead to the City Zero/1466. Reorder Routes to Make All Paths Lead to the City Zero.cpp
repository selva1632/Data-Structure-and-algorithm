// problem link: 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<pair<int, int>>> &adj, int node, int parent, vector<int>& vis, int &count) {
        vis[node] = true;

        for (auto &[adjNode, sign]: adj[node]) {
            if (!vis[adjNode]) {
                count += sign;
                dfs(adj, adjNode, node, vis, count);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto it: connections) {
            adj[it[0]].push_back({it[1], 1});
            adj[it[1]].push_back({it[0], 0});
        }
        vector<int> vis(n, 0);    
        int count = 0;
        dfs(adj, 0, -1, vis, count);

        return count;
    }
};