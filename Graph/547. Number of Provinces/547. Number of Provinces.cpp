// problem link: https://leetcode.com/problems/number-of-provinces/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void dfs(int ind, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[ind] = 1;
        for (int j = 0; j < isConnected.size(); j++) {
            if (ind != j && isConnected[ind][j] == 1) {
                if (visited[j] == false) {
                    dfs(j, isConnected, visited);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();
        vector<int> visited(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }

        return provinces;
    }
};


// using adjacency list

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int> &visited) {
        visited[node] = true;
        for (auto it: adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        // create adjList
        
        vector<int> adjList[V];
        
        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj[0].size(); j++) {
                if (i != j && adj[i][j] == 1) {
                    adjList[i].push_back(j);
                }
            }
        }
        
        vector<int> visited(V, false);
        int provinces = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, adjList, visited);
            }
        }
        return provinces;
    }
};