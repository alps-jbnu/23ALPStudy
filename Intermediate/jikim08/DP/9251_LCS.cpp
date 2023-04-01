#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int len1 = str1.length(), len2 = str2.length();

	vector<vector<int>> DP(len1 + 1, vector<int>(len2 + 1, 0));

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
			}
		}
	}
	
	cout << DP[len1][len2];
}
