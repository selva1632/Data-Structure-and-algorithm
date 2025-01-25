// problem link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> res;
        if (!root) return res;

        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto node = q.front().first;
            auto level = q.front().second;
            q.pop();
            mpp[level] = node->data;

            if (node->left) {
              q.push({node->left, level - 1});
            }

            if (node->right) {
              q.push({node->right, level + 1});
            }
        }

        for (auto it: mpp) {
          res.push_back(it.second);
        }
        return res;
    }
};