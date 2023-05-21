#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 10000 + 1;
using namespace std;

ll N, C, W;
int arr[50 + 1];
ll result = 0, temp = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> C >> W;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if(arr[i] > temp) temp = arr[i];
    }

    for(int i = 1; i < MAX; i++)
    {
        int sum = 0;
        for(int j = 0; j < N; j++)
        {
            int cost, cnt;
            if(arr[j] >= i)
            {
                cost = arr[j] / i;
                if(arr[j] % i) cnt = arr[j] / i;
                else cnt = arr[j] / i - 1;

                int count = cost * W * i - cnt * C;
                if(count > 0) sum += count;
            }
        }
        if(sum > result) result = sum;
    }
    cout << result;

	return 0;
}