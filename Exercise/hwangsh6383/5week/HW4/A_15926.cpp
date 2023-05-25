#include <bits/stdc++.h>

using namespace std;

bool check[200000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        char c; cin >> c;
        if(c == '(')
            s.push(i);
        else
        {
            if(!s.empty())
            {
                check[s.top()] = true; s.pop();
                check[i] = true;
            }
        }
    }
    int answer = 0, temp = 0;
    for(int i = 0; i < n; i++)
    {
        if(check[i])
        {
            temp++;
            answer = max(answer, temp);
        }
        else
            temp = 0;
    }
    cout << answer;
    return 0;
}
