// problem link: https://leetcode.com/problems/rotate-list/

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode* ptr = head;

        int n = 1;
        while (ptr->next) {
            ptr = ptr->next;
            n++;
        }
        ptr->next = head;
        k %= n;

        ptr = head;
        for (int i = 0; i < n - k - 1; i++) {
            ptr = ptr->next;
        }

        ListNode* newHead = ptr->next;
        ptr->next = nullptr;

        return newHead;
    }
};