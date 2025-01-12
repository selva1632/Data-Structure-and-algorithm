// problem link: https://leetcode.com/problems/flood-fill/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& image, int i, int j, int target, int color) {
        if (i < 0 || j < 0 || j >= image[0].size() || i >= image.size() || image[i][j] != color) {
            return;
        }
        
        image[i][j] = target;
        dfs(image, i - 1, j, target, color);
        dfs(image, i, j - 1, target, color);
        dfs(image, i + 1, j, target, color);
        dfs(image, i, j + 1, target, color);

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }
        
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};