// problem link: https://leetcode.com/problems/palindrome-partitioning/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    bool isPalindrome(int start, int end, string& s) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    void f(int ind, string &s, vector<string> &ds, vector<vector<string>> &res) {
        if (ind == s.size()) {
            res.push_back(ds);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            if (isPalindrome(ind, i, s)) {
                ds.push_back(s.substr(ind, i - ind + 1));
                f(i + 1, s, ds, res);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        f(0, s, ds, res);
        return res;
    }
};