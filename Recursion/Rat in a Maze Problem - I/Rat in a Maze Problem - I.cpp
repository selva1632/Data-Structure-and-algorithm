// problem link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        vector<string> res;
        string path = "";
        dfs(0, 0, mat, path, res);
        return res;
    }
    private:
    void dfs(int i, int j, vector<vector<int>> &mat, string path, vector<string>& res) {
        if (i == mat.size() - 1 && j == mat[0].size() - 1) {
            res.push_back(path);
            return ;
        }
        
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] == 0) 
            return;
            
        mat[i][j] = 0;
        dfs(i - 1, j, mat, path + "U", res);
        dfs(i + 1, j, mat, path + "D", res);
        dfs(i, j - 1, mat, path + "L", res);
        dfs(i, j + 1, mat, path + "R", res);
        mat[i][j] = 1; // backtrack
    }
};