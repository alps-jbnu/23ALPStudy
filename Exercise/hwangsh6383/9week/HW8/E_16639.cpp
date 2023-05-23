#include <bits/stdc++.h>

using namespace std;

int maxVal[20][20];
int minVal[20][20];

int calc(int val1, int val2, char op) {
    if(op == '+')
    {
        return val1 + val2;
    }
    else if(op == '-')
    {
        return val1 - val2;
    }
    else
    {
        return val1 * val2;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for(int i = 1; i <= N; i += 2)
    {
        for(int j = 1; j <= N; j += 2)
        {
            maxVal[i][j] = INT_MIN;
            minVal[i][j] = INT_MAX;
        }
    }
    string s; cin >> s;
    for(int i = 1; i <= N; i += 2)
    {
        int val = s[i - 1] - '0';
        maxVal[i][i] = val;
        minVal[i][i] = val;
    }
    for(int i = 2; i <= N; i += 2)
    {
        for(int j = 1, k = j + i; k <= N; j += 2, k += 2)
        {
            for(int m = j; m < k; m += 2)
            {
                int values[4] = {
                        calc(maxVal[j][m], maxVal[m + 2][k], s[m]),
                        calc(minVal[j][m], minVal[m + 2][k], s[m]),
                        calc(maxVal[j][m], minVal[m + 2][k], s[m]),
                        calc(minVal[j][m], maxVal[m + 2][k], s[m])
                };
                sort(values, values + 4);
                minVal[j][k] = min(minVal[j][k], values[0]);
                maxVal[j][k] = max(maxVal[j][k], values[3]);
            }
        }
    }
    cout << maxVal[1][N];
    return 0;
}
