#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 100 + 1;
using namespace std;

int N, M, cnt = 0;
int arr[MAX][MAX];

bool check()
{
    for (int i=0; i<N; i++)
	{
        for(int j=0; j<M; j++)
		{
            if(arr[i][j] == 1) return false;
        }
    }
    return true;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> M;

    for (int i=0; i<N; i++)
	{
        for(int j=0; j<M; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
    }

    for(int i=N-1; i>=0; i--)
	{
        for(int j=M-1; j>=0; j--)
		{
            if (arr[i][j] == 1)
			{
                cnt++;

                for(int k=0; k<=i; k++)
				{
                    for(int l=0; l<=j; l++)
					{
                        arr[k][l] = (arr[k][l] == 0) ? 1:0;
                    }
                }
            }

            if(check())
			{
                cout << cnt << '\n';
                return 0;
            }
        }
    }
    return 0;
}