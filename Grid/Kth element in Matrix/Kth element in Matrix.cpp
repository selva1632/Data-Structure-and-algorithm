// problem link: 

#include<iostream>
#include<vector>
using namespace std;
#define MAX 1000

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