#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int exam[10];
int choice[10];
int ans = 0;

void func(int depth) {
    if (depth == 10) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            if (exam[i] == choice[i])
                sum++;
        }
        // 5점이 넘었다면 경우의 수 count
        if (sum >= 5)
            ans++;

        return;
    }

    for (int i = 1; i <= 5; i++) {
        if (depth >= 2 && choice[depth - 1] == i && choice[depth - 2] == i) {
            continue;
        }

        choice[depth] = i;
        func(depth + 1);
        //choice[depth] = 0;
    }
}

int main() {

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 10; i++) {
        cin >> exam[i];
    }

    func(0);
    cout << ans;
}

