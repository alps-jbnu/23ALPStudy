#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
map<string, int> name_idx;                 
vector<vector<int>> graph(1005);         
vector<string> name;                    // 입력으로 주어진 이름들을 저장하는 벡터
vector<vector<int>> children(1005);  
int N, M;
int indegree[1005];                  // 각 노드의 진입 차수를 저장하는 배열

int main() {
    cin.tie(0); 
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        name.push_back(s);
    }

    sort(name.begin(), name.end());  // 이름들을 사전순으로 정렬
    for (int i = 0; i < N; ++i) 
        name_idx[name[i]] = i;  // 각 이름에 대한 인덱스를 맵에 저장

    cin >> M;   
    for (int i = 0; i < M; ++i) {
        string a, b;
        cin >> a >> b;
        int u = name_idx[a];  
        int v = name_idx[b]; 
        graph[v].push_back(u);  
        indegree[u]++;      
    }
    queue<int> q;
    vector<int> super_father;  // 최상위 조상 노드들의 인덱스를 저장하는 벡터
    for (int i = 0; i < N; ++i) {
        if (indegree[i] == 0) {
            super_father.push_back(i);  
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : graph[cur]) {
            indegree[nxt]--;  // 현재 노드를 거쳐서 갈 수 있는 자식 노드의 진입 차수 감소
            if (indegree[nxt] == 0) {
                children[cur].push_back(nxt);  // 현재 노드와 간선으로 연결된 자식 노드 추가
                q.push(nxt);
            }
        }
    }
    cout << super_father.size() << '\n';  // 최상위 조상의 개수 출력
    for (int i : super_father) cout << name[i] << ' ';  // 최상위 조상들의 이름 출력
    cout << '\n';
    for (int i = 0; i < N; ++i) {
        cout << name[i] << ' ' << children[i].size() << ' ';  
        sort(children[i].begin(), children[i].end());     // 자식들을 사전순으로 정렬
        for (int j : children[i]) cout << name[j] << ' ';     // 자식들의 이름 출력
        cout << '\n';
    }
    return 0;
}
