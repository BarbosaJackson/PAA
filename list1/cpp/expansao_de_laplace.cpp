#include <bits/stdc++.h>

using namespace std;

#define DEBUG if(0)
#define DASH cout << "--------------------------------" << endl;
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;

void print_matrix(vvi matrix) {
	for(int j = 0; j < (int)matrix.size(); j++) {
		for(int k = 0; k < (int)matrix.size(); k++) {
			cout << matrix[j][k] << " ";
		}
		cout << endl;
	}
}

lli calc_deter(int d, vvi matrix) {
	if(d == 1) return matrix[0][0];
	if(d == 2) return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
	lli sum = 0;
	vvi newMatrix;
	newMatrix.resize(d - 1);
	
	for(int i = 0; i < d; i++) {
		int i1 = 0;
		for(int j = 1; j < d; j++) {			
			newMatrix[i1].resize(d - 1);
			int j1 = 0;
			for(int k = 0; k < d; k++) {
				if(k != i) {
					newMatrix[i1][j1++] = matrix[j][k];
				}
			}
			i1++;
		}
		lli ret = calc_deter(d - 1, newMatrix);
		int p = ((i & 1) ? - 1 : 1);
		sum += (p * matrix[0][i] * ret);
	}
	return sum;
}

int main() {
	int d;
	vvi matrix;
	cin >> d;
	matrix.resize(d);
	
	for(int i = 0; i < d; i++){
		for(int j = 0;  j < d; j++) {
			int x;
			cin >> x;
			matrix[i].pb(x);
		}
	}
	cout << calc_deter(d, matrix) << endl;
	return 0;
}