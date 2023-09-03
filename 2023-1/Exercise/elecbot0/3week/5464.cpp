#include <bits/stdc++.h>

using namespace std;

int N, M, answer;
int price[101];
int weight[2001];
int parking[101];
int parking_place_num[2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> price[i];
    for (int i = 1; i <= M; i++) cin >> weight[i];
    M *= 2;
    queue<int> waiting_q;
    while (M--) {
        int i; cin >> i;
        if (i > 0) {
            int empty = 0;
            for (int j = 1; j <= N; j++) {
                if (parking[j]) continue;
                empty = j; break;
            }
            if (!empty) waiting_q.emplace(i);
            else {
                parking[empty] = i;
                parking_place_num[i] = empty;
            }
            // 차량 들어오는 것
        } else {
            // 차량 나가는 것
            i = abs(i);
            answer += weight[i] * price[parking_place_num[i]];
            if (!waiting_q.empty()) {
                int waiting = waiting_q.front(); waiting_q.pop();
                parking[parking_place_num[i]] = waiting;
                parking_place_num[waiting] = parking_place_num[i];
            } else {
                parking[parking_place_num[i]] = 0;
            }
            parking_place_num[i] = 0;
        }
    }
    cout << answer;
    return 0;
}
