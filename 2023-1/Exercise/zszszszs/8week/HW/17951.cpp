#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int sum = 0;
vector<int> x;

bool calc(int mid)
{
    int count = 0;
    int s = 0;

    for (int i = 0; i < N; i++)
    {
        s += x[i];
        if (s >= mid)
        {
            count++;
            s = 0;
        }
    }

    return count >= K;
}

int main()
{
    ios_base::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    x = vector<int>(N, 0);

    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;

        x[i] = input;
        sum += input;
    }

    int left = 0, right = sum;
    int ans = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (calc(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    cout << ans;

    return 0;
}