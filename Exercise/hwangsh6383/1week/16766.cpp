#include <bits/stdc++.h>
#define _MAX 1000000000

using namespace std;

int N, M, C;
int times[100000];

bool canTake(int x) {
    int cnt = 1;
    for(int i = 1, start = 0; i < N; i++)
    {
        if(i - start < C && times[i] < times[start] + x) continue;
        cnt++;
        start = i;
    }
    return cnt > M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> C;
    for(int i = 0; i < N; i++)
    {
        cin >> times[i];
    }
    sort(times, times + N);

    int start = 0, end = _MAX;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(canTake(mid))
            start = mid + 1;
        else
            end = mid - 1;
    }
    cout << end;
    return 0;
}
