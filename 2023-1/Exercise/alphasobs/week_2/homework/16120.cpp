#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'P')
        {
            cnt++;
            continue;
        }

        if (cnt >= 2 && str[i + 1] == 'P')
        {
            cnt--;
            i++;
        }
        else
        {
            cout << "NP";
            return 0;
        }
    }

    if (cnt == 1) cout << "PPAP";
    else cout << "NP";

    return 0;
}