// problem link:

#include<iostream>
#include<vector>
#include<string>
using namespace std;

string getAlienLanguage(vector<string> &dictionary, int k)
{
    // Write your code here.
    vector<vector<int>> adj(k);

    for (int i = 0; i < dictionary.size() - 1; i++) {
        string a = dictionary[i];
        string b = dictionary[i + 1];

        int n = min(a.size(), b.size());
        int j = 0;

        while (j < n) {
            if (a[j] != b[j]) {
                int x = a[j] - 'a';
                int y = b[j] - 'a';
                adj[x].push_back(y);
                break;
            }
            j++;
        }
    }

    vector<int> indegree(k, 0), res;
    queue<int> q;
    for (int i = 0; i < k; i++) {
        for (auto it: adj[i]) {
            indegree[it]++;
        }
    }

    for (int i = 0; i < k; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        res.push_back(node);

        for (auto it: adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    string s = "";
    for (auto it: res) {
        s += (it + 'a');
    }
    return s;
}