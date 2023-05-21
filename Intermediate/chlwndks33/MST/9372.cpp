#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int v, e;
        cin >> v >> e;
        while(e--) {
            int a, b;
            cin >> a >> b;
        }
        cout << v-1 << '\n'; //최소신장트리의 간선의 수는 정점의수-1
    }
}