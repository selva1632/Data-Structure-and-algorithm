// problem link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

#include<iostream>
#include<map>
#include<set>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        map<int, map<int, multiset<int>>> mpp;
        queue<pair<pair<int, int>, TreeNode*>> q;
        q.push({{0, 0}, root});

        while (!q.empty()) {
            auto node = q.front().second;
            int x = q.front().first.first;
            int y = q.front().first.second;
            q.pop();

            mpp[x][y].insert(node->val);

            if (node->left) {
                q.push({{x -1, y + 1}, node->left});
            }

            if (node->right) {
                q.push({{x + 1, y + 1}, node->right});
            }
        }

         for (auto it: mpp) {
            vector<int> temp;
            for (auto item: it.second) {
                temp.insert(temp.end(), item.second.begin(), item.second.end());
            }
            res.push_back(temp);
        }
        return res;
    }
};