// problem link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    vector<string> phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void f(int ind, string &digits, string &ds, vector<string>& res) {
        if (ind == digits.size()) {
            res.push_back(ds);
            return;
        }

        int index = digits[ind] - '2';
        for (int i = 0; i < phone[index].size(); i++) {
            ds.push_back(phone[index][i]);
            f(ind + 1, digits, ds, res);
            ds.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits == "") return res;
        string ds = "";
        f(0, digits, ds, res);
        return res;
    }
};