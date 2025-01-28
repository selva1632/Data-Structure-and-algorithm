// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        pq.push({0, src});
        
        while (!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto it: adj[node]) {
                int edgeWeight = it.second;
                int adjNode = it.first;
                
                if (edgeWeight + distance < dist[adjNode]) {
                    dist[adjNode] = edgeWeight + distance; 
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};