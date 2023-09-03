#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> adj[32001]; // 인접리스트
vector<string> child[32001]; // 각 사람의 자녀 고유번호 저장
int deg[32001];
unordered_map<string, int> name_map; // pair<string, int>로 시도하다가 실패 -> 구글링

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n;

    string name[n+1];
    for(int i=1; i<=n; i++){
        cin >> name[i];
    }
    sort(name+1, name+n+1);
    
    for(int i=1; i<=n; i++){
        name_map.insert({name[i],i});
    }

    cin >> m;
    for(int i=0; i<m; i++){
        string x, y;
        cin >> x >> y;

        adj[name_map[y]].push_back(name_map[x]);
        deg[name_map[x]]++;
    }

    queue<int> q;
    vector<string> parent; // 최고조상
    
    for(int i=1; i<=n; i++){
        if(deg[i]==0){
            q.push(i);
            parent.push_back(name[i]);
        }
    }
    
    // 가문 개수, 가문의 시조 이름
    sort(parent.begin(), parent.end());
    cout << parent.size() << endl;
    for(int i=0; i<parent.size(); i++) cout << parent[i] << " ";
    cout << endl;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt]==0){
                q.push(nxt);
                child[cur].push_back(name[nxt]);
            }
        }
    }

    for(auto x : name_map){
        cout << x.first << " ";
        cout << child[x.second].size() << " ";

        sort(child[x.second].begin(), child[x.second].end());
        for(auto c : child[x.second]){
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
