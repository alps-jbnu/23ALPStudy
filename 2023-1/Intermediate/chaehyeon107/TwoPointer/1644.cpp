#include <bits/stdc++.h>

using namespace std;

const int N = 4000002;
vector<int> prime;
bool seive[N];

void sieveOfEratosthenes() {
	fill(seive, seive+N, true);
	for(int i = 2; i*i < N; ++i) {
		if(!seive[i]) continue;
		for(int j = i*i; j < N; j += i)
			seive[j] = false;
	}
	for(int i = 2; i < N; i++) if(seive[i]) prime.push_back(i);
	prime.push_back(0);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	sieveOfEratosthenes();
	int st = 0;
	int en = 1;
	int sum = prime[0], cnt = 0;
	while(1) {
		if(sum == n) cnt++;
		if(sum <= n) sum += prime[en++];
		if(sum > n) sum -= prime[st++];
		if(en == prime.size()) break; 
	}
	cout << cnt;
}
