// problem link: https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            auto node = st.top();
            res.push_back(node->val);
            st.pop();

            if (node->right) {
                st.push(node->right);
            }
            if (node->left) {
                st.push(node->left);
            }
        }

        return res;
    }
};

class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            if (!root) return res;
    
            stack<TreeNode*> st;
            TreeNode* cur = root;
    
            while (!st.empty() || cur) {
                while (cur) {
                    res.push_back(cur->val);
                    st.push(cur);
                    cur = cur->left;
                }
    
                cur = st.top(); st.pop();
                cur = cur->right;
            } 
    
            return res;
        }
    };