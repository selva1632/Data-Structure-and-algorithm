// problem link: https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int width = 0;

        while (!q.empty()) {
            int size = q.size(), start = 0, end = 0;
            long long reducer = q.front().second;

            for (int i = 0; i < size; i++) {
                auto node = q.front().first;
                long long pos = q.front().second - reducer;
                q.pop();

                if (i == 0) {
                    start = pos;
                }
                if (i == size - 1) {
                    end = pos;
                }

                if (node->left) {
                    q.push({node->left, 2 * pos + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * pos + 2});
                }
            }

            width = max(width, end - start + 1);
        }
        return width;
    }
};