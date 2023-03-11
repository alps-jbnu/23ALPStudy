#include <bits/stdc++.h>
const int MAX = 1e5;
using namespace std;

struct tup
{
    int l, s, t;
};

struct compare {
    bool operator()(tup a, tup b) {
        return a.l > b.l;
    }
};
bool operator<(tup const a, tup const b) {
    if (a.s == b.s)
        return a.l < b.l;
    return a.s < b.s;
};

int N;
tup x;
tup vec[MAX];
priority_queue<tup, vector<tup>, compare> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        vec[i].l = i; cin >> vec[i].s >> vec[i].t;
    }
    sort(vec, vec + N);

    int result = -1;
    for (int i = 0; i <= N;)
    {
        if (pq.empty())
        {
            x.s = vec[i].s + vec[i].t;
            i++;
        }
        else
        {
            tup cur = pq.top();
            pq.pop();

            result = max(result, x.s - cur.s);
            x.s += cur.t;
        }
        int temp = lower_bound(vec + i, vec + N, x) - vec;

        for (; i < temp; i++)
        {
            pq.emplace(vec[i]);
        }
    }
    cout << result;

    return 0;
}