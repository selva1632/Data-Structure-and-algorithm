// problem link: https://bit.ly/3podAiY

#include<iostream>
#include<stack>
using namespace std;

class Solution{
public:
    void solve(stack<int> &st, int top) {
        if (st.empty()) {
            st.push(top);
            return;
        }
        int x = st.top();
        st.pop();
        solve(st, top);
        st.push(x);
    }
    void Reverse(stack<int> &St){
        if (St.empty()) return;
        int top = St.top();
        St.pop();
        Reverse(St);
        solve(St, top);
    }
};