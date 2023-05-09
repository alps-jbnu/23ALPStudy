#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> line(N);

	for (int i = 0; i < N; i++) {
		cin >> line[i].first >> line[i].second;
	}

	sort(line.begin(), line.end());

	long long start = line[0].first, end = line[0].second;
	long long len = 0;

	for (int i = 1; i < N; i++) {
		if (line[i].first < end) {
			if (line[i].second > end) {
				end = line[i].second;
			}
		}
		else {
			len += end - start;
			start = line[i].first, end = line[i].second;
		}
	}

	len += end - start;

	cout << len;

}
