// problem link: https://www.geeksforgeeks.org/problems/children-sum-parent/1

#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) { 
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if (!root) return 0;
        
        queue<Node*> q;
        q.push(root);
        int sum = 0;
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            sum = 0;
            if (node->left) {
                sum += node->left->data;
                q.push(node->left);
            }
            if (node->right) {
                sum += node->right->data;
                q.push(node->right);
            }
            
            if (sum != 0 && sum != node->data) {
                return false;
            }
        }
        
        return true;
    }
};