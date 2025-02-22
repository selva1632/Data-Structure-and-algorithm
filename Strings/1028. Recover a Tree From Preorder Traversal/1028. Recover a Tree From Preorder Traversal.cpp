// problem link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

#include<iostream>
#include<vector>
#include<string>
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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> st;
        int i = 0, n = traversal.size();
        while (i < n) {
            int curNum = 0, curLevel = 0;
            while (i < n && traversal[i] == '-') {
                ++curLevel;
                ++i;
            }
            while (i < n && traversal[i] >= '0' && traversal[i] <= '9') {
                curNum = curNum * 10 + traversal[i] - '0';
                ++i;
            }

            TreeNode* node = new TreeNode(curNum);

            while (st.size() > curLevel) {
                st.pop_back();
            }

            if (!st.empty()) {
                if (!st.back()->left) st.back()->left = node;
                else st.back()->right = node;
            }

            st.push_back(node);
        }

        while (st.size() > 1) {
            st.pop_back();
        }
        return st.back();
    }
};

/*
    time complexity: O(N)
    space complexity: O(D) ->  D - depth of the tree
*/