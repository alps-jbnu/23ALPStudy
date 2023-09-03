#include <bits/stdc++.h>
#define ll long long
const int MAX = 100 + 1;
using namespace std;

int N;
int jokbo[9] = { 0, 0, 1, 7, 4, 2, 0, 8, 10 };
ll arr[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
    {
        arr[i] = jokbo[i];
    }
    arr[6] = 6;

    for (int i = 9; i <= 100; i++)
    {
        arr[i] = arr[i - 2] * 10 + jokbo[2];

        for (int j = 3; j < 8; j++)
        {
            arr[i] = min(arr[i], arr[i - j] * 10 + jokbo[j]);
        }
    }

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int cnt; cin >> cnt;

        cout << arr[cnt] << " ";

        if (!(cnt % 2))
        {
            for (int i = 0; i < cnt / 2; i++)
            {
                cout << 1;
            }
        }
        else
        {
            cout << 7;
            for (int i = 0; i < cnt / 2 - 1; i++)
            {
                cout << 1;
            }
        }
        cout << "\n";
    }

    return 0;
}