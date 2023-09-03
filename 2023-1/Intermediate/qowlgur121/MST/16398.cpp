#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001] = { 0, };      
int map[1001][1001] = { 0, };   //유니온파인드
vector<pair<int, pair<int, int>>> v; // (비용,(출발지,도착지))

// 해당 노드의 루트(최종 부모)를 찾음
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// union : 두 노드를 합침(부모를 같게함)
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (x < y) parent[y] = x;
    else parent[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            std::cin >> map[i][j];
            
    for (int i = 0; i <= N; i++) parent[i] = i; // 초기 부모는 자기 자신

    for (int i = 1; i <= N; i++) {
        // 행렬이기 때문에 0 이후부터 입력만 받음
        for (int j = i + 1; j <= N; j++) {
            v.push_back({ make_pair(map[i][j],make_pair(i,j)) });   //(비용, (출발지, 도착지))
        }
    }

    sort(v.begin(), v.end()); // cost 순으로 오름차순 정렬

    long long ans = 0;

    // cost가 작은 것부터 
    for (int i = 0; i < v.size(); i++) {
        // 싸이클이 발생하면 패스
        if (find(v[i].second.first) == find(v[i].second.second)) continue;  //부모가 같은 경우, find에서 parent 체크
        ans += v[i].first; // 비용 더함
        merge(v[i].second.first, v[i].second.second); // 두 행성(노드)를 합침   , parent 테이블
    }
		std::cout<<ans;
}
