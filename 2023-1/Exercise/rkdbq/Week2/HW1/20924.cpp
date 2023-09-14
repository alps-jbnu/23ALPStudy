#define MAX 200001
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Node {
    public:
    int vertex;
    int length;
    Node(int v, int l) {
        vertex = v;
        length = l;
    }
};

int longestBranchLength;
int columnLength;
bool columnFound;

int N,R;
vector<Node> adj[MAX];

void dfs(int bef, int cur, int totalLength) {
    if(adj[cur].size() == 1 && adj[cur][0].vertex == bef) longestBranchLength = max(longestBranchLength, totalLength);
    else {
        if(!columnFound && adj[cur].size() >= 2) {
            if(adj[cur].size() != 2 || bef == -1) {
                columnLength = totalLength;
                columnFound = true;
            }
        }
        for(int i{}; i<adj[cur].size(); i++) {
            auto nxt{adj[cur][i]};
            if(bef == nxt.vertex) continue;
            dfs(cur, nxt.vertex, totalLength + nxt.length);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>R;
    for(int i{}; i<N-1; i++) {
        int a, b, d;
        cin>>a>>b>>d;
        adj[a].push_back(Node(b, d));
        adj[b].push_back(Node(a, d));
    }

    dfs(-1, R, 0);
    if(!columnFound) columnLength = longestBranchLength;
    longestBranchLength -= columnLength;
    cout<<columnLength<<" "<<longestBranchLength;

    return 0;
}