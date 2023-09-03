#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int nA, nB;
long long A[500005];
long long B[500005];
vector<long long>answer;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> nA >> nB;
	for (int i = 0; i < nA; i++) {
		cin >> A[i];
	}
	sort(A, A + nA);
	for (int i = 0; i < nB; i++) {
		cin >> B[i];
	}
	sort(B, B + nB);
	for (int i = 0; i < nA; i++) {
		if (binary_search(B, B + nB, A[i])) continue;
		else answer.push_back(A[i]);
	}
	if (answer.empty()) cout << 0;
	else {
		cout << answer.size() << "\n";
		for (int i : answer)
			cout << i << " ";
	}
}
