#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    Node* cur = root;
    int ans = -1;
    while (cur) {
        
        if (cur->data == input) {
            ans = cur->data;
            return ans;
        }
        
        if (cur->data < input) {
            cur = cur->right;
        } else {
            ans = cur->data;
            cur = cur->left;
        }
    }
    return ans;
    
}