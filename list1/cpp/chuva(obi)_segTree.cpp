#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef vector<int> vi;

vi arr, segTree;

void build(int start, int end, int i) {
	if(end - start < 2) {
		segTree[i] = arr[start];
		return;
	}
	build(start, (start + end) / 2, i * 2);
	build((start + end) / 2, end, (i * 2) + 1);
	segTree[i] = max(segTree[i * 2], segTree[(i * 2) + 1]);
}

int query(int node, int start, int end, int i, int j) {
	if(start >= j || end <= i) return -1;
	if(start <= i && end >= j) return segTree[node];
	return max(query(node * 2, start, end, i, (i + j) / 2), query((node * 2) + 1, start, end, (i + j) / 2, j));
}

int main() {
	int n, count = 0;
	cin >> n;
	arr.resize(n);
	for(int i = 0; i < n * 2 + 1; i++) segTree.pb(0);
	for(int i = 0; i < n; i++) cin >> arr[i];
	build(0, n , 1);
	for(int i = 0; i < n; i++) count += (min(query(1, 0, i + 1, 0, n), query(1, i, n, 0, n)) > arr[i]);
	cout << count << endl;
	return 0;
}
