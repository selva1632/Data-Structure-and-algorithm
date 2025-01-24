// problem link: https://leetcode.com/problems/valid-parentheses/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                st.push(s[i]);
            } else {
                if (s[i] == ']') {
                    if (!st.empty() && st.top() == '[') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else if (s[i] == ')') {
                    if (!st.empty() && st.top() == '(') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    if (!st.empty() && st.top() == '{') {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};