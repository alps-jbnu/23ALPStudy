#include<bits/stdc++.h>
using namespace std;

int parent[10001];

class Edge
{
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance)
    {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }

    bool operator<(Edge &edge) const
    {
        return this->distance < edge.distance;
    }
};

int find_parent(int node)
{
    if(parent[node] == node)
    {
        return node;
    }

    return find_parent(parent[node]);
}

void union_parent(int u, int v)
{
    u = find_parent(u);
    v = find_parent(v);

    if(u < v)
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
    }
}

bool IsCycle(int u, int v)
{
    u = find_parent(u);
    v = find_parent(v);

    if(u == v)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
	int n, m; cin >> n >> m;
	int i, j;
	
	vector<Edge> board;
	
	for(i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
	    board.push_back(Edge(u, v, w));
	}
	
	sort(board.begin(), board.end());

    for(i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
	
	int sum = 0;
	
	for (i = 0; i < board.size(); i++)
    {
        if (!IsCycle(board[i].node[0], board[i].node[1]))
        {
            sum += board[i].distance;
            union_parent(board[i].node[0], board[i].node[1]);
        }
    }
    
    cout << sum;
    
    return 0;
 } 
