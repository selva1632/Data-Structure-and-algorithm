#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


void helper(Node* root, int &ans, int input) {
    if (!root) return;
    
    if (root->data >= input) {
        ans = root->data;
        helper(root->left, ans, input);
    } else {
        helper(root->right, ans, input);
    }
}

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ans = -1;
    helper(root, ans, input);
    return ans;
}