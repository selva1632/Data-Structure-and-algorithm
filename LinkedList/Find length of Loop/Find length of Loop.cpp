// problem link: https://bit.ly/3dyXL6m

#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution {
  public:
    int countNodesinLoop(Node *head) {
        Node* slow = head, *fast = head;

        while (fast && fast->next) {
          slow = slow->next;
          fast = fast->next->next;

          if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                // start of loop
                int count = 1;
                slow = slow->next;
                while (slow != fast) {
                    slow = slow->next;
                    count++;
                }
                return count;
          }
        }
        return 0;
    }
};