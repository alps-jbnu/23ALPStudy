#include <bits/stdc++.h>
using namespace std;
int arr[155];

int main(void)
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 1;
    int dir = arr[0];
    while (count <= n + 1)
    {
        if (dir == k)
        {
            cout << count;
            return 0;
        }
        count++;
        dir = arr[dir];
    }
    cout << "-1";
}