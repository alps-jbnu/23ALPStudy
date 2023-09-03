#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("../example.txt", "r", stdin);

    while(true)
    {
        int n, k; cin >> n >> k;
        if(n == 0 && k == 0)
            break;
        map<int,int> pc;
        vector<pair<int,int>> tr;
        int j = -1;
        int root_num; cin >> root_num;
        tr.push_back(make_pair(root_num, j));
        int gp = 0, p = 0;
        bool kisrootORrootc = false;
        for(int i = 1; i < n; i++)
        {
            int num; cin >> num;
            if(tr[i - 1].first + 1 != num)
                j++;
            if(num == k)
            {
                p = j;
                if(p == -1)
                    kisrootORrootc = true;
                gp = tr[p].second;
                if(gp == -1)
                    kisrootORrootc = true;
            }
            tr.push_back(make_pair(num, j));
            if(pc.find(tr[j].first) == pc.end())
                pc[tr[j].first] = 1;
            else
                pc[tr[j].first]++;
        }
        int answer = 0;
        if(!kisrootORrootc)
        {
            vector<int> ps;
            for(int i = 0; i < n; i++)
            {
                if(tr[i].second == gp && tr[i].first != tr[p].first)
                    ps.push_back(tr[i].first);
            }
            for(int i = 0; i < ps.size(); i++)
            {
                answer += pc[ps[i]];
            }
        }
        cout << answer << '\n';
    }
    return 0;
}
