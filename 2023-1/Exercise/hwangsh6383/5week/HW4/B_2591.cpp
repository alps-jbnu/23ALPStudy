#include <bits/stdc++.h>

using namespace std;

int temp[41];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    temp[0] = 1; temp[1] = 1; temp[2] = 2;
    for(int i = 3; i <= s.length(); i++)
    {
        temp[i] = temp[i - 1] + temp[i - 2];
    }
    int answer = 1; int tp = 1;
    for(int i = 1; i < s.length(); i++)
    {
        if(s[i - 1] == '1' || s[i - 1] == '2')
        {
            if(s[i] == '0')
            {
                answer *= temp[tp - 1];
                tp = 1;
            }
            else
            {
                tp++;
            }
        }
        else if(s[i - 1] == '3')
        {
            if(s[i] == '0')
            {
                answer *= temp[tp - 1];
                tp = 1;
            }
            else if(s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4')
            {
                tp++;
            }
            else
            {
                answer *= temp[tp];
                tp = 1;
            }
        }
        else
        {
            answer *= temp[tp];
            tp = 1;
        }
    }
    cout << answer * temp[tp];
    return 0;
}
