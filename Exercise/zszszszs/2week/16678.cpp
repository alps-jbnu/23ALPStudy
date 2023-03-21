#include <bits/stdc++.h>
using namespace std;
long long arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int num = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= num)
            continue;
        num++;
        if (arr[i] > num)
            ans += arr[i] - num;
        }
    cout << ans;
}