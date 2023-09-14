#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int n,m;
int startSize; //시조 size 
int inComing[1001]; // incoming 갯수 
string a, b;
string names[1001]; // names 담는 
unordered_map<string,int> id; // names index 매핑
vector<int> adj[1001]; //간선 
vector<int> ch[1001];  //자녀들 담는
vector<string> startParent;
queue<int> que; //incoming edge가 0인 정점


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> names[i];
    }
    sort(names+1, names+1+n);

    for(int i=1; i<=n; i++) {
        id[names[i]] = i;  // name으로 키 값 설정
    }

    cin >> m;
    for(int i=1; i<=m; i++) {
        cin >> a >> b;
        adj[id[b]].push_back(id[a]);
        inComing[id[a]]++;
    }
    for(int i=1; i<=n; i++) {
        if(inComing[i]==0) {
            que.push(i);  //incoming 0인 edge push
            startSize++;
            startParent.push_back(names[i]);
        }
    }

    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        for(auto nxt: adj[cur]) {
            inComing[nxt]--;
            if(inComing[nxt] == 0) {
                que.push(nxt);
                ch[cur].push_back(nxt); // 자녀 임 
            }
        }
    }
    for(int i=1; i<=n; i++) {
        sort(ch[i].begin(), ch[i].end());
    }
    cout << startSize << '\n';
    for(auto e: startParent)
        cout << e << " ";
    cout << "\n";
    for(int i=1; i<=n; i++) {
        cout << names[i] << " " << ch[i].size() << " ";
        for(auto e: ch[i]) {
            cout << names[e] << " ";
        }
        cout << '\n';
    }




}