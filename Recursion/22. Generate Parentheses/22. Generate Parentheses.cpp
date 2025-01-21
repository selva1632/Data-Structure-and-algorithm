// problem link: https://leetcode.com/problems/generate-parentheses/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    void f(int open, int close, int n, vector<string>& s, string& ds) {
        if (open + close == 2 * n) {
            s.push_back(ds);
            return;
        }

        if (open < n ) {
            ds.push_back('(');
            f(open + 1, close, n, s, ds);
            ds.pop_back();
        }

        if (open > close) {
             ds.push_back(')');
            f(open, close + 1, n, s, ds );
            ds.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        string temp = "";
        f(0, 0, n, s, temp);
        return s;
    }
};