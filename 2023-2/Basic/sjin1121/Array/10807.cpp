#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>

using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, val;
	map<int, int>map;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		map[tmp]++;
	}
	cin >> val;
	cout << map[val];
	return 0;
}
