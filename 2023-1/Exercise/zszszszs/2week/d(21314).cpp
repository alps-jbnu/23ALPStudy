#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string str;
    string ans;
    cin >> str;

    int idx = 0;
    string ans1;
    bool flag = false;
    while (idx < str.size())
    {

        if (str[idx] == 'M' && flag == false) // M 처음 만날때
        {
            ans1 += '1';
            flag = true;
        }
        else if (str[idx] == 'M' && flag == true)
        {
            ans1 += '0';
        }

        else if (str[idx] == 'K')
        {
            ans1 += '5';
            flag = false;
        }
        idx++;
    }
    idx = 0;
    flag = false;
    string ans2;
    while (idx < str.size())
    {
        if (str[idx] == 'M')
        {
            int end_idx = idx;
            while (end_idx < str.size())
            {
                end_idx++;
                if (str[end_idx] == 'K')
                {
                    break;
                }
            }

            if (end_idx == str.size())
            {
                for (int i = 0; i < end_idx - idx; i++)
                {
                    ans2 += "1";
                }
            }
            else
            {
                ans2 += "5";
                for (int i = 0; i < end_idx - idx; i++)
                {
                    ans2 += "0";
                }
            }
            idx = end_idx + 1;
        }
        else
        {
            ans2 += "5";
            idx++;
        }
    }
    cout << ans2 << "\n"
         << ans1;
}