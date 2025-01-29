#include <iostream>
#include <vector>
using namespace std;

class DisjointSetUnion {
private:
	vector<int> parent, rank, size;

public:
	DisjointSetUnion(int n) {
		parent.resize(n + 1);
		rank.resize(n + 1, 0);
		size.resize(n + 1, 0);

		for (int i = 0; i <= n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	// path compression
	int findParent(int node) {
		if (parent[node] == node) {
			return node;
		}

		return parent[node] = findParent(parent[node]);
	}

	void UnionByRank(int u, int v) {
		int rootU = findParent(u);
		int rootV = findParent(v);

		if (rootU == rootV) return;

		if (rank[rootU] < rank[rootV]) {
			parent[rootU] = rootV; 

		} else if (rank[rootU] > rank[rootV]) {
			parent[rootV] = rootU;
		} else {
			parent[rootU] = rootV;
			rank[rootU]++;
 		}
	}

	void UnionBySize(int u, int v) {
		int rootU = findParent(u);
		int rootV = findParent(v);

		if (rootU == rootV) return;

		if (size[rootU] < size[rootV]) {
			parent[rootU] = rootV;
			size[rootV] += size[rootU];
		} else {
			parent[rootV] = rootU;
			size[rootU] += size[rootV];
		}
	}
};

int main() {
	DisjointSetUnion ds(7);
	ds.UnionBySize(1, 2);
	ds.UnionBySize(2, 3);
	ds.UnionBySize(4, 5);
	ds.UnionBySize(6, 7);
	ds.UnionBySize(5, 6);

	if (ds.findParent(3) == ds.findParent(7)) {
		cout << "same" << endl;
	} else { cout << "not same" << endl; }
    ds.UnionBySize(3, 7);
	if (ds.findParent(3) == ds.findParent(7)) {
	    cout << "same" << endl;
	} else { cout << "not same" << endl; }

	return 0;
}