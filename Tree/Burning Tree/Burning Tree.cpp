// problem link: 

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  private:
    Node* markParent(Node* root, unordered_map<Node*, Node*>& parent_map, int target) {
        queue<Node*> q;
        Node* targetNode = nullptr;
        q.push(root);

        while (!q.empty()) {
          int size = q.size();

          for (int i = 0; i < size; i++) {
            auto node = q.front();
            q.pop();
            
            if (node->data == target) {
              targetNode = node;
            }
            
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
        return targetNode;
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> parent_map;
        Node* targetNode;
        targetNode = markParent(root, parent_map, target); // marks parent and return the target node;

        unordered_map<Node*, bool> vis;
        queue<Node*> q;
        q.push(targetNode);
        vis[targetNode] = true;

        int time = 0;
        while (!q.empty()) {
          time++;
          int size = q.size();
          for (int i = 0; i < size; i++) {
              auto node = q.front();
              q.pop();

              if (node->left && !vis[node->left]) {
                vis[node->left] = true;
                q.push(node->left);
              }
              if (node->right && !vis[node->right]) {
                vis[node->right] = true;
                q.push(node->right);
              }
              if (parent_map[node] && !vis[parent_map[node]]) {
                vis[parent_map[node]] = true;
                q.push(parent_map[node]);
              }
          }
        }
        return time - 1;
    }
};