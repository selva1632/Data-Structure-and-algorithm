// problem link: https://bit.ly/3QJ0vwc

#include<iostream>
#include<vector>
using namespace std;

void f(int i, int &n, vector<string>& s, string ds, char prev) {
    if (n == i) {
        s.push_back(ds);
        return;
    }

    // not take 0
    f(i + 1, n, s, ds + "0", '0');

    // take 1
    if (prev != '1') {
        f(i + 1, n, s, ds + "1", '1');
    }
}

vector<string> generateString(int N) {
    // Write your code here.
    vector<string> s;
    f(0, N, s, "", '0');
    return s;
}