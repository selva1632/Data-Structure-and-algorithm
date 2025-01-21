// problem link: https://leetcode.com/problems/is-graph-bipartite/  

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<int>& colors, vector<vector<int>>& adjL, int color) {
        colors[node] = color;

        for (auto it: adjL[node]) {
            if (colors[it] == -1) {
                if (dfs(it, colors, adjL, !color) == false) return false;
            } else if (colors[it] == color) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(i, color, graph, 0) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};