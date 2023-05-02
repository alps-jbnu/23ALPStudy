#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> node[1001];
bool is_visited[1001];      // �ڵ����� false�� �ʱ�ȭ

int main(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    queue<int> q;
    int num = 0;
    for (int i = 1; i <= n; i++)     // node�� 1���� �ִ� �������� �˻�
    {
        if (is_visited[i])
            continue;
        num++;
        is_visited[i] = true;
        q.push(i);
        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            for (auto next : node[current])
            {
                if (is_visited[next])
                    continue;
                q.push(next);
                is_visited[next] = true;
            }
        }
    }
    cout << num;
    return 0;
}
