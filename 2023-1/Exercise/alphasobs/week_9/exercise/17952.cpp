#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 1000000 + 1;
using namespace std;

ll N, A, T, result = 0;
stack<pii> st;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
    for(int i = 0; i < N; i++)
    {
        int op; cin >> op;
        if(op)
        {
            cin >> A >> T;
            st.push({ T, A });
        }

        if(!st.empty())
        {
            st.top().first--;

            if(!st.top().first)
            {
                result += st.top().second;
                st.pop();
            }
        }
    }
    cout << result;

    return 0;
}