#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct cmp {
    bool operator()(pair<int, int> A, pair<int, int> B) {
        if (abs(A.first - A.second) < abs(B.first - B.second)) {
            return true;
        }
        else {
            return false;
        }
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> PQ;
int N, X;
int ans = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> X;

    int max_A_count = X / 5000;
    int B_count = N - max_A_count;

    if ((max_A_count * 5000) + (B_count * 1000) > X) {
        while ((max_A_count * 5000) + (B_count * 1000) > X) {
            max_A_count = max_A_count - 1;
            B_count = N - max_A_count;
        }
    }

    for (int i = 0; i < N; i++) {
        int menu_A, menu_B;

        cin >> menu_A >> menu_B;

        PQ.push({ menu_A , menu_B });
    }

    while (!PQ.empty()) {
        auto k = PQ.top(); PQ.pop();

        int menu_A = k.first;
        int menu_B = k.second;

        //cout << "menu_A: " << menu_A << ' ';
        //cout << "menu_B: " << menu_B << '\n';

        if (menu_A <= menu_B) {
            ans += menu_B;
        } 
        else if (max_A_count > 0) {
            ans += menu_A;
            max_A_count--;
        }
        else {
            ans += menu_B;
        }
    }

    cout << ans;
}

/* 이 반례를 떠올리지 못해서 틀린 제출이 많았다.
2 7000

3 1

300 299

output: 301

ans : 302
*/