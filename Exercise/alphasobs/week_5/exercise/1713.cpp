#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long int
const int MAX = 100 + 1;
using namespace std;

int N, V, frame = 0;
int arr[MAX], DP[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> V;
    for(int i = 1; i <= V; i++)
    {
        int x; cin >> x;

        if(arr[x]) arr[x]++;
        else
        {
            if(frame < N)
            {
                arr[x]++;
                DP[x] = i;
                frame++;
            }
            else
            {
                int temp = 1e9, target = 0;
                for(int j = 1; j <= 100; j++)
                {
                    if(!arr[j]) continue;

                    if(temp > arr[j])
                    {
                        target = j;
                        temp = arr[j];
                    }
                    else if(temp == arr[j])
                    {
                        if(DP[j] < DP[target]) target = j;
                    }   
                }
                arr[x]++;
                DP[x] = i;

                arr[target] = 0;
                DP[target] = 0;
            }
        }
    }
    for(int i = 1; i <= 100; i++)
    {
        if(DP[i]) cout << i << " ";
    }

    return 0;
}