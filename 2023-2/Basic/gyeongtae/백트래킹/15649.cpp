#include <iostream>

using namespace std;

int n, m;
int s = 0;
int map[9];
bool vis[9];

void re(int a) {
    if (a == m) {
        for (int i = 0;i < m;i++) {
            cout << map[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 1;i <= n;i++) {
            if (!vis[i]) {
                vis[i] = true;
                map[a] = i;
                re(a + 1);
                vis[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    re(0);
}
