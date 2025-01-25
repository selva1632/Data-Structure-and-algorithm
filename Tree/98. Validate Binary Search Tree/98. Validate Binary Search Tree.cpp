// problem link: https://leetcode.com/problems/validate-binary-search-tree

#include<iostream>
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
    bool isValidBST(TreeNode* root) {
        return isvalid(LONG_MIN, LONG_MAX, root);
    }
private:
    bool isvalid(long long min, long long max, TreeNode* root) {
        if (!root) return true;
        else if (root->val <= min || root->val >= max) return false;
        return isvalid(min, root->val, root->left) && isvalid(root->val, max, root->right);
    }
};