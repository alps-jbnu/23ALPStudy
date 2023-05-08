#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, t;    //사람 수, 파티 수, 진실 아는 사람 수
vector<int> pt[55]; //파티 참석자 저장
vector<int> al[55]; //참석자 연결
bool tr[55]; // 진실을 아는지 여부

// 굳이 vis 배열을 쓸 필요 없이 tr을 vis처럼 쓰면 됨
void bfs() {
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(tr[i]) q.push(i);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt : al[cur]) {
            if(tr[nxt]) continue;
            tr[nxt] = true;
            q.push(nxt);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> t;
    while(t--) {
        int x; cin >> x;
        tr[x] = true;
    }

    for(int i = 0; i < m; i++) {
        int no; cin >> no;  //각 파티별 사람 수

        int prv, nxt;
        cin >> prv;
        pt[i].push_back(prv);

        while(--no) {
            cin >> nxt;
            pt[i].push_back(nxt);
            al[nxt].push_back(prv);
            al[prv].push_back(nxt); // 동일한 파티에 참석한 앞뒤 사람끼리 연결
            swap(prv, nxt);
        }
    }

    bfs(); // bfs 돌리면 간선을 통해 연결된 사람들에게로 진실이 전파됨

    int cnt = 0;
    for(int i = 0; i < m; i++) {
        bool known = false; // 진실을 아는 사람이 파티 내에 있는지
        for(int p : pt[i]) if(tr[p]) known = true;
        if(!known) cnt++;
    }
    cout << cnt;
    return 0;
}