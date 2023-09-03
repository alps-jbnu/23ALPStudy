//19951번 태상이의 훈련소 생활

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int soil[100'005];
int order_sum[100'005]; // 조교의 명령을 합칠 것임
int N, M; // N: 연병장 크기, M: 조교의 수

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> soil[i];
    }

    while (M--) {
        //a번 칸부터 b번 칸까지 높이가 
        //각각 | k | 만큼 늘어나도록 흙을 덮어야 한다.
        // k가 음수면 흙을 파내는 것, 양수면 흙을 쌓는 것
        int a, b, k;
        cin >> a >> b >> k;

        order_sum[a] += k;
        order_sum[b + 1] += (-1) * k;
    }

    for (int i = 1; i <= N; i++) {
        order_sum[i] += order_sum[i - 1];
    }

    for (int i = 1; i <= N; i++) {
        soil[i] = soil[i] + order_sum[i];
        cout << soil[i] << ' ';
    }
}

// 참고 https://yabmoons.tistory.com/729

