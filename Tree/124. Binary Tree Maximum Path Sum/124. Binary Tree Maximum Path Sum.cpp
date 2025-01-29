// problem link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        helper(root, maxPath);
        return maxPath;
    }

    int helper(TreeNode* root, int &maxPath) {
        if (!root) return 0;

        int left = max(0, helper(root->left, maxPath));
        int right = max(0, helper(root->right, maxPath));

        maxPath = max(maxPath, root->val + left + right);

        return max(left, right) + root->val;
    }
};