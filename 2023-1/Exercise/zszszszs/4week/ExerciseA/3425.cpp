#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
ll n, N;
vector<ll> st;
vector<string> chklist;

void chking(ll y)
{
    st.clear();
    st.push_back(y);

    for (int i = 0; i < chklist.size(); i++)
    {
        s = chklist[i];
        if (s == "NUM")
        {
            i++;
            s = chklist[i];
            st.push_back(stoll(s));
        }
        else if (s == "POP")
        {
            if (st.size() == 0)
            {
                cout << "ERROR";
                return;
            }
            st.erase(st.end() - 1);
        }
        else if (s == "INV")
        {
            if (st.size() == 0)
            {
                cout << "ERROR";
                return;
            }
            st[st.size() - 1] *= -1;
        }
        else if (s == "DUP")
        {
            if (st.size() == 0)
            {
                cout << "ERROR";
                return;
            }
            ll temp = st[st.size() - 1];
            st.push_back(temp);
        }
        else if (s == "SWP")
        {
            if (st.size() < 2)
            {
                cout << "ERROR";
                return;
            }
            swap(st[st.size() - 1], st[st.size() - 2]);
        }
        else if (s == "ADD")
        {
            if (st.size() < 2)
            {
                cout << "ERROR";
                return;
            }
            ll temp = st[st.size() - 1];
            st.erase(st.end() - 1);
            st[st.size() - 1] += temp;
        }
        else if (s == "SUB")
        {
            if (st.size() < 2)
            {
                cout << "ERROR";
                return;
            }
            ll temp = st[st.size() - 1];
            st.erase(st.end() - 1);
            st[st.size() - 1] -= temp;
        }
        else if (s == "MUL")
        {
            if (st.size() < 2)
            {
                cout << "ERROR";
                return;
            }
            ll temp = st[st.size() - 1];
            st.erase(st.end() - 1);
            st[st.size() - 1] *= temp;
        }
        else if (s == "DIV")
        {
            if (st.size() < 2)
            {
                cout << "ERROR";
                return;
            }
            ll temp = st[st.size() - 1];
            if (temp == 0)
            {
                cout << "ERROR";
                return;
            }
            int pm = 0;
            if (st[st.size() - 1] < 0)
            {
                pm++;
            }
            if (st[st.size() - 2] < 0)
            {
                pm++;
            }
            st.erase(st.end() - 1);
            st[st.size() - 1] = abs(st[st.size() - 1]) / abs(temp) * (pm % 2 ? -1 : 1);
        }
        else if (s == "MOD")
        {
            if (st.size() < 2)
            {
                cout << "ERROR";
                return;
            }
            ll temp = st[st.size() - 1];
            if (temp == 0)
            {
                cout << "ERROR";
                return;
            }
            st.erase(st.end() - 1);
            st[st.size() - 1] %= temp;
        }
        if (!st.empty() && abs(st[0]) > 1000000000)
        {
            cout << "ERROR";
            return;
        }
    }
    if (st.size() != 1)
    {
        cout << "ERROR";
        return;
    }

    cout << st[0];
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cc = 0;
    while (cin >> s)
    {
        if (s == "QUIT")
        {
            break;
        }
        else if (s == "END")
        {
            if (cc != 0)
            {
                cout << "\n";
            }
            cc++;
            cin >> N;
            for (int i = 0; i < N; i++)
            {
                cin >> n;
                chking(n);
                cout << "\n";
            }
            chklist.clear();
        }
        else
        {
            chklist.push_back(s);
        }
    }

    return 0;
}