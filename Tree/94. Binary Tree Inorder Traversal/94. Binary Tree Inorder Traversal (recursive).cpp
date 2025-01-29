// problem link: https://leetcode.com/problems/binary-tree-inorder-traversal/

#include<iostream>
#include<vector>
#include<stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    void inorder(TreeNode* root, vector<int>& res) {
        if (root) {
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }
};