#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int v, e;
int d[405][405];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	for (int i = 1; i <= v; i++) fill(d[i], d[i] + v + 1, INF);
	for (int i = 1; i <= v; i++) d[i][i] = 0;
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (d[a][b] > c) d[a][b] = c;
		
	}

	for(int k = 1; k <= v; k++)
		for(int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++) 
				if (d[i][j] > d[i][k] + d[k][j]) 
					d[i][j] = d[i][k] + d[k][j];

	int mn = INF;
	for (int i = 1; i <= v; i++) {	// 출발
		for (int j = 1; j <= v; j++) {	// 거쳐가는 곳
			if (i == j) continue;
			mn = min(mn, d[i][j] + d[j][i]);
		}
	}

	if (mn == INF) mn = -1;
	cout << mn << '\n';
	
	return 0;
}
