#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 26;
using namespace std;

int N, M, arr[MAX];
char x, y, result;
vector<int> vec[MAX];
queue<int> q;

int BFS(int s, int e)
{
    q.push(s);
    memset(arr, 0, sizeof(arr));
    arr[s] = 1;

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();

        for(auto it : vec[temp])
        {
            if(arr[it]) continue;

            arr[it] = 1;
            q.push(it);
        }
    }
    return arr[e];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> x; cin >> s; cin >> y;

        int a = x - 'a';
        int b = y - 'a';

        vec[a].push_back(b);
    }
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        string s;
        cin >> x; cin >> s; cin >> y;

        int a = x - 'a';
        int b = y - 'a';

        if(BFS(a, b)) cout << "T\n";
        else cout << "F\n";
    }

    return 0;
}