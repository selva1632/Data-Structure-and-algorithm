// problem link: 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    struct JobData{
        int id, deadline, profit;
        
        JobData(): id(0), deadline(0), profit(0) {}
        JobData(int id, int dl, int p): id(id), deadline(dl), profit(p) {}
    };
    
    static bool cmp(const JobData &a, const JobData &b) {
        return a.profit > b.profit;
    }
public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
        vector<JobData> job;
        int n = id.size(), maxDeadline = 0;
        
        for (int i = 0; i < id.size(); i++) {
            job.push_back(JobData(id[i], deadline[i], profit[i]));
            maxDeadline = max(deadline[i], maxDeadline);
        }
        
        sort(job.begin(), job.end(), cmp);
        vector<int> arr(maxDeadline + 1, -1);
        int maxprofit = 0, count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = job[i].deadline; j > 0; j--) {
                if (arr[j] == -1) {
                    arr[j] = 1;
                    count++;
                    maxprofit += job[i].profit;
                    break;
                }
            }
        }
        
        return {count, maxprofit};
    }
};