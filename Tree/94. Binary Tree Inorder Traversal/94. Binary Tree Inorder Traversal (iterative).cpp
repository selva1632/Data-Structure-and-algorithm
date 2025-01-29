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
        stack<TreeNode*> st;
        vector<int> res;
        if (!root) return res;

        TreeNode* cur = root;

        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};