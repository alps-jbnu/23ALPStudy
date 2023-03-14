#include <bits/stdc++.h>

using namespace std;

int n;
pair<int,int> arr[100005];
int a[100005];
int t[100005];
priority_queue<int, vector<int>, greater<int> > pq;

bool cp_first(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first < b.first;
}

bool cp_second(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int aa;
		cin >> aa >> t[i];
		arr[i] = { aa,i };
		a[i] = aa;
	}

	sort(arr,arr+n,cp_first);

	int cnt = 1;
	int time = 0;
	int max = 0;
	pq.push(arr[0].second);
	while (!pq.empty()){
		int cur = pq.top();
		pq.pop();
		int wait = 0;
		if (time < a[cur]) time = a[cur];
		else {
			wait = time - a[cur];
			if (max < wait) max = wait;
		}
		time += t[cur];

		while (cnt < n && arr[cnt].first <= time) {
			pq.push(arr[cnt].second);
			cnt++;
		}
		if (cnt < n && pq.empty()) {
			pq.push(arr[cnt].second);
			cnt++;
		}
	}

	cout << max;
}