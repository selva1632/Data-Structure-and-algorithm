// problem link: https://leetcode.com/problems/boundary-of-binary-tree/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

bool isLeaf(TreeNode<int> *root) {
    return !root->left && !root->right;
}

void addLeft(TreeNode<int> *root, vector<int> &res) {
    auto cur = root;

    while (cur) {
        if (!isLeaf(cur)) res.push_back(cur->data);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addRight(TreeNode<int> *root, vector<int> &res) {
    auto cur = root;
    vector<int> temp;

    while (cur) {
        if (!isLeaf(cur)) temp.push_back(cur->data);
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

void addLeaf(TreeNode<int> *root, vector<int> &res) {
    if (!root) return;

    if (isLeaf(root)) res.push_back(root->data);
    addLeaf(root->left, res);
    addLeaf(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int> *root) {
    vector<int> res;
    if (!root) return res;

    if (!isLeaf(root)) res.push_back(root->data);    
    addLeft(root->left, res);
    addLeaf(root, res);
    addRight(root->right, res);
    return res;
}