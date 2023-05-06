#include <bits/stdc++.h>

using namespace std;

int height[100001];
int arr[100002];
int sum[100002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        cin >> height[i];
    }
    while(M--)
    {
        int a, b, k; cin >> a >> b >> k;
        arr[a] += k;
        arr[b + 1] += -k;
    }
    for(int i = 1; i <= N; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }
    for(int i = 1; i <= N; i++)
    {
        cout << sum[i] + height[i] << ' ';
    }
    return 0;
}
