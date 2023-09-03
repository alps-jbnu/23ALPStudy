#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X; cin >> N >> X;
    vector<pair<int,int>> taste; taste.push_back(make_pair(0,0));
    priority_queue<pair<int, int>> pq;
    for(int i = 1; i <= N; i++)
    {
        int A, B; cin >> A >> B;
        taste.push_back(make_pair(A, B));
        pq.push(make_pair(abs(A - B), i));
    }
    int cnt = 0;
    while(true)
    {
        if(cnt * 5000 + (N - cnt) * 1000 > X)
        {
            cnt--;
            break;
        }
        cnt++;
    }
    int answer = 0;
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(taste[cur.second].first > taste[cur.second].second)
        {
            if(cnt <= 0)
            {
                answer += taste[cur.second].second;
            }
            else
            {
                answer += taste[cur.second].first;
                cnt--;
            }
        }
        else
        {
            answer += taste[cur.second].second;
        }
    }
    cout << answer;
    return 0;
}
