#include <bits/stdc++.h>
using namespace std;

int main() {
	string name;
	cin >> name;
	vector<int> a(26);

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < name.size(); j++) {
			if (name[j] == (char)(i + 97))
				a[i]++;
		}
		cout << a[i] << " ";
	}

	return 0;
}
