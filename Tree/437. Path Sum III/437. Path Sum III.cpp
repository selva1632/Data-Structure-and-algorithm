#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        return hasPathSum(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int hasPathSum(TreeNode *root, long long target)
    {
        if (!root) return 0;
        else return (root->val == target ? 1 : 0) +
                   hasPathSum(root->left, target - root->val) +
                   hasPathSum(root->right, target - root->val);
    }
};

/*
    time complexity - O(N * N)
    space complexity - O(N)    
*/