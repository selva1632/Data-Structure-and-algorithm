// problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA, *ptr2 = headB;

        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;

            if (ptr1 == ptr2) {
                return ptr1;
            }
            if (ptr1 == nullptr) {
                ptr1 = headB;
            }

            if (ptr2 == nullptr) { 
                ptr2 = headA;
            }
        }

        return ptr1;
    }
};