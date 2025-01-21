// problem link: https://bit.ly/3Po7tpf

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        int count = 0;
        
        while (head) {
            count++;
            head = head->next;
        }
        
        return count;
    }
};