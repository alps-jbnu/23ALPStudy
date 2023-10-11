#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<pair<int, int>> S;
    long long ans = 0;
    while (n--) {
        int h;
        cin >> h;
        // 스택에 아무것도 없는 상황에서 새로운 데이터를 만난 경우,
        // 키가 같은 사람을 1명으로 설정한다.
        int cnt = 1;
        while (!S.empty() && S.top().X <= h) {
            // 새로운 데이터가 top보다 큰 경우 키가 같은 사람이 연속된 만큼 쌍에 더한다.
            // 새로운 데이터가 top보다 키가 크다면 자기보다 키가 작은 사람들을 볼 수 있다.
            ans += S.top().Y;
            // 새롭게 만난 데이터가 stack의 탑과 같다면,
            // cnt를 올려줘서 키가 같은 사람이 연속 몇 번인지 센다.
            if (S.top().X == h) cnt += S.top().Y;
            // 현재 데이터가 top보다 클 때까지 pop
            S.pop();
        }
        // 어떤 값에 막히는 경우(not empty) 그 사람을 볼 수 있는 상황 이므로 ans에 1을 더한다.
        if (!S.empty()) ans++;
        // h값을 연속하는 횟수 cnt와 함께 스택에 넣는다.
        S.push({h, cnt});
    }
    cout << ans;
}
