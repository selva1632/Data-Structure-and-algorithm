// problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;

        while (cur) {
            while (cur->next && cur->next->val == cur->val) {
                cur->next = cur->next->next;
            }

            cur = cur->next;
        }

        return head;
    }
};