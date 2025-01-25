// problem link: https://leetcode.com/problems/balanced-binary-tree/

#include<iostream>
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
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }

    int helper(TreeNode* root) {
        if (!root) return 0;

        int left = helper(root->left);
        if (left == -1) return -1;

        int right = helper(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) {
            return -1;
        }

        return max(left, right) + 1;
    }
};