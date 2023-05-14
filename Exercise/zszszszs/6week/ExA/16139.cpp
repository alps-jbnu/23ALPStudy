#include <bits/stdc++.h>
using namespace std;

int psum[33][200001];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    char a;

    for (int i = 97; i <= 122; i++)
    {
        if (int(s[0]) == i)
        {
            psum[i - 97][0]++;
        }
    }

    for (int i = 1; i < s.size(); i++)
    {

        for (int j = 97; j <= 122; j++)
        {
            psum[j - 97][i] = psum[j - 97][i - 1];
            if (int(s[i] == j))
            {
                psum[j - 97][i]++;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        int l;
        int r;
        cin >> c >> r >> l;
        r--;
        for (int j = 97; j <= 122; j++)
        {
            if (int(c) == j)
            {
                if (r >= 0)
                {
                    cout << psum[j - 97][l] - psum[j - 97][r] << '\n';
                }
                else
                {
                    cout << psum[j - 97][l] << '\n';
                }
            }
        }
    }
}