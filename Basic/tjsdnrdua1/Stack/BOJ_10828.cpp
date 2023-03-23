#include <iostream>
using namespace std;
const int MX = 100005;
int dat[MX];
int pos = 0;
void Push(int x) { dat[pos++] = x; }
bool Empty() {
    return pos == 0;
}
int Pop() {
    if (pos) return dat[--pos];
    else
        return -1;
}
int Top() {
    if (pos) return dat[pos - 1];
    else
        return -1;
}
int Size() {
    return pos;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int add;
            cin >> add;
            Push(add);
        }
        else if (cmd == "pop")
            cout << Pop() << '\n';
        else if (cmd == "size")
            cout << Size() << '\n';
        else if (cmd == "empty")
            cout << Empty() << '\n';
        else
            cout << Top() << '\n';
    }
}
