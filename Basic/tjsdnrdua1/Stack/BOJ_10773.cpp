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
    while (n--) {
        int add;
        cin >> add;
        if (add) {
            Push(add);
        }
        else
            Pop();
    }
    int sum = 0;
    for (int i = pos - 1; i > -1; i--)
        sum += dat[i];
    cout << sum;
}
