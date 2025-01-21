// problem link: https://bit.ly/3MZQOct

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int helper(vector<int>& arr, int page) {
    int curPerson = 1, curPage = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (curPage + arr[i] <= page) {
            curPage += arr[i];
        } else {
            curPerson++;
            curPage = arr[i];
        }
    }
    return curPerson;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if (n < m) {
        return -1;
    }
    int l = *max_element(arr.begin(), arr.end());
    int r = accumulate(arr.begin(), arr.end(), 0);

    while (l <= r) {
        int mid = l + (r - l) / 2;

        int person = helper(arr, mid);
        if (person > m) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}