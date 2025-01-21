// problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode* next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head), *cur = dummy;

        while (head) {
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                cur->next = head->next;
            } else {
                cur = cur->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};