#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 100 + 1;
const int INF = 1e9 + 1;
using namespace std;

int T, N, M, K;
int arr[MAX][MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(i == j) arr[i][j] = 0;
                else arr[i][j] = INF;
            }
        }

        for(int i = 0; i < M; i++)
        {
            int a, b, c; cin >> a >> b >> c;
            arr[a][b] = c;
            arr[b][a] = c;
        }

        for(int k = 1; k <= N; k++)
        {
            for(int i = 1; i <= N; i++)
            {
                for(int j = 1; j <= N; j++)
                {
                    if(arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }

        cin >> K;
        vector<int> vec;
        for(int i = 0; i < K; i++)
        {
            int num; cin >> num;
            vec.push_back(num);
        }

        int result = INF, idx;
        for(int i = 1; i <= N; i++)
        {
            int temp = 0;
            for(int j = 0; j < K; j++)
            {
                temp += arr[i][vec[j]];
            }
            if(result > temp)
            {
                result = temp;
                idx = i;
            }
        }
        cout << idx << "\n";
    }

	return 0;
}