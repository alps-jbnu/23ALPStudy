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
	int arr[10];
	ll a, b, c;
	
	memset(arr, 0, sizeof(arr));

	cin >> a >> b >> c;
	string ans = to_string(a * b * c);
	for (int i = 0; i < ans.length(); i++)
		arr[ans[i] - '0']++;
	for (int i = 0; i < 10; i++)
		cout << arr[i] << "\n";
}
