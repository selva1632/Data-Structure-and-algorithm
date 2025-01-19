// problem link: https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int findPainter(vector<int>& arr, int time) {
    int painters = 1, timeTake = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (timeTake + arr[i] <= time) {
            timeTake += arr[i];
        } else {
            painters++;
            timeTake = arr[i];
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int l = *max_element(boards.begin(), boards.end());
    int r = accumulate(boards.begin(), boards.end(), 0);

    while (l <= r) {
        int mid = l + (r - l) / 2;
        int painter = findPainter(boards, mid);
        if (painter <= k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}