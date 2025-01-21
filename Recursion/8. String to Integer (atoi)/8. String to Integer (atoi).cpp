// problem link: 

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    int atoi(int i, int& sign, int& n, string& s, long long res) {
        if (sign * res >= INT_MAX) {
            return INT_MAX;
        }
        if (sign * res <= INT_MIN) {
            return INT_MIN;
        }
        if (i >= n || s[i] < '0' || s[i] > '9') {
            return sign * res;
        }

        return atoi(i + 1, sign, n, s, res * 10 + s[i] - '0');
    }

public:
    int myAtoi(string s) {
        int sign = 1, n = s.size(), i = 0;

        while (i < n && s[i] == ' ')
            i++;

        if (s[i] == '+') {
            ++i;
        } else if (s[i] == '-') {
            sign = -1;
            ++i;
        }

        return atoi(i, sign, n, s, 0);
    }
};