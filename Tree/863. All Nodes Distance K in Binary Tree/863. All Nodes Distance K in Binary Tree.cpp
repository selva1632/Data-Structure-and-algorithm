// problem link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

#include<iostream>
#include<queue>
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
private:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_map) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();

                if (node->left) {
                    parent_map[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parent_map[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_map;
        markParent(root, parent_map);

        queue<pair<TreeNode*, int>> q;
        unordered_map<TreeNode*, bool> vis;
        vector<int> res;
        q.push({target, 0});
        vis[target] = true;
        

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front().first;
                int dis = q.front().second;
                q.pop();

                if (dis == k) {
                    res.push_back(node->val);
                    break;
                }

                if (node->left != nullptr && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push({node->left, dis + 1});
                }
                if (node->right != nullptr && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push({node->right, dis + 1});
                }
                if (parent_map[node] != nullptr  && !vis[parent_map[node]]) {
                    vis[parent_map[node]] = true;
                    q.push({parent_map[node], dis + 1});
                }
            }
        }

        return res;
    }
};