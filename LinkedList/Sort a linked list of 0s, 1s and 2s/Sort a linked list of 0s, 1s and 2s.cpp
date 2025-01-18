// problem link: https://bit.ly/3Ceotvr

#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // Add code here
        Node *zeroHead, *zero, *oneHead, *one, *twoHead, *two;
        zeroHead = zero = oneHead = one = twoHead = two = nullptr;
        
        while (head) {
            if (head->data == 0) {
              if (zeroHead == nullptr) {
                zeroHead = zero = head;
              } else {
                zero->next = head;
                zero = zero->next;
              }
            } else if (head->data == 1) {
              if (oneHead == nullptr) {
                oneHead = one = head;
              } else {
                one->next = head;
                one = one->next;
              }
            } else {
              if (twoHead == nullptr) {
                twoHead = two = head;
              } else {
                two->next = head;
                two = two->next;
              }
            }
            head = head->next;
        }

        if (zero) zero->next = nullptr;
        if (one) one->next = nullptr;
        if (two) two->next = nullptr;

        if (zeroHead) {
          if (oneHead && twoHead) {
            zero->next = oneHead;
            one->next = twoHead;
          } else if (oneHead) {
            zero->next = oneHead;
          } else {
            zero->next = twoHead;
          }
          return zeroHead;
        } else if (oneHead) {
          if (twoHead) {
            one->next = twoHead;
          }
          return oneHead;
        } else {
          return twoHead;
        }
        return nullptr;
    }
};