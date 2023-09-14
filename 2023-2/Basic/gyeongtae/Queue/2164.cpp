#include <iostream>
#include <queue>

using namespace std;

int main() {
    int a,b,c;
    string n, m;
    queue <int> q;
    cin >> a;
    for (int i = 1;i <= a;i++) {
        q.push(i);
        //cout << q.back() << endl;
    }
    while (q.size() > 1) {
        q.pop();
        b = q.front();
        q.pop();
        q.push(b);
    }
    cout << q.front();
}
