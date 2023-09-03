#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true)
    {
        bool quit = false;
        vector<string> v;
        vector<long long> num;
        while(true)
        {
            int x;
            string tp; cin >> tp;
            if(tp == "QUIT")
            {
                quit = true;
                break;
            }
            else if(tp == "END")
            {
                v.push_back(tp);
                break;
            }
            else if(tp == "NUM")
            {
                cin >> x;
                num.push_back(x);
            }
            v.push_back(tp);
        }
        int N; cin >> N;
        vector<int> n;
        for(int i = 0; i < N; i++)
        {
            int number; cin >> number;
            n.push_back(number);
        }
        for(int cur : n)
        {
            stack<long long> st;
            int index = 0;
            st.push(cur);
            for(string s : v)
            {
                if(s == "END")
                {
                    if(st.size() != 1)
                    {
                        cout << "ERROR" << '\n';
                    }
                    else
                    {
                        cout << st.top() << '\n';
                    }
                }
                else if(s == "NUM")
                {
                    st.push(num[index++]);
                }
                else if(s == "POP")
                {
                    if(st.empty())
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    st.pop();
                }
                else if(s == "INV")
                {
                    if(st.empty())
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long x = st.top(); st.pop();
                    st.push(-x);
                }
                else if(s == "DUP")
                {
                    if(st.empty())
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    st.push(st.top());
                }
                else if(s == "SWP")
                {
                    if(st.size() < 2)
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long x = st.top(); st.pop();
                    long long y = st.top(); st.pop();
                    st.push(x); st.push(y);
                }
                else if(s == "ADD")
                {
                    if(st.size() < 2)
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long x = st.top(); st.pop();
                    long long y = st.top(); st.pop();
                    if(x + y > 1000000000 || x + y < -1000000000)
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    st.push(x + y);
                }
                else if(s == "SUB")
                {
                    if(st.size() < 2)
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long x = st.top(); st.pop();
                    long long y = st.top(); st.pop();
                    if(y - x > 1000000000 || y - x < -1000000000)
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    st.push(y - x);
                }
                else if(s == "MUL")
                {
                    if(st.size() < 2)
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long x = st.top(); st.pop();
                    long long y = st.top(); st.pop();
                    if(x * y > 1000000000 || x * y < -1000000000)
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    st.push(x * y);
                }
                else if(s == "DIV")
                {
                    if(st.size() < 2)
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long x = st.top(); st.pop();
                    long long y = st.top(); st.pop();
                    if(x == 0)
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    if(x < 0 && y < 0)
                    {
                        y = -y;
                        x = -x;
                    }
                    long long div = y / x;
                    if(x < 0 && y > 0 && div > 0)
                        div = -div;
                    else if(x > 0 && y < 0 && div > 0)
                        div = -div;
                    st.push(div);
                }
                else if(s == "MOD")
                {
                    if(st.size() < 2)
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long x = st.top(); st.pop();
                    long long y = st.top(); st.pop();
                    if(x == 0)
                    {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long m = y % x;
                    if(m * y < 0)
                        m = -m;
                    st.push(m);
                }
            }
        }
        if(quit) break;
        cout << '\n';
    }
    return 0;
}
