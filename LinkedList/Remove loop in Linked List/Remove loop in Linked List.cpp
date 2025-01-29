// problem link: https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        Node* slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                if (slow == head) {
                    fast = head;
                    
                    while (fast->next != head) {
                        fast = fast->next;
                    }
                    fast->next = nullptr;
                    return;
                }
                
                slow = head;
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
                
                fast->next = nullptr;
            }
        }
    }
};