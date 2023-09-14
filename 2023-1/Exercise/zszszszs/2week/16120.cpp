#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string str;
    cin >> str;

    int cnt = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'P') // P일때
        {
            cnt++;
            continue;
        }
        if (cnt >= 2 && str[i + 1] == 'P') // A이고 뒤가 P일때
        {
            cnt--;
            i++;
        }
        else
        { // A이고 뒤가 P가 아닐때
            cout << "NP";
            return 0;
        }
    }
    if (cnt == 1)
    {
        cout << "PPAP";
    }
    else
    {
        cout << "NP";
    }
}