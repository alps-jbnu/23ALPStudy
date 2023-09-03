#include<bits/stdc++.h>
using namespace std;

string  name;
stack<char> s;
int AP_cnt, P_cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    bool flag = false;

    cin >> name;

    for (int i = 0; i < name.size(); i++)
        s.push(name[i]);

    while (!s.empty()) {
        if (s.top() == 'P') {
            P_cnt++;
            s.pop();
            
            if (AP_cnt > 0 && P_cnt >= 2) {
                AP_cnt -= 1;
                P_cnt -= 2;
                s.push('P');
            }
        }
        else {
            if (P_cnt < 1) {
                flag = true;
                break;
            }
            else {
                AP_cnt++;
                P_cnt = 0;
            }
            s.pop();
        }
    }

    if (flag)
        cout << "NP";
    else {
        if (P_cnt == 1 && AP_cnt == 0)
            cout << "PPAP";
        else
            cout << "NP";
    }

    return 0;
}