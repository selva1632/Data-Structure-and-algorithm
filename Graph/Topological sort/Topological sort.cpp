// problem link:

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfs(int node, vector<vector<int>>& adj, stack<int>& st, vector<int>& vis) {
        vis[node] = 1;
        
        for (auto it: adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, st, vis);
            }
        }
        st.push(node);
    }
    
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n = adj.size();
        vector<int> vis(n, 0);
        stack<int> st;
        
        for (auto i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, st, vis);
            }
        }
        
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
};

/*
    time complexity - O(V + E)
    space complexity - O(V) + O(V)
*/