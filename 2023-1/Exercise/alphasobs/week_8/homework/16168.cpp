#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 3000 + 1;
using namespace std;

int V, E, result = 0;
int arr[MAX], Visited[MAX];
vector<int> vec[MAX];

void DFS(int x)
{
    if(Visited[x]) return;

    Visited[x] = 1;
    for(int i = 0; i < vec[x].size(); i++)
    {
        arr[x]++;
        DFS(vec[x][i]);
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> V >> E;

    for(int i = 0; i < E; i++)
    {
        int x, y; cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    
    int cnt = 0;
    for(int i = 1; i <= V; i++)
    {
        if(!Visited[i])
        {
            cnt++;
            memset(arr, 0, sizeof(arr));
            DFS(i);

            for(int j = 1; j <= V; j++)
            {
                if(arr[j] % 2 == 1) result++;
            }
        }
        
    }
    if(cnt == 1 && (result == 0 || result == 2))
        cout << "YES";
    else cout << "NO";

	return 0;
}