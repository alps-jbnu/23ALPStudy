#include <bits/stdc++.h>
#define MAX 1e9 + 1
using namespace std;

int N, M, C;
int low = 0, high = 1e9;
vector<int> vec;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool Solve(int x)
{
    int cnt = 1;

    int start = 0;
    for (int i = 1; i < N; i++)
    {
        if (i - start < C && vec[i] <= vec[start] + x)
            continue;
        cnt++;
        start = i;
    }
    return cnt <= M;
}

int main()
{
    init();

    cin >> N >> M >> C;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (Solve(mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << low;

    return 0;
}