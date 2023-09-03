#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pdi pair<double, int>
const int MAX = 1000 + 1;
using namespace std;

struct st 
{
	int dist;
	int x;
	int y;
};
struct compare 
{
	bool operator()(st a, st b) 
    {
		if (a.dist > b.dist) return 1;
		return 0;
	}
};

int N, M, flag = 0, vertex = 0, result = 0;
int arr[MAX][MAX];
int parent[MAX];
vector<st> vec;
priority_queue<st, vector<st>, compare> pq;

int Find(int x)
{
    if(parent[x] == x) return x;
    else return x = Find(parent[x]);
}

int Union(int x, int y)
{
    x = Find(x); y = Find(y);
    if(x == y) return 0;
    else
    {
        parent[x] = y;
        return 1;
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) parent[i] = i;

    for(int i = 0; i < M; i++)
    {
        int x, y; cin >> x >> y;
        if(Find(x) != Find(y))
        {
            Union(x, y);
            vertex++;
        }
    }

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            if(i == j || i == 1 || j == 1) continue;

            int px = Find(i);
            int py = Find(j);

            if(px != py) pq.push({ arr[i][j], i, j });
        } 

    while(!pq.empty())
    {
        int ndis = pq.top().dist;
        int nx = pq.top().x;
        int ny = pq.top().y;
        pq.pop();

        if(Find(nx) != Find(ny))
        {
            Union(nx, ny);
            vec.push_back({ 0, nx, ny });
            result += ndis;
            vertex++;
        }
        if(vertex == N - 2) break;
    }

    cout << result << " " << vec.size() << "\n";

    if(vec.empty()) cout << "0\n";
    else
    {
        for(int i = 0; i < vec.size(); i++)
        {
            cout << vec[i].y << " " << vec[i].x << "\n";
        }
    }

    return 0;
}