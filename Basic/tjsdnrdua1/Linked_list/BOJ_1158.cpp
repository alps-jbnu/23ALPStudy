#include <bits/stdc++.h>
using namespace std;
const int MX = 5001;
int dat[MX], pre[MX], nxt[MX];
void insert(int N) {
	for (int i = 1; i <= N; i++) {
		if (i == 1) {
			pre[i] = N;
			nxt[i] = 2;
		}
		else if (i != 1 && i != N) {
			pre[i] = i - 1;
			nxt[i] = i + 1;
		}
		else {
			pre[i] = i - 1;
			nxt[i] = 1;
		}
	}
}
void erase(int current, int idx) {
	cout << current;
	nxt[pre[current]] = nxt[current];
	pre[nxt[current]] = pre[current];
}
int main(void) {
	int N, K;
	cin >> N >> K;
	insert(N);
	int curs = K;
	cout << "<";
	for (int i = 0; i < N; i++) {
		erase(curs,K);
		for(int j=0;j<K;j++) {
			curs = nxt[curs];
		}//Renew cursor
		if (i != N - 1)
			cout << ", ";
	}
	cout << ">";
}
