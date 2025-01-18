// problem link: https://www.interviewbit.com/problems/subarray-with-given-xor/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
        int xr = 0, count = 0;
        map<int, int> mpp;
        mpp[xr]++;
        
        for (int i = 0; i < n; i++) {
            xr ^= arr[i];
            int k = xr ^ x;
            count += mpp[k];
            mpp[xr]++;
        }
        
        return count;
}