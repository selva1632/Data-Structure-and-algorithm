// problem link: https://leetcode.com/problems/odd-even-linked-list

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head, *evenHead = head->next, *even = evenHead;

        while (even && even->next) {
          odd->next = even->next;
          odd = odd->next;
          even->next = odd->next;
          even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};
