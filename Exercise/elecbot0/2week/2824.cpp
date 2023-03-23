#include <bits/stdc++.h>

using namespace std;

int N, M;
long long A[1001], B[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    cin >> M;
    for (int i = 1; i <= M; i++) cin >> B[i];
    long long answer = 1;
    bool holy = false;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            long long temp = gcd(A[i], B[j]);
            answer *= temp;
            if (answer >= 1000000000) {
                answer %= 1000000000;
                holy = true;
            }
            A[i] /= temp; B[j] /= temp;
        }
    }
    if (holy) {
        answer += 1000000000;
        string temp = to_string(answer);
        cout << temp.substr(temp.size() - 9, 9);
    } else {
        cout << answer;
    }
    return 0;
}
