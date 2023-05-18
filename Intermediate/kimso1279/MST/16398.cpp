#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<tuple<int,int,int>> edge;
int p[1004];

int find(int x){
    if(p[x]<0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
    u = find(u);
    v = find(v);
    if(u==v) return 0;
    if(p[u]==p[v]) p[u]--;
    if(p[u]<p[v]) p[v]=u;
    else p[u]= v;
    return 1;
    }

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, c;
    cin >> t;
    fill(p, p + t, -1);

    for(int i=0; i<t; i++){
        for(int j=0; j<t; j++){
            cin >> c;
            if(i != j) edge.push_back({c,i,j});
        }
    }
    sort(edge.begin(), edge.end());

    long long cnt=0, ans=0;
    for(auto edge : edge) {
        int cost, a, b;
        tie(cost, a, b) = edge;
        if(!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        if(cnt == t-1) break;    
    }
    cout << ans;
}
