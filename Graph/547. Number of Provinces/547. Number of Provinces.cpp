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