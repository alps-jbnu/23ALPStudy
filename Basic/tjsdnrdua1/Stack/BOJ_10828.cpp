#include <iostream>
using namespace std;
const int MX = 100005;
int dat[MX];
int pos = 0;
void Push(int x) { dat[pos++] = x; }
bool Empty() {
    return pos == 0;
}
void Pop() {
    pos--;
}
int Top() {
    return dat[pos-1];
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
        else if (cmd == "pop") {
            if (pos) {
                cout << Top() << '\n';
                Pop();
            }
            else { cout << -1 << '\n'; }
        }
        else if (cmd == "size")
            cout << Size() << '\n';
        else if (cmd == "empty")
            cout << Empty() << '\n';
        else {// if(cmd=="top")
            if (pos)
                cout << Top() << '\n';
            else
                cout << -1 << '\n';
        }
    }
}
