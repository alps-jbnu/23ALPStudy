#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> p(10005, -1);

int find(int n)
{
	if (p[n] < 0)
		return n;
	//return find(p[n]);					// 트리 경로 비압축
	return p[n] = find(p[n]);			// 트리 경로 압축
}

void union_num(int a, int b)
{
	a = find(a);
	b = find(b);
	p[b] = a;
}

int v, e;
tuple<int, int, int> edge[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		edge[i] = { cost, a , b };
	}
	int ans = 0;
	int cnt = 0;
	sort(edge, edge + e);
	for (int i = 0; i < e; i++)
	{
		int cost, a, b;
		tie(cost, a, b) = edge[i];
		if (find(a) == find(b))
			continue;
		else
			union_num(a, b);
		ans += cost;
		cnt++;
		if (cnt == v - 1)
			break;
	}
	cout << ans;

	return 0;
}
