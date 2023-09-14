#include<bits/stdc++.h>
using namespace std;

int point[100005];
long long result;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> point[i];
    }

    sort(point,point+n);

    int index = 1;

    for (int i = 0; i < n; i++) {
        if (point[i] >= index) {
            result += point[i] - index;
            index++;
        }
    }

    cout << result;

    return 0;
}