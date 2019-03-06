#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair 
#define MAX_SIZE (1 << 20)
#define READ(x) cin >> x;
#define PRT(x) cout << x << endl;
#define REP(i, n) for(i = 0; i < n; i++)
#define REP1(i, n) for(i = 1; i < n; i++)
#define REVREP(i, n) for(i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define DASH() cout << "-------------------------" << endl;
typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

vi prices;
vii memo;

void init(int qnt) {
	memo.clear();
	memo.resize(qnt);
}

void bestSell() {
	int min_price = prices[0], i;
	memo[0].fi = 0;
	REP1(i, sz(prices)) {
		memo[i].fi = memo[i - 1].fi > prices[i] - min_price ? memo[i - 1].fi : prices[i] - min_price;
		min_price = (prices[i] < min_price ? prices[i] : min_price);
	}
}

int maxProfit() {
	int profit, max_price, i;
	bestSell();
	memo[sz(prices) - 1].se = 0;
	max_price = prices[sz(prices) - 1];
	profit = memo[sz(prices) - 1].fi;
	for(int i = sz(prices) - 2; i >= 2; i--) {
		memo[i].se = max(memo[i + 1].se, max_price - prices[i]);
		profit = max(profit, memo[i].se + memo[i - 1].fi);
		if(prices[i] > max_price) max_price = prices[i];
	}
	return profit;
}

int main() {
	int x, i;
	while(cin >> x){
		prices.pb(x);
	}
	init(sz(prices));
	PRT(maxProfit());
	return 0;
}