#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    queue<int> q;
    int num;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        if (str == "push") {
            int X;
            cin >> X;
            q.push(X);

        }
        else if (str == "pop") {
            if (q.size() != 0) {
                num = q.front();
                q.pop();
            }
            else {
                num = -1;
            }
            cout << num << '\n';

        }
        else if (str == "size") {
            cout << q.size() << '\n';

        }
        else if (str == "empty") {
            if (q.size() == 0) 
                num = 1;
            else 
                num = 0;
            cout << num << '\n';

        }
        else if (str == "front") {
            if (q.size() == 0) {
                num = -1;
            }
            else {
                num = q.front();
            }
            cout << num << '\n';

        }
        else if (str == "back") {
            if (q.size() == 0) {
                num = -1;
            }
            else {
                num = q.back();
            }
            cout << num << '\n';
        }
    }
    return 0;
}
