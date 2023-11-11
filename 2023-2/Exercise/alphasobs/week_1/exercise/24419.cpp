#include <bits/stdc++.h>
#define ll long long int
#define div 1000000007
#define MAX 1000 + 1
using namespace std;

int N;
int rec_cnt = 0, dp_cnt = 0;
int arr[MAX][MAX];

int rec_matrix(int m[MAX][MAX], int i, int j)
{
    if (i == 0 || j == 0)
    {
        rec_cnt++;
        return 0;
    }
    else
        return m[i][j] + max(rec_matrix(m, i - 1, j), rec_matrix(m, i, j - 1));
}
int rec_path(int m[MAX][MAX], int n)
{
    return rec_matrix(m, n, n);
}

int DP_path(int m[MAX][MAX], int n)
{
    int d[MAX][MAX];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp_cnt++;
            d[i][j] = m[i][j] + max(d[i - 1][j], d[i][j - 1]);
        }
    }

    return d[n][n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }

    rec_path(arr, N);
    DP_path(arr, N);

    cout << rec_cnt % div << " " << dp_cnt % div;

    return 0;
}