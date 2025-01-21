// problem link: https://bit.ly/3w6hUaa

#include<iostream>
using namespace std;

class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    DLLNode* reverseDLL(DLLNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        DLLNode* prev = nullptr;
        while (head) {
            DLLNode* next = head->next;
            head->next = prev;
            head->prev = next;

            prev = head;
            head = head->prev;
        }

        return prev;
    }
};