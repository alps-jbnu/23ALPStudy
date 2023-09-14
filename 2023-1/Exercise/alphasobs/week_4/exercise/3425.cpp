#include <bits/stdc++.h>
#define ll long long
const ll INF = 1000000000;
using namespace std;

int N;
bool IsError = 0;
string s;
stack<ll> st;
vector<ll> vec;
vector<string> command;

int NUM(ll x)
{
    st.push(x);
    return 0;
}
int POP()
{
    if(st.empty()) return 1;

    st.pop();
    return 0;
}
int INV()
{
    if(st.empty()) return 1;

    ll temp = st.top();
    temp = -(temp);

    st.pop(); st.push(temp);

    return 0;
}
int DUP()
{
    if(st.empty()) return 1;

    ll temp = st.top();
    st.push(temp);

    return 0;
}
int SWP()
{
    if(st.empty()) return 1;
    ll n1 = st.top(); st.pop();

    if(st.empty()) return 1;
    ll n2 = st.top(); st.pop();

    st.push(n1); st.push(n2);

    return 0;
}
int ADD()
{
    if(st.empty()) return 1;
    ll n1 = st.top(); st.pop();

    if(st.empty()) return 1;
    ll n2 = st.top(); st.pop();

    ll temp = n1 + n2;
    st.push(temp);

    return 0;
}
int SUB()
{
    if(st.empty()) return 1;
    ll n1 = st.top(); st.pop();

    if(st.empty()) return 1;
    ll n2 = st.top(); st.pop();

    ll temp = n2 - n1;
    st.push(temp);

    return 0;
}
int MUL()
{
    if(st.empty()) return 1;
    ll n1 = st.top(); st.pop();

    if(st.empty()) return 1;
    ll n2 = st.top(); st.pop();

    ll temp = n2 * n1;
    st.push(temp);

    return 0;
}
int DIV()
{
    int pos = 0;
    if(st.empty()) return 1;
    ll n1 = st.top(); st.pop();
    if(n1 > 0) pos++;
    if(!n1) return 1;

    if(st.empty()) return 1;
    ll n2 = st.top(); st.pop();
    if(n2 > 0) pos++;

    ll temp = n2 / n1;
    if(pos == 1) 
    {
        temp = -(abs(temp));
        st.push(temp);
    }
    else
    {
        temp = abs(temp);
        st.push(temp);
    }

    return 0;
}
int MOD()
{
    int pos = 0;
    
    if(st.empty()) return 1;
    ll n1 = st.top(); st.pop();
    
    if(!n1) return 1;

    if(st.empty()) return 1;
    ll n2 = st.top(); st.pop();
    if(n2 > 0) pos++;

    ll temp = n2 % n1;
    if(pos == 1) 
    {
        temp = abs(temp);
        st.push(temp);
    }
    else
    {
        temp = -(abs(temp));
        st.push(temp);
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(1)
    {
        IsError = 0;
        vec.clear(); 
        command.clear();

        while(1)
        {
            cin >> s;

            if(s == "QUIT") return 0;
            else if(s == "END") break;
            else if(s == "NUM")
            {
                int x; cin >> x;
                vec.push_back(x);
            }

            command.push_back(s);
        }

        cin >> N;
        while(N--)
        {
            int first; cin >> first;
            st.push(first);

            int cnt = 0;

            for(int i = 0; i < command.size(); i++)
            {
                if(command[i] == "NUM") 
                {
                    IsError = NUM(vec[cnt]);
                    cnt++;
                }
                else if(command[i] == "POP") IsError = POP();
                else if(command[i] == "INV") IsError = INV();
                else if(command[i] == "DUP") IsError = DUP();
                else if(command[i] == "SWP") IsError = SWP();
                else if(command[i] == "ADD") IsError = ADD();
                else if(command[i] == "SUB") IsError = SUB();
                else if(command[i] == "MUL") IsError = MUL();
                else if(command[i] == "DIV") IsError = DIV();
                else if(command[i] == "MOD") IsError = MOD();

                if(!st.empty() && (st.top() > INF || st.top() < -INF)) IsError = 1;

                if(IsError) break;
            }
            if(IsError == 1 || st.size() != 1) cout << "ERROR" << "\n";
            else cout << st.top() << "\n";

            while(!st.empty())
            {
                st.pop();
            }
        }
        cout << "\n";
    }
    

    return 0;
}