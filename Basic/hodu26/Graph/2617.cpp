#include <bits/stdc++.h>

using namespace std;

vector<int> lighter[103]; // adjacency list 인접 리스트
vector<int> heavier[103]; // adjacency list 인접 리스트
bool vis[103];

int cntLighter_dfs(int marble, int cntL){

    for (int light : lighter[marble]){
        if (!vis[light]){
            vis[light] = true;
            cntL = cntLighter_dfs(light, cntL+1);
        }
    }

    return cntL;
}

int cntHeavier_dfs(int marble, int cntH){

    for (int heavy : heavier[marble]){
        if (!vis[heavy]){
            vis[heavy] = true;
            cntH = cntHeavier_dfs(heavy, cntH+1);
        }
    }

    return cntH;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,M,heavy,light,cntL,cntH, neverMid=0;

    cin >> N >> M;

    while (M--){
        cin >> heavy >> light;

        lighter[heavy].push_back(light);
        heavier[light].push_back(heavy);
    }

    for (int i=1;i<=N;i++){
        cntL = cntLighter_dfs(i,0);
        fill(vis+1,vis+N+1,false);

        cntH = cntHeavier_dfs(i,0);
        fill(vis+1,vis+N+1,false);

        if (cntH >= (N+1)/2 || cntL >= (N+1)/2){
            neverMid++;
        }
    }

    cout << neverMid;

    return 0;
}
