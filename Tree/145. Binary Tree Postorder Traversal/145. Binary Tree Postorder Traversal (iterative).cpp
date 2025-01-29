// problem link: https://leetcode.com/problems/binary-tree-postorder-traversal/

#include<iostream>
#include<vector>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st1, st2;

        st1.push(root);

        while (!st1.empty()) {
            auto node = st1.top();
            st1.pop();
            res.push_back(node->val);

            if (node->left) {
                st1.push(node->left);
            }
            if (node->right) {
                st1.push(node->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};