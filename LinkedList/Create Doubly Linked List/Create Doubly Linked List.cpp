// problem link: https://bit.ly/3V9wY1v

#include<iostream>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        Node* head = new Node(0), *cur = head;
        
        for (int i = 0; i < arr.size(); i++) {
            Node* newNode = new Node(arr[i]);
            newNode->prev = cur;
            cur->next = newNode;
            
            cur = cur->next;
        }
        Node* next = head->next;
        next->prev = nullptr;
        return next;
    }
};