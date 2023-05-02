#include<bits/stdc++.h>
using namespace std;

int pos[100005];
int result;
pair<int, int> ani[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, l;
    cin >> m >> n >> l;

    for (int i = 0; i < m; i++)
        cin >> pos[i];

    for (int i = 0; i < n; i++)
        cin >> ani[i].first >> ani[i].second;

    sort(pos, pos + m);
    sort(ani, ani + n);

    int j = 0;
    for (int i = 0; i < m; i++) {
        for (; j < n; j++) {
            if((i<m-1)&&abs(ani[j].first-pos[i])>abs(ani[j].first-pos[i+1]))
                break;

            if (abs(ani[j].first - pos[i]) + ani[j].second <= l)
                result++;
        }
    }

    cout << result;

    return 0;
}