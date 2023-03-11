#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int,int>, int>> ai_ti;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for(int i = 0; i < N; i++)
    {
        int ai, ti; cin >> ai >> ti;
        ai_ti.push_back(make_pair(make_pair(ai, ti), i));
    }
    sort(ai_ti.begin(), ai_ti.end());

    priority_queue<pair<int, int>,
                        vector<pair<int, int>>,
                                greater<pair<int, int>>> pq;
    pq.push(make_pair(-1, 0));
    int index = 1;
    int answer = 0;
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int timePass = ai_ti[cur.second].first.first + ai_ti[cur.second].first.second;
        while(timePass >= ai_ti[index].first.first)
        {
            pq.push(make_pair(ai_ti[index].second,index));
            index++;
            if(index >= N)
                break;
        }
        while(!pq.empty())
        {
            auto c = pq.top(); pq.pop();
            answer = max(answer, timePass - ai_ti[c.second].first.first);
            timePass += ai_ti[c.second].first.second;
            while(index < N && timePass >= ai_ti[index].first.first)
            {
                pq.push(make_pair(ai_ti[index].second,index));
                index++;
                if(index >= N)
                    break;
            }
        }
        if(index < N - 1)
        {
            pq.push(make_pair(-1, index++));
        }
        else
        {
            break;
        }
    }
    cout << answer;
    return 0;
}
