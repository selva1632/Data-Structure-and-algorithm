// problem link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return NULL;
        ListNode* slow = head, *fast = head->next;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* next = slow->next;
        slow->next = next->next;
        delete next;
        return head;
    }
};