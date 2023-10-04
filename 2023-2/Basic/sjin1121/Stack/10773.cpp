#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>arr;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0)
			arr.pop_back();
		else
			arr.push_back(tmp);
	}
	for (int i = 0; i < arr.size(); i++)
		cnt += arr[i];
	cout << cnt;

	return 0;
}
