#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef vector< pair <int,  iii> > viii;

void print(viii v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i].first << " ";
	}
	cout << endl;
}

int main() {
	vi v;
	viii sums;
	bool flag = false;
	int x, n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(x < 0) flag = true;
		v.pb(x);
	}
	if(flag) {
		cout << -1 << endl;
		return 0;
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = j + 1; k < n; k++) {
				sums.pb(mp((v[i] + v[j] + v[k]), mt(v[i],v[j], v[k])));
			}
		}
	}
	for(int i = 0; i < (int)sums.size(); i++) {
		flag = false;
		for(int j = i + 1; j < (int)sums.size(); j++) {
			if(sums[i].first == sums[j].first) {
				flag = true; 
				sums.erase(sums.begin() + j);
				j = i;
			}
		}
		if(flag) {
			sums.erase(sums.begin() + i);
			i = -1;
		}
	}
	for(int i = 0; i < (int)sums.size(); i++) {
		iii x = sums[i].second;
		cout << "{" << get<0>(x) << "," << get<1>(x) << "," << get<2>(x) << "} = " << sums[i].first << endl;
	}
	return 0;
}
