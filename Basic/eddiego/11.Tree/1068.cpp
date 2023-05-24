#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> child[55];
int del;
int root;
// 문제의 조건대로 del이 root인 subtree를 트리에서 제거한 이후
// x가 root인 subtree에서 leaf node의 수를 반환하는 함수
int go(int x){
    if(x == del) return 0;// x가 del일 경우에는 0 반환
    if(child[x].empty()) return 1; // x 자체가 leaf일 경우 1 반환
    if(child[x].size() == 1 && child[x][0] == del) return 1; // x에 자식 del만 있는 경우 마찬가지로 leaf이니 1 반환
    int ret = 0;
    // x가 leaf가 아닐 경우 go(x) = go(child[x][0])+go(child[x][1])+...
    for(auto nxt : child[x])
        ret += go(nxt);
    return ret;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        if(p == -1){
            root = i;
            continue;
        }
        child[p].push_back(i);
    }
    cin >> del;
    cout << go(root) << '\n';
}

/*
#include <bits/stdc++.h>
using namespace std;

const int MX = 50;

int delnode, cnt, root;
vector<int> child[MX + 2];

void bfs() {
  if(root == delnode) return;
  queue<int> q;
  q.push(root);
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    bool isleaf = 1;
    for(int c : child[cur]) {
      if(c == delnode) continue;
      isleaf = 0;
      q.push(c);
    }
    cnt += isleaf;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int p; cin >> p;
    if(p == -1) { root = i; continue; }
    child[p].push_back(i);
  }

  cin >> delnode;
  bfs();
  cout << cnt;
}

부모 노드 정보를 역으로 활용해 자녀 노드들을 저장한다.
너비 우선 탐색을 통해 자녀 노드들을 돌아본다.
해당 노드에 삭제된 노드가 아닌 자녀 노드가 있는 경우, 이를 리프가 아니라 판정한다.
해당 노드가 리프인 경우 cnt 변수를 하나 증가시킨다.
이후 정답으로 cnt를 출력한다.
*/