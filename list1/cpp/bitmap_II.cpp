#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi matrix;
int p;
string bitmap;

void build_matrix(int start_c, int start_l, int end_c, int end_l) {
	p++;
	// cout << "Lin: " << start_l << ", " << end_l << endl;
	// cout << "Col: " << start_c << ", " << end_c << endl;
	// if(p < bitmap.length() )cout << "char: " << bitmap.at(p) << endl;
	// cout << "---------------------------------" << endl;
	if(start_c == end_c || start_l == end_l) {
		p--;
		return;
	}
	if(p < bitmap.length()) {
		if( bitmap.at(p) == 'D') {
			int mid_c = ceil((end_c + start_c) / 2.0);
			int mid_l = ceil((end_l + start_l) / 2.0);
			build_matrix(start_c, start_l, mid_c, mid_l);
			build_matrix(mid_c, start_l, end_c, mid_l);
			build_matrix(start_c, mid_l, mid_c, end_l);
			build_matrix(mid_c, mid_l, end_c, end_l);
		} else if(bitmap.at(p) == '1') {
			for(int i = start_l; i < end_l; i++) {
				for(int j = start_c; j < end_c; j++) {
					matrix[i][j] = 1;
				}
			}
			
		}
	}
}

int main() {
	int cases;
	cin >> cases;
	while(cases--) {
		int n, m;
		p = -1;
		cin >> n >> m;
		cin >> bitmap;
		matrix.clear();
		matrix.resize(n);
		for(int i = 0; i < (int)matrix.size(); i++) {
			matrix[i].clear();
			matrix[i].resize(m);
		}
		build_matrix(0, 0, m, n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cout << matrix[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
