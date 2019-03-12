# O problema
Ambrósio é um homem extremamente rico, sua fortuna se deve a sua sapiencia ao escolhar as ações certas para comprar e o momento certo de as vender, para saber se deve ou não comprar ações de uma empresa ambrósio faz um teste:
vou comprar e vender no máximo duas vezes, e comprarei ações da empresa que me der o maior lucro possivel nos N dias.
contudo, antes desse processo de teste, cuidadoso como sempre foi, Ambrósio seleciona a empresa que apresentou o maior lucro nos em um intervalo de N dias, antigamente esse processo era feito por Ambrósio e seus assistentes no papel, mas com a crescente de empresas entrando nas bases de ações já não é viável para ele fazer este processo na mão, para isso, você foi contratado para criar um programa que dado os preços de uma determinada ação indicar qual o maior lucro possível dela sabendo que Ambrósio vai ter sempre apenas uma ação em posse e vai comprar e vender no máximo duas vezes.

# exemplo de entrada
8 10 5 30 25 35

# exemplo de saída
35

# Explicação da solução
O maior lucro possivel é obtido atráves da compra no dia 3 (custando 5) e venda no dia 4(custando 30), dando de lucro 25, e comprando no dia 5(custando 25) e vendendo no dia 6(custando 35) obtendo 10 de lucro que somado daria 35.

# como determinar esse valor
vamos criar uma tabela onde na primeira coluna vão estar a melhor venda de ações até aquele dia e na segunda coluna a melhor venda desse dia para o dia __n__.

com os valores dados no exemplo de entrada a tabela obtida é a seguinte:

| first  | second |
| :----: | :----: |
| 0      | 0      |
| 2      | 0      |
| 2      | 30     |
| 25     | 10     |
| 25     | 10     |
| 30     | 0      |

tendo a tabela e sabendo que o first é a melhor venda de 0 até a posição da tabela e second é a melhor venda da posição da tabela pro final, basta pegar a maior soma da posição tabela[i].first com a posição tabela[i + 1].second, olharemos para as posições atual e atual + 1 pelo fato dele não poder realizar mais de uma operação no dia, dessa forma, a pergunta que sempre faremos é: a melhor venda até aqui somada a melhor venda do próximo dia até o ultimo é a maior venda possivel?

# Solução
```C++
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
```

