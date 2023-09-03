//정점 next의 최소 건설 시간은 선행 정점이 모두 지어진 시간에 자신의 건물을 짓는 시간을 더한 값이다.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        int time[1002];
        for (int i = 1; i <= N; i++) {
            cin >> time[i];
        }

        vector<int> pre_idx[1002];  //먼저 선행되어야 하는 인덱스
        int inDeg[1002] = { 0, };
        queue<int> q;
        int result[1002];

        while (K--) {
            int X, Y;
            cin >> X >> Y;
            pre_idx[X].push_back(Y);
            inDeg[Y]++;
        }

        int final;
        cin >> final;

        for (int i = 1; i <= N; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
            result[i] = time[i];
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < pre_idx[cur].size(); i++) {
                int next = pre_idx[cur][i];
                inDeg[next]--;
                result[next] = max(result[next], result[cur] + time[next]);

                if (inDeg[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << result[final] << endl;
    }

    return 0;
}
