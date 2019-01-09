#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef vector<int> vi;

int main() {
	int n;
	cin >> n;
	vi pool;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pool.pb(x);
	}
	vi left, right;
	left.resize(n);
	right.resize(n);
	left[0] = pool[0];
	right[n - 1] = pool[n - 1];
	for(int i = 1, j = n - 2; i < n; i++, j--){
		left[i] = max(left[i - 1], pool[i]);
		right[j] = max(right[j + 1], pool[j]);
	}
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += (left[i] > pool[i] && right[i] >  pool[i]);	
	cout << sum << endl;

	return 0;
}