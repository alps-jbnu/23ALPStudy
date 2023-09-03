#include<bits/stdc++.h>
using namespace std;

int h[100005];
int mem[100005];
int sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = 1; i <= m; i++) {
        int a, b, k;
        cin >> a >> b >> k;

        mem[a] += k;
        mem[b + 1] -= k;

    }

    for (int i = 1; i <= n; i++) {
        sum += mem[i];
        h[i] += sum;
        cout << h[i] << " ";
    }

    return 0;
}