#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int arr[100005];
int l = 0;
int h = 1000000000;

bool isRide(int x)
{
    int cnt = 1;
    int st = 0;
    for (int i = 1; i < n; i++)
    {
        if (i - st < c && arr[i] <= arr[st] + x)
            continue;
        cnt += 1;
        st = i;
    }
    return cnt <= m;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    while (l <= h)
    {

        int mid = (l + h) / 2;
        if (isRide(mid))
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l;
}