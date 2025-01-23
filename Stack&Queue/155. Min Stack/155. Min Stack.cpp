// problem link: https://leetcode.com/problems/min-stack/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class MinStack {
private:
    stack<int> st1, st2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if (st2.empty() || val <= getMin()) {
            st2.push(val);
        }
    }
    
    void pop() {
        if (getMin() == st1.top()) {
            st2.pop();
        }
        st1.pop();
    }
    
    int top() {
        if (!st1.empty()) {
            return st1.top();
        }
        return -1;
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */