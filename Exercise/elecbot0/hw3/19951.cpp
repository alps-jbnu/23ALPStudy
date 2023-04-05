#include <bits/stdc++.h>

using namespace std;

int N, M;
int H[100001];
int cal[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b, k; cin >> a >> b >> k;
        cal[a] += k;
        cal[b + 1] -= k;
    }
    for (int i = 1; i <= N; i++) {
        cal[i] += cal[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        cout << H[i] + cal[i] << " ";
    }
    return 0;
}
