#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	int arr[10];
	memset(arr, 0, sizeof(arr));

	cin >> str;
	for (int i = 0; i < str.length(); i++)
		arr[str[i] - '0']++;
	int maxi = arr[0];
	for (int i = 1; i < 10; i++) {
		if (i != 9 && i != 6) maxi = max(maxi, arr[i]);
	}
	cout << max(maxi, (arr[6] + arr[9] + 1) / 2);
	return 0;
}
