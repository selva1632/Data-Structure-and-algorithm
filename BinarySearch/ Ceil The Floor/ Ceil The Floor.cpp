#include<iostream>
#include<vector>
using namespace std;

int findFloor(vector<int>& arr, int n, int x) {
	int l = 0, r = n - 1, ans = -1;

	while (l <= r) {
		int mid = l + (r - l) / 2;
		
		if (arr[mid] <= x) {
			ans = arr[mid];
			l = mid + 1; 
		} else {
			r = mid - 1;
		}
	}
	return ans;
}
int findCeil(vector<int>& arr, int n, int x) {
	int l = 0, r = n - 1, ans = -1;

	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (arr[mid] >= x) {
			ans = arr[mid];
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	return make_pair(findFloor(a, n, x), findCeil(a, n, x));
}