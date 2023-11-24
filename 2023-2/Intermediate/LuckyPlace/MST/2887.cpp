#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <cmath>
#define W first
#define N second
using namespace std;

const int mx = 100'002;
vector<int> p(mx, -1);
pair<int, int> x[mx];
pair<int, int> y[mx];
pair<int, int> z[mx];
vector<tuple<int, int, int>> edge;

int find(int n)
{
	if (p[n] < 0)
		return n;
	return p[n] = find(p[n]);
}

void union_num(int a, int b)
{
	int u, v;
	u = find(a), v = find(b);
	p[v] = u;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t_x, t_y, t_z;
		cin >> t_x >> t_y >> t_z;
		x[i] = { t_x, i };
		y[i] = { t_y, i };
		z[i] = { t_z, i };
	}

	sort(x, x + n);
	sort(y, y + n);
	sort(z, z + n);

	for (int i = 1; i < n; i++)
	{
		edge.push_back({ abs(x[i - 1].W - x[i].W), x[i - 1].N, x[i].N });
		edge.push_back({ abs(y[i - 1].W - y[i].W), y[i - 1].N, y[i].N });
		edge.push_back({ abs(z[i - 1].W - z[i].W), z[i - 1].N, z[i].N });
	}

	sort(edge.begin(), edge.end());

	int ans = 0, cnt = 0;
	for (int i = 0; i < edge.size(); i++)
	{
		int cost, a, b;
		tie(cost, a, b) = edge[i];
		if (find(a) == find(b))
			continue;
		else
			union_num(a, b);
		cnt++;
		ans += cost;
		if (cnt == n - 1)
			break;
	}
	cout << ans;

	return 0;
}
