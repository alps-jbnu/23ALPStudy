#include <bits/stdc++.h>

using namespace std;

int N;
int A[1000001];
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    int num = 1;
    dq.push_back(num++);
    for (int i = N - 1; i >= 1; i--) {
        if (A[i] == 1) {
            dq.push_front(num++);
        } else if (A[i] == 2) {
            dq.insert(dq.begin() + 1, num++);
        } else if (A[i] == 3) {
            dq.push_back(num++);
        }
    }
    for (auto it = dq.begin(); it != dq.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}
