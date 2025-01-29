// problem link: https://www.interviewbit.com/problems/nearest-smaller-element/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    vector<int> res(A.size());
    stack<int> st;
    
    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        
        res[i] = st.empty() ? -1 : st.top();
        st.push(A[i]);
    }
    
    return res;
}
