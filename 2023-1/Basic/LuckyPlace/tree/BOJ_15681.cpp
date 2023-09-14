#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;
vector<int> vertex[MAX];
bool is_visited[MAX];
int num_of_subTree[MAX];

void countSubTreeNodes(int cur)
{
	num_of_subTree[cur] = 1;		// 1·Î ½ÃÀÛ
	is_visited[cur] = true;
	for(int next : vertex[cur])
	{
		if (is_visited[next])
			continue;
		countSubTreeNodes(next);
		num_of_subTree[cur] += num_of_subTree[next];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r, q;
	cin >> n >> r >> q;
	int edge = n - 1;
	while (edge--)
	{
		int u, v;
		cin >> u >> v;
		vertex[u].push_back(v);
		vertex[v].push_back(u);
	}
	countSubTreeNodes(r);
	while (q--)
	{
		int root;
		cin >> root;
		cout << num_of_subTree[root] << "\n";
	}
	return 0;
}