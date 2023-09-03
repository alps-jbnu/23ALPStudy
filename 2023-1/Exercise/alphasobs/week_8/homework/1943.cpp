#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 50000 + 1;
using namespace std;

int T = 3, N, result;
int arr[MAX];
vector<pii> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    while(T--)
    {
        result = 0;

        cin >> N;
        for(int i = 0; i < N; i++)
        {
            int num, cnt; cin >> num >> cnt;
            vec.push_back({ num, cnt });
            result += num * cnt;
        }

        if(result % 2 == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        memset(arr, 0, sizeof(arr));

        arr[0] = 1;
        for(int i = 0; i < N; i++)
        {
            for(int j = 50000; j >= vec[i].first; j--)
            {
                if(arr[j - vec[i].first] == 1)
                {
                    for(int k = 0; k < vec[i].second && (j + k * vec[i].first) <= 50000; k++)
                    {
                        arr[j + k * vec[i].first] = 1;
                    }
                }
            }
        }

        if(arr[result / 2] == 1) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    

	return 0;
}