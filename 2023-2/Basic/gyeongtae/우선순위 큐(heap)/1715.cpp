#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, compare> pq;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int result = 0;

    while (pq.size() > 1) {
        int n = pq.top();
        pq.pop();

        int m = pq.top();
        pq.pop();

        result += n + m;

        pq.push(n + m);

    }

    cout << result << "\n";
}
