//5464 주차장
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

// 주차장 번호를 우선순위큐에 넣으면 크기 작은 순으로 정렬된다
// 차가 올때마다 우선순위 큐에서 빼서 알맞은 주차장 번호를 할당해준다
// 차가 주차장을 빠져나가면 그 주차장 번호를 우선순위 큐에 반납한다.

int N; //주차공간의 크기
int M; // M대의 차량
int fee[101]; // 주차공간 별 단위 무게당 요금
int vis[101]; // 해당 공간에 차의 유무확인
int car[2001]; //index: 차번호, value: 차의 무게
queue<int> Q; //대기하는 차를 넣어둘 용도
priority_queue<int, vector<int>, greater<>> pq; // 주차장 배치용, 번호가 작은 주차'공간'에 차를 배치시킨다
int ans = 0;

void parking_system(int order) {
    if (order > 0) {
        if (!pq.empty()) {
            int parking_num = pq.top(); pq.pop();
            vis[parking_num] = order;
        }
        else {
            Q.push(order);
        }
    }
    else {
        for (int i = 1; i <= N; i++) {
            if (vis[i] == abs(order)) {
                pq.push(i);
                vis[i] = 0;
                //cout << "요금 " << fee[i] << '\n';
                //cout << "차 무게 " << car[abs(order)] << '\n';
                ans += (fee[i] * car[abs(order)]);

                if (!Q.empty()) {
                    parking_system(Q.front());
                    Q.pop();
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> fee[i];
        pq.push(i);
    }

    for (int i = 1; i <= M; i++) {
        cin >> car[i];
    }

    for (int i = 0; i < 2 * M; i++) {
        int order;
        cin >> order;
        
        parking_system(order);
    }

    cout << ans;
}


