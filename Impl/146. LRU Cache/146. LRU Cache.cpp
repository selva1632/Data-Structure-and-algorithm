// problem link: https://leetcode.com/problems/lru-cache/submissions/1

#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int key, val;
    Node *prev, *next;

    Node(): key(0), val(0), prev(nullptr), next(nullptr) {};
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> mpp;
    Node *head, *tail;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mpp.find(key) == mpp.end()) 
            return -1;

        Node* node = mpp[key];
        remove(node);
        add(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            remove(mpp[key]);
        }
        if (capacity == mpp.size()) {
            remove(tail->prev);
        }

        add(new Node(key, value));
    }
    
private:
    void add(Node* node) {
        Node* next = head->next;
        head->next = node;
        node->prev = head;
        node->next = next;
        next->prev = node;

        mpp[node->key] = node;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;

        mpp.erase(node->key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */