#include <bits/stdc++.h>
using namespace std;

int h;	//지정할 나무 높이
int n;	//나무의 수
int m;	//가져갈 나무의 길이
int answer = 0;
vector<int> tree;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> h;
		tree.push_back(h);
	}

	sort(tree.begin(), tree.end());

	int start = 0;
	int end = *max_element(tree.begin(), tree.end());

	while (start <= end) {
		int mid = (start + end) / 2;
		long long height = 0; 
		for (int i = 0; i < n; i++) {
			if(tree[i] > mid)
				height += tree[i] - mid;
		}

		if (height >= m) {
			start = mid + 1;
			answer = mid;
		}
		else
			end = mid - 1;
	}

	cout << answer;
}