#include <iostream>
using namespace std;
int alp[26];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	for (int e : s)
		alp[e - 'a']++;
	for (int p : alp)
		cout << p << " ";
}
