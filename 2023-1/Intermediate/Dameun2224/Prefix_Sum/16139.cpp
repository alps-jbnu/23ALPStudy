#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string str;
int n, i;
int num[200005][30];
int sum[200005][30];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str >> n;
	for (char c : str) {
		i++;
		num[i][c - 'a']++;
		for (int j = 0; j <= 26; j++) 
			num[i][j] += num[i - 1][j];
	}

	while (n--) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		int d = c - 'a';
		cout << num[b+1][d] - num[a][d] << '\n';
	}

	return 0;
}
