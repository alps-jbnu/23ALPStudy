#include <bits/stdc++.h>
#define ll long long int
#define MAX 100 + 1
using namespace std;

int N, add = 3;
int DP[MAX] = {
    0,
    2,
    4,
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 3; i <= N; i++)
    {
        DP[i] = DP[i - 1] + add;

        if ((i % 3) != 0)
            add++;
    }

    cout << DP[N];

    return 0;
}