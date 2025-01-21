#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;
    int size;
    
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        
        Node* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->data;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        
        Node* current = head;
        Node* newNode = new Node(val);
        
        if (index == 0) {
            newNode->next = current;
            head = newNode;
        } else {
            
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        
        if (index == 0) {
            Node* newHead = head->next;
            delete head;
            head = newHead;
        } else {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            
            Node* nextNode = cur->next;
            cur->next = nextNode->next;
            delete nextNode;
        }
        size--;
    }

    Node* reverseList() {
        Node* cur = head, *prev = nullptr;

        while (cur) {
            Node* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    void printAllElement()
    {
        Node *cur = head;

        while (cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void printAllElement(Node* head)
    {
        Node *cur = head;

        while (cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    ~MyLinkedList() {
        Node* p = head;

        while (p) {
            head = p->next;
            delete p;
            p = head;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    MyLinkedList obj = MyLinkedList();

    for (int i = 0; i < n; i++)
    {
        obj.addAtTail(arr[i]);
    }
    obj.printAllElement();

    int x, y; cin >> x;
    obj.addAtHead(x);

    cin >> x >> y;
    obj.addAtIndex(y, x);

    obj.printAllElement();

    cout << obj.get(4) << endl;
    obj.printAllElement(obj.reverseList());
    return 0;
}