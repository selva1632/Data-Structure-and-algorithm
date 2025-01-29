// problem link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> res;
        vector<int> temp;
        helper(root, res, temp);
        return res;
    }

    void helper(Node* root, vector<vector<int>>& res, vector<int> temp) {
        if (!root) return;

        temp.push_back(root->data);
        if (!root->left && !root->right) {
          res.push_back(temp);
          return;
        }

        helper(root->left, res, temp);
        helper(root->right, res, temp);
    }
};