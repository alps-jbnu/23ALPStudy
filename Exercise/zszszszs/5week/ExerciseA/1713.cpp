#include <bits/stdc++.h>
using namespace std;

int reco[105];
int n;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    int k;
    cin >> k;
    vector<pair<int, int>> v(n, {0, 0});
    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        reco[num]++;

        bool replace = true;
        for (int j = 0; j < n; j++)
        {
            if (v[j].second == 0)
            { // 자리남
                v[j].second = num;
                v[j].first = i;
                replace = false;
                break;
            }
            else if (v[j].second == num)
            { // 똑같은거 있
                replace = false;
                break;
            }
        }
        if (replace)
        {
            int idx = 0;
            for (int j = 1; j < n; j++)
            {
                if (reco[v[j].second] == reco[v[idx].second])
                {
                    if (v[j].first < v[idx].first)
                        idx = j;
                }
                else if (reco[v[j].second] < reco[v[idx].second])
                {
                    idx = j;
                }
            }
            reco[v[idx].second] = 0;
            v[idx].first = i;
            v[idx].second = num;
        }
    }
    vector<int> pic;
    for (int i = 0; i < n; i++)
    {
        pic.push_back(v[i].second);
    }
    sort(pic.begin(), pic.end());
    for (int i = 0; i < n; i++)
    {
        if (pic[i] == 0)
            continue;
        cout << pic[i] << " ";
    }
    return 0;
}