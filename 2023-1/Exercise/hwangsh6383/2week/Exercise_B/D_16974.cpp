#include <bits/stdc++.h>

using namespace std;

long long wholeBurgerNum[51];
long long wholePatiNum[51];

long long getPatiNum(int n, long long x) {
    if(n == 0)
        return 1;
    if(x == 1)
        return 0;
    else if(x < 1 + wholeBurgerNum[n - 1])
    {
        return getPatiNum(n - 1, x - 1);
    }
    else if(x == 1 + wholeBurgerNum[n - 1])
    {
        return wholePatiNum[n - 1];
    }
    else if(x == 1 + wholeBurgerNum[n - 1] + 1)
    {
        return wholePatiNum[n - 1] + 1;
    }
    else if(x <= wholeBurgerNum[n - 1] * 2 + 2)
    {
        return wholePatiNum[n - 1] + 1 + getPatiNum(n - 1, x - wholeBurgerNum[n - 1] - 2);
    }
    else
    {
        return wholePatiNum[n - 1] * 2 + 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    wholeBurgerNum[0] = 1; wholePatiNum[0] = 1;
    for(int i = 1; i <= 50; i++)
    {
        wholeBurgerNum[i] = wholeBurgerNum[i - 1] * 2 + 3;
        wholePatiNum[i] = wholePatiNum[i - 1] * 2 + 1;
    }

    long long N, X; cin >> N >> X;
    cout << getPatiNum(N, X);
    return 0;
}
