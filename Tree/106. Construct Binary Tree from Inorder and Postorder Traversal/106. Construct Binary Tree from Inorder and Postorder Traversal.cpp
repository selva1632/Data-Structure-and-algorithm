// problem link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include<iostream>
#include<unordered_map>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return construct(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mpp);
    }

    TreeNode* construct(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int pstart, int pend, unordered_map<int, int>& mpp) {

        if (instart > inend || pstart > pend) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(postorder[pend]);
        int rootIndex = mpp[root->val];
        int numLeft = rootIndex - instart;

        root->left = construct(inorder, instart, rootIndex-1, postorder, pstart, pstart + numLeft - 1, mpp);
        root->right = construct(inorder, rootIndex + 1, inend, postorder, pstart + numLeft, pend - 1, mpp);
        return root;
    }
};
