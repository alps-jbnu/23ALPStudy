#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 100000 + 1;
using namespace std;

int N, K;
int l = -1, r = 0;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

    for(int i = 0; i < N; i++)
    {
        int x; cin >> x;
        vec.push_back(x);
    }

    for(int i = 0; i < N; i++)
    {
        r += vec[i];
    }
    r++;

    while(l + 1 < r)
    {
        int cnt = 0, sum = 0, mid = (l + r) / 2;

        for(int i = 0; i < N; i++)
        {
            sum += vec[i];
            
            if(sum >= mid)
            {
                sum = 0;
                cnt++;
            }
        }
        if(cnt >= K) l = mid;
        if(cnt < K) r = mid;
    }

    cout << l;

    return 0;
}