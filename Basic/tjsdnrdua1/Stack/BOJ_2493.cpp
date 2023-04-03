#include <bits/stdc++.h>
using namespace std;
int N;
stack<pair<int, int>> tower;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    tower.push({ 100000001, 0 });
    for (int i = 1; i <= N; i++) {
        int height;
        cin >> height;
        while (tower.top().first < height)
            tower.pop();
        cout << tower.top().second << " ";
        tower.push({ height, i });
    }
}