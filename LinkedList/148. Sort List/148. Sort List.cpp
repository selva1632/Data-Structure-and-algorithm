// problem link: https://leetcode.com/problems/sort-list/

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* sortList(ListNode* head) {
      if (!head || !head->next) return head;

      ListNode* left = head;
      ListNode* middle = findMiddle(head);
      ListNode* right = middle->next;
      middle->next = nullptr;
      
      left = sortList(left);
      right = sortList(right);
      return merge(left, right);
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
            cur->next = l1;
            l1 = l1->next;
            } else {
            cur->next = l2;
            l2 = l2->next;
            }
            cur = cur->next;
        }

        if (l1) {
        cur->next = l1;
        }
        if (l2) {
        cur->next = l2;
        }

        return dummy->next;
    }

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};