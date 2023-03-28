// 유니온 파인드 까먹어서 찾아봄
// https://jungahshin.tistory.com/14
#include <bits/stdc++.h>

using namespace std;

int n, m, q, x, y, z;

vector<int> disconnect;
vector<pair<int,int>> v;
bool M[1000005];
int connect[100001];
long long cost[100001];
long long total = 0;

int find(int a){
    if(a==connect[a]){
        return a;
    }else{
        return connect[a] = find(connect[a]);
    }
}

int main(){
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++){
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    for (int i = 0; i < q; i++){
        cin >> z;
        M[z] = 1;
        disconnect.push_back(z);
    }

    for (int i = 1; i <= n; i++){
        cost[i] = 1;
        connect[i] = i;
    }

    for (int i = 0; i < v.size(); i++){
        if(M[i+1]==1){
            continue;
        }
        int a = find(v[i].first);
        int b = find(v[i].second);
        
        if(a!=b){
            connect[a] = b;
            cost[b] += cost[a]; // 자손 노드 개수 세주기라 생각하면 편함
        }
    }
    for (int i =disconnect.size()-1; i>=0; i--){
        int idx = disconnect[i] - 1;
        int a = find(v[idx].first);
        int b = find(v[idx].second);

        if(a!=b){
            connect[a] = b;
            total += cost[a] * cost[b];
            cost[b] += cost[a];
        }
    }

    cout << total << '\n';
    return 0;
}