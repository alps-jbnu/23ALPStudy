#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int r[105];
    int w[2005];
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    unordered_map<int, int> label;
    queue<int> q;
    int ans = 0;
    for (int i = 0; i < 2 * m; i++)
    {
        int car;
        cin >> car;

        if (car > 0)
        {
            q.push(car);
        }
        else
        {
            s.insert(label[-car]);
            label.erase(-car);
        }
        while (!q.empty() && !s.empty())
        {
            set<int>::iterator it = s.begin(); // set의 오름차순 성질을 이용하여 주차장 우선순위 적용해주기
            label[q.front()] = *it;            // 차가 주차된 주차장 번호 저장
            ans += w[q.front()] * r[*it];
            q.pop();
            s.erase(*it); // set에 없는 번호는 차를 댈 수 없다는 뜻
        }
    }
    cout << ans;
}