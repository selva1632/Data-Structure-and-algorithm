// problem link: https://leetcode.com/problems/redundant-connection/

#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void join(int u, int v) {
        int ut_u = findParent(parent[u]);
        int ut_v = findParent(parent[v]);
        
        if (ut_u == ut_v) {
            return;
        }

        if (rank[ut_u] < rank[ut_v]) {
            parent[ut_u] = ut_v;
        } else if (rank[ut_u] > rank[ut_v]){
            parent[ut_v] = ut_u;
        } else {
            parent[ut_v] = ut_u;
            rank[ut_u]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds = DisjointSet(n);

        for (auto it: edges) {
            int u = it[0], v = it[1];
            if (ds.findParent(u) == ds.findParent(v)) {
                return it;
            }
            ds.join(u, v);
        }
        return {};
    }   
};

/*
    time complexity - O(N) 
    N - no. of edges
    

    space complexity - O(N) for rank and parent array
*/ 
