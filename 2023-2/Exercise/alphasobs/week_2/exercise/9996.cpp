#include <bits/stdc++.h>
#define ll long long int
#define MAX 100 + 1
using namespace std;

int N, idx = 0;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> s;

    idx = s.find('*');
    string s1 = s.substr(0, idx);
    string s2 = s.substr(idx + 1, s.length());

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        if (str.length() < s1.length() + s2.length())
        {
            cout << "NE"
                 << "\n";
            continue;
        }

        string str1 = str.substr(0, s1.length());
        string str2 = str.substr(str.length() - s2.length(), str.length());

        if (str1 == s1 && str2 == s2)
            cout << "DA"
                 << "\n";
        else
            cout << "NE"
                 << "\n";
    }

    return 0;
}