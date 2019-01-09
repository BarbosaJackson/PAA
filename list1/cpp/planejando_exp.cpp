#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> ii;
typedef vector<ii> vii;

vii arr;
int biggest;

bool sortBySec(const ii &a, const ii &b) {
	return a.se < b.se;
}

int insert_binary_search(int begin, int end, int value) {
	int mid = (begin + end) / 2;
	if(begin > end) return -1;
	if(arr[mid].fi == value) return mid;
	else if(arr[mid].fi < value) return insert_binary_search(mid + 1, end, value);
	else return insert_binary_search(begin, mid - 1, value);
}

int calc_days(int current_days) {
	int q = 0;
	for(int i = 0; i < arr.size(); i++) {
		q += (arr[i].se / current_days);
	}
	return q;
}

int days_binary_search(int begin, int end, int qtd_trip) {
	if(begin >= end) return -1;
	int mid = (begin + end) / 2;
	int q = calc_days(mid);
	if(q >= qtd_trip){
		while(q >= qtd_trip) {
			q = calc_days(++mid);
		}
		return mid - 1;
	}
	return days_binary_search(begin, mid, qtd_trip);
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if((int)arr.size() > 0) {
			int pos = insert_binary_search(0, (int)arr.size(), x);
			if(pos == -1) arr.pb(mp(x, 1));
			else arr[pos].se++;
		} else {
			arr.pb(mp(x, 1));
		}
		sort(arr.begin(), arr.end());
	}
	if((int)arr.size() == 1) {
		cout << (arr[0].se / n) << endl;
	} else {
		int days = days_binary_search(1, 100, n);
		cout <<  (days == -1 ? 0 : days) << endl;
	}
	return 0;
}