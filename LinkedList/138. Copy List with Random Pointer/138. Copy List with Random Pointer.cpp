// problem link: https://leetcode.com/problems/copy-list-with-random-pointer

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // insert new node in between
        Node* temp = head;

        while (temp) {
            Node* nextNode = temp->next;
            Node* newNode = new Node(temp->val);
            newNode->next = nextNode;
            temp->next = newNode;
            temp = nextNode;
        }

        temp = head;

        // connect to random pointer
        while (temp) {
            Node* copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = nullptr;
            }

            temp = temp->next->next;
        }

        // disconnecting other original nodes
        temp = head;
        Node* newNode = new Node(-1);
        Node* cur = newNode;

        while (temp) {
            cur->next = temp->next;
            cur = cur->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return newNode->next;
    }
};