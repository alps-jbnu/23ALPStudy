#include <iostream>
#include <cstring>
using namespace std;

int main() {

	string s;
	cin >> s;
	int len = s.size();
	
	int count[26] = {0};

	for (int i = 0; i < len; i++) {
		for (int j = 'a'; j <= 'z'; j++) {
			if (s[i] == j) {
				count[j - 'a']++;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << count[i] << " ";
	}
	
}
