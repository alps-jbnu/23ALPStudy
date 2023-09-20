#include <bits/stdc++.h>
#define ll long long int
#define MAX 50 + 1
using namespace std;

int N;
int x[MAX], h[MAX], s, e;
int top = 0, down = 0;
double degree = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i <= N; i++)
    {
        cin >> x[i] >> h[i];
    }
    cin >> s >> e;
    down = e;

    for (int i = 1; i <= N; i++)
    {

        if (x[i] < e)
            degree *= (h[i] - h[i - 1]) / (x[i] - x[i - 1]);
        else
            degree *= (h[i] - h[i - 1]) / (e - x[i - 1]);
    }

    cout << abs(degree);

    return 0;
}