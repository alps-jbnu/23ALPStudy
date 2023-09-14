#include <bits/stdc++.h>

using namespace std;

long long dpMin[101];
string dpMax[101];
int num[6] = {1, 7, 4, 2, 0, 8};

// 2 - 1
// 3 - 7
// 4 - 4
// 5 - 2, 3, 5
// 6 - 6, 9, 0
// 7 - 8

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(dpMin, dpMin + 101, 188888888888888);
    dpMin[1] = 9; dpMin[2] = 1; dpMin[3] = 7; dpMin[4] = 4; dpMin[5] = 2; dpMin[6] = 6; dpMin[7] = 8;
    for(int i = 8; i <= 100; i++)
    {
        for(int j = 2; j <= 7; j++)
        {
               dpMin[i] = min(dpMin[i], dpMin[i - j] * 10 + num[j - 2]);
        }
    }

    dpMax[2] = "1";
    dpMax[3] = "7";
    for(int i = 4; i <= 100; i++)
    {
        dpMax[i] = dpMax[i - 2] + "1";
    }
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        cout << dpMin[n] << ' ' << dpMax[n] << '\n';
    }

    return 0;
}
