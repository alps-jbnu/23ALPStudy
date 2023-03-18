#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;

    int pCount = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'P')
            pCount++;
        else if(s[i] == 'A')
        {
            if(pCount < 2)
            {
                pCount = 0;
                break;
            }
            else if(s[i + 1] == 'P')
            {
                pCount--;
                i += 1;
            }
            else
            {
                pCount = 0;
                break;
            }
        }
    }
    if(pCount == 1)
        cout << "PPAP";
    else
        cout << "NP";
    return 0;
}
