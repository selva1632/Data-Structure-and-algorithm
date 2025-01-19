// problem link: https://bit.ly/3zuBr66

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
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* head = *head_ref, *cur = head;
        
        while (cur) {
            if (cur->data == x) {
                if (cur->prev != nullptr) {
                    cur->prev->next = cur->next;
                } else {
                    *head_ref = cur->next;
                }
                
                if (cur->next != nullptr) {
                    cur->next->prev = cur->prev;
                }
            }
            cur = cur->next;
        }
    }
};