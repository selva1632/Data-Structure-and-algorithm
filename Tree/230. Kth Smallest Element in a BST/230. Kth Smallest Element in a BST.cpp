// problem link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        dfs(root, k, ans);
        return ans;
    }

    void dfs(TreeNode* root, int &k, int &ans) {
        if (!root) return;

        dfs(root->left, k, ans);
        k--;

        if (k == 0) {
            ans = root->val;
            return;
        }
        dfs(root->right, k, ans);
    }
};