#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int costPlanet[1001][2];

double tryTravel(double fuel, double weightRocket, int size) {
	for(int i = 0; i < size	; i++) {
		fuel -= (fuel + weightRocket) / costPlanet[i][0];
		fuel -= (fuel + weightRocket) / costPlanet[(i + 1) % size][1];
	}
	return fuel;
}

double binSearch(int weightRocket, int size) {
	double fuel = 1;
	double mid;
	double left = 1, right = INF;
	while(right - left > 0.000001) {
		mid = (left + right) / 2.0;
		fuel = tryTravel(mid, weightRocket, size);
		if(fuel > 0) {
			right = mid;
		} else if(fuel < 0) {
			left = mid;
		} else {
			break;
		}
	}
	return mid;
}

int main(void) {
	int n, weightRocket;
	cin >> n >> weightRocket;
	for(int i = 0; i < n; i++) {
		cin >> costPlanet[i][0];
	}
	for(int i = 0; i < n; i++) {
		cin >> costPlanet[i][1];
	}
	if(tryTravel(INF, weightRocket, n) < 0.0){
		printf("-1\n");
	} else {
		printf("%.2lf\n", binSearch(weightRocket, n));
	}
	return 0;
}