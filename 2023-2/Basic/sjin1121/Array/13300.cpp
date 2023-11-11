#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, capacity;
    cin >> n >> capacity;
    int arr[2][7] = {};
    for (int i = 0; i < n; i++) {
        int gender, grade;
        cin >> gender >> grade;
        arr[gender][grade]++;
    }
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < 7; j++) {
            cnt += (arr[i][j] + capacity - 1) / capacity;
        }
    }
    cout << cnt;
}
