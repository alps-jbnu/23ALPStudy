#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[26];
	memset(arr, 0, sizeof(arr));
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		arr[str[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";
}
