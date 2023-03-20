#include <bits/stdc++.h>
using namespace std;
int arr[5000000];
int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[a]++;
    }
    int ans1 = 0;

    long long minsum1 = LONG_MAX;
    long long sum2 = 0;
    for (int i = 1; i <= 10000; i++)
    {
        sum2 = 0;
        for (int j = 1; j <= 10000; j++)
        {
            sum2 += arr[j] * (abs(j - i));
        }
        if (sum2 < minsum1)
        {
            minsum1 = sum2;
            ans1 = i;
        }
    }
    int ans2 = 0;
    long long minsum = LONG_MAX;
    for (int i = 1; i <= 10000; i++)
    {
        long long sum2 = 0;
        for (int j = 1; j <= 10000; j++)
        {
            sum2 += 1LL * arr[j] * (abs(i - j) * abs(i - j));
        }
        if (sum2 < minsum)
        {
            minsum = sum2;
            ans2 = i;
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}