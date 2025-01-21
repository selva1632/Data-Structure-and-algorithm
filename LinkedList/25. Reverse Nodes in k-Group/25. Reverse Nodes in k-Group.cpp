// problem link: 

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;


        while (temp) {
          ListNode* kth = kthNode(temp, k);
          if (kth == nullptr) {
            if (prev) {
              prev->next = temp;
              break;
            }
          }
          ListNode* nextNode = kth->next;
          kth->next = nullptr;
          reverse(temp);

          if (temp == head) {
            head = kth;
          } else {
            prev->next = kth;
          }

          prev = temp;
          temp = nextNode;
        }
        return head;
    }

    ListNode* kthNode(ListNode* head, int k) {
      while (head && --k > 0) {
        head = head->next;
      }
      return head;
    }

    ListNode* reverse(ListNode* head) {
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