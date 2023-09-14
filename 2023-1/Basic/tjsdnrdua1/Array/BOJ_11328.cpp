#include <iostream>
using namespace std;
int	main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	while (N--) {
		int alp_A[26] = {}, alp_B[26] = {};
		string a, b;
		string res;
		cin >> a >> b;

		for (auto e : a) alp_A[e - 'a']++;
		for (auto e : b) alp_B[e - 'a']++;
		int i = 0;
		for (; i < 26; i++) {
			if (alp_A[i] != alp_B[i])
				break;
		}
		if (i == 26) cout << "Possible\n";
		else cout << "Impossible\n";
	}
}
