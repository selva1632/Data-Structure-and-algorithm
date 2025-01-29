// problem link: https://www.geeksforgeeks.org/problems/fractional-knapsack

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
    
    Item(): value(0), weight(0) {}
    Item(int value, int weight): value(value), weight(weight) {}
};

class Solution {
    private:
    static bool cmp(const Item &a, const Item &b) {
        double ratio1 = (double) a.value / (double) a.weight;
        double ratio2 = (double) b.value / (double) b.weight;
        
        return ratio1 > ratio2;
    }
    
    public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<Item> arr;
        for (int i = 0; i < val.size(); i++) {
            arr.push_back(Item(val[i], wt[i]));
        }
        
        sort(arr.begin(), arr.end(), cmp);
        
        double knapsack = 0.0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].weight <= capacity) {
                knapsack += (double) arr[i].value;
                capacity -= arr[i].weight;
            } else {
                knapsack +=  ((double)arr[i].value / (double) arr[i].weight) * capacity;
                break;
            }
        }
        return knapsack;
    }
};