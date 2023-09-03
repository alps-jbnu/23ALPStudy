//9489 사촌 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int n, k;
int graph[1000001];
vector<int> idx;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    while (1) {
        if (n == 0 && k == 0) {
            break;
        }

        int parent_idx = -1, before = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int node; cin >> node;
            idx.push_back(node);

            if (i == 0) {
                // 루트일 때
                before = node;
                graph[node] = node;
            }
            else {
                if (before + 1 == node) {
                    // node의 값이 그 전과 연속적이라면 같은 부모를 공유하는 노드 
                    graph[node] = idx[parent_idx];
                    before = node;
                }
                else {
                    // node의 값이 그 전과 연속적이지 않다면 같은 부모를 공유하지 않음
                    graph[node] = idx[++parent_idx];
                    before = node;
                }
            }
        }

        for (int n : idx) {
            if (graph[graph[n]] == graph[graph[k]]) {
                // 부모의 부모가 같다면                
                if (graph[n] != graph[graph[k]]) {
                    // n의 부모가 k의 조부모이면 안됨
                    if (graph[n] != graph[k]) {
                        // 부모가 다르다면 (사촌은 부모는 다르고 부모의 부모가 같아야함)
                        if (graph[k] != graph[idx[0]]) {
                            // k의 부모가 루트노드가 아니라면 (예외)
                            ans++;
                        }
                    }
                }
            }          
        }
        cout << ans << '\n';
        idx.clear();

        cin >> n >> k;
    }

}

