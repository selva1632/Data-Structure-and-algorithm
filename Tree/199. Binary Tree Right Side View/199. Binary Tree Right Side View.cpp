// problem link: https://leetcode.com/problems/binary-tree-right-side-view/

#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto node = q.front().first;
            auto level = q.front().second;
            q.pop();

            mpp[level] = node->val;
            if (node->left) {
                q.push({node->left, level+1});
            }
            if (node->right) {
                q.push({node->right, level + 1});
            }
        }
        for (auto it: mpp) {
            res.push_back(it.second);
        }
        return res;
    }
};