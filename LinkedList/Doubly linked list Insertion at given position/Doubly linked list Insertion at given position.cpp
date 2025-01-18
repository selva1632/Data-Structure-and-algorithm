// problem link: https://bit.ly/3QD4hHs

#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

class Solution {
  public:
    Node *addNode(Node *head, int pos, int data) {
        Node* newNode = new Node(data);
        
        if (pos == 0) {
            newNode->next = head->next;
            newNode->prev = head;
            head->next = newNode;
            head = newNode;
            
            return head;
        } else {
            Node* cur = head;
            for (int i = 0; i < pos; i++) {
                cur = cur->next;
            }
            
            newNode->next = cur->next;
            if (cur->next) {
                cur->next->prev = newNode;
            }                 
            cur->next = newNode;
            newNode->prev = cur;
        }
    
        return head;
    }
};