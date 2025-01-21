// problem link: https://bit.ly/3C9GQRS

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
  private:
    void f(int ind, vector<int>& arr, vector<int>& res, int sum) {
        
        if (ind == arr.size()) {
            res.push_back(sum);
            return;
        }
        
        // not take 
        f(ind + 1, arr, res, sum);
        
        // take 
        f(ind + 1, arr, res, sum + arr[ind]);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> res;
        f(0, arr, res, 0);
        return res;
    }
};