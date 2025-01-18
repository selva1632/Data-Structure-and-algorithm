// problem link: https://leetcode.com/problems/reverse-linked-list/

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *cur = head;

        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }      
        return prev;
    }
};