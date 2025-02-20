// problem link: https://www.geeksforgeeks.org/problems/common-elements1132/1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int i = 0, j = 0, k = 0;
        vector<int> res;
        
        while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                if (res.empty() || res.back() != arr1[i]) {
                    res.push_back(arr1[i]);
                }
                i++, j++, k++;
            } else if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr2[j] < arr3[k]) {
                j++;
            } else {
                k++;
            }
        }
        
        return res;
    }
};

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
  
  for (int i = 0; i < n; i++) {
      pq.push({mat[i][0], i, 0});
  }
  
  int ans;
  while (k--) {
      int val = pq.top()[0];
      int row = pq.top()[1];
      int col = pq.top()[2];
      pq.pop();
      
      ans = val;
      
      if (col + 1 < n) {
          pq.push({mat[row][col + 1], row, col + 1});
      }
  }
  
  return ans;
}