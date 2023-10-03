#include <bits/stdc++.h>
#define ll long long int
#define MAX 100000 + 1
using namespace std;

int N, M, flag = 1;
priority_queue<int> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;

        if (pq.top() >= x)
        {
            pq.push(pq.top() - x);
            pq.pop();
        }
        else
            flag = 0;
    }

    cout << flag;

    return 0;
}