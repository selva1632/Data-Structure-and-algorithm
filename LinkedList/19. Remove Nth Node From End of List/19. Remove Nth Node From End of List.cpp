// problem link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;
        for (int i = 0; i < n; i++) {
          fast = fast->next;
        }

        if (!fast) return head->next;

        while (fast && fast->next) {
          slow = slow->next;
          fast = fast->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};