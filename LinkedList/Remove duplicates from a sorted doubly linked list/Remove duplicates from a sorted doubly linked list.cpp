// problem link: https://bit.ly/3FtJUtZ

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        Node* cur = head;
        
        while (cur) {
            while (cur->next && cur->next->data == cur->data) {
                cur->next = cur->next->next;
            }
            if (cur->next){
                cur->next->prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};