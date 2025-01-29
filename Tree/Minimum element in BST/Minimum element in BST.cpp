#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        if (!root) return -1;
        if (!root->left && !root->right) return root->data;
        
        return minValue(root->left);
    }
};
