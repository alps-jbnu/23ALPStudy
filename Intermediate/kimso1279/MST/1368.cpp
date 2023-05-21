#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

tuple<int,int,int> edge[100005];
vector<int> p(10005,-1);

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

    int v,e;
    cin >> v;
    for(int i=0; i<v; i++){
        int a;
        cin >> a;
        edge[e++] = {a, i, v+1};
    }

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            int a;
            cin >> a;
            if(i>=j) continue;
            edge[e++] = {a,i,j};
        }
    }
    v++;
    sort(edge, edge+e);

    int cnt=0, ans=0;
    for(int i=0; i<e; i++){
        int a, b, c;
        tie(c,a,b) = edge[i];
        if(!is_diff_group(a,b)) continue; // 같은 그룹이 아니라면
        ans += c;
        cnt++;
        if(cnt == v-1) break;
    }

    cout << ans;
}
