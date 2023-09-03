#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    stack<int> st;
    for (int i = 0; i <= n; i++)
    {
        int x, y;
        if (i != n)
            cin >> x >> y;
        else
            y = 0;
        /

            while (!st.empty() && st.top() >= y)
        {
            if (st.top() != y)
                ans++;
            st.pop();
        }
        st.push(y);
    }
    cout << ans;
    return 0;
}