#include <iostream>
using namespace std;
int	main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int alp_A[26] = {}, alp_B[26] = {};

	string a, b;
	cin >> a >> b;
	for (auto e : a)alp_A[e - 'a']++;
	for (auto e : b)alp_B[e - 'a']++;
	int sub = 0; //subtraction count
	for (int i = 0; i < 26; i++) {
		sub += (alp_A[i] > alp_B[i] ?
			alp_A[i] - alp_B[i] : alp_B[i] - alp_A[i]);
	}
	cout << sub;
}
