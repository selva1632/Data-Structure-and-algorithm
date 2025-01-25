// problem link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return construct(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
    }

    TreeNode* construct(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int instart, int inend, unordered_map<int, int> &mpp) {
        if (pstart > pend || instart > inend) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[pstart]);
        int rootIndex = mpp[root->val];
        int numLeft = rootIndex - instart;

        root->left = construct(preorder, pstart + 1, pstart + numLeft, inorder, instart, rootIndex - 1, mpp);
        root->right = construct(preorder, pstart + numLeft + 1, pend, inorder, rootIndex + 1, inend, mpp);
        return root;
    }
};