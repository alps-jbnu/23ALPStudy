#include <bits/stdc++.h>
using namespace std;
int n;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    deque<int> de;
    cin >> n;
    int ans[1000005];
    int arr[1000005];
    deque<int> card;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        card.push_back(i);
    }
    for (int i = n; i > 0; i--)
    {
        int a = card.front();
        card.pop_front();
        if (arr[i] == 1)
        {

            de.push_front(a);
        }
        if (arr[i] == 2)
        {
            int tmp = de.front();
            de.pop_front();
            de.push_front(a);
            de.push_front(tmp);
        }
        if (arr[i] == 3)
        {
            de.push_back(a);
        }
    }
    while (!de.empty())
    {
        int a = de.front();
        cout << a << " ";
        de.pop_front();
    }
}