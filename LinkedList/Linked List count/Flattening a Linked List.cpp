// problem link: https://bit.ly/3w9TKf8

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

typedef pair<int, Node*> pii;
class Solution {
  public:
    Node *flatten(Node *root) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        while (root) {
            Node* next = root->next;
            pq.push({root->data, root});
            while (root->bottom) {
                pq.push({root->bottom->data, root->bottom});
                root->bottom = root->bottom->bottom;
            }
            root = next;
        }
        
        Node* dummy = new Node(0), *cur = dummy;
        while (!pq.empty()) {
            cur->bottom = pq.top().second;
            pq.pop();
            cur = cur->bottom;
        }
        
        return dummy->bottom;
    }
};