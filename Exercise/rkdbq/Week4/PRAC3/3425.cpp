#define MAX 1000000000
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// NUM X: X를 스택의 가장 위에 저장한다. (0 ≤ X ≤ 109)
// POP: 스택 가장 위의 숫자를 제거한다.
// INV: 첫 번째 수의 부호를 바꾼다. (42 -> -42)
// DUP: 첫 번째 숫자를 하나 더 스택의 가장 위에 저장한다.
// SWP: 첫 번째 숫자와 두 번째 숫자의 위치를 서로 바꾼다.
// ADD: 첫 번째 숫자와 두 번째 숫자를 더한다.
// SUB: 첫 번째 숫자와 두 번째 숫자를 뺀다. (두 번째 - 첫 번째)
// MUL: 첫 번째 숫자와 두 번째 숫자를 곱한다.
// DIV: 첫 번째 숫자로 두 번째 숫자를 나눈 몫을 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
// MOD: 첫 번째 숫자로 두 번째 숫자를 나눈 나머지를 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.

map<string, int> commands;
stack<int> s;

void clear() {
    while(!s.empty()) s.pop();
}

void NUM(int x) {s.push(x);}
bool POP() {
    if(s.empty()) return false;
    s.pop();
    return true;
}
bool INV() {
    if(s.empty()) return false;
    int tmp = s.top();
    s.pop();
    s.push(-tmp);
    return true;
}
bool DUP() {
    if(s.empty()) return false;
    s.push(s.top());
    return true;
}
bool SWP() {
    if(s.size()<2) return false;
    int tmp[2];
    for(int i{}; i<2; i++) {
        tmp[i] = s.top();
        s.pop();
    }
    for(int i{}; i<2; i++) s.push(tmp[i]);
    return true;
}
bool ADD() {
    if(s.size()<2) return false;
    int tmp[2];
    for(int i{}; i<2; i++) {
        tmp[i] = s.top();
        s.pop();
    }
    if(abs(tmp[1] + tmp[0]) > MAX) return false;
    s.push(tmp[1] + tmp[0]);
    return true;
}
bool SUB() {
    if(s.size()<2) return false;
    int tmp[2];
    for(int i{}; i<2; i++) {
        tmp[i] = s.top();
        s.pop();
    }
    if(abs(tmp[1] - tmp[0]) > MAX) return false;
    s.push(tmp[1] - tmp[0]);
    return true;
}
bool MUL() {
    if(s.size()<2) return false;
    int tmp[2];
    for(int i{}; i<2; i++) {
        tmp[i] = s.top();
        s.pop();
    }
    if(abs((long long)tmp[1] * (long long)tmp[0]) > MAX) return false;
    s.push(tmp[1] * tmp[0]);
    return true;
}
bool DIV() {
    if(s.size()<2) return false;
    int tmp[2];
    for(int i{}; i<2; i++) {
        tmp[i] = s.top();
        s.pop();
    }
    if(tmp[0] == 0) {
        for(int i{1}; i>=0; i--) s.push(tmp[i]);
        return false;
    }
    if(abs(tmp[1] / tmp[0]) > MAX) return false;
    s.push(tmp[1] / tmp[0]);
    return true;
}
bool MOD() {
    if(s.size()<2) return false;
    int tmp[2];
    for(int i{}; i<2; i++) {
        tmp[i] = s.top();
        s.pop();
    }
    if(tmp[0] == 0) {
        for(int i{1}; i>=0; i--) s.push(tmp[i]);
        return false;
    }
    if(abs(tmp[1] % tmp[0]) > MAX) return false;
    s.push(tmp[1] % tmp[0]);
    return true;
}
bool END() {
    return s.size() == 1;
}

bool program() {
    vector<pair<string, int>> cmds;
    while(true) {
        string cmd = "";
        int arg = 0;
        cin>>cmd;
        if(cmd == "QUIT") return false;
        if(cmd == "NUM") cin>>arg;
        cmds.push_back({cmd, arg});
        if(cmd == "END") break;
    }
    int n;
    cin>>n;
    for(int i{}; i<n; i++) {
        int st;
        cin>>st;

        s.push(st);

        bool error_occured = false;
        for(int j{}; j<cmds.size(); j++) {
            string cmd = cmds[j].first;
            int arg = cmds[j].second;
            switch (commands[cmd])
            {
            case 0:
                NUM(arg);
                break;
            case 1:
                if(!POP()) error_occured = true;
                break;
            case 2:
                if(!INV()) error_occured = true;
                break;
            case 3:
                if(!DUP()) error_occured = true;
                break;
            case 4:
                if(!SWP()) error_occured = true;
                break;
            case 5:
                if(!ADD()) error_occured = true;
                break;
            case 6:
                if(!SUB()) error_occured = true;
                break;
            case 7:
                if(!MUL()) error_occured = true;
                break;
            case 8:
                if(!DIV()) error_occured = true;
                break;
            case 9:
                if(!MOD()) error_occured = true;
                break;
            case 10:
                if(!END()) error_occured = true;
                break;
            default:
                break;
            }
            if(error_occured) break;
        }
        if(error_occured) cout<<"ERROR\n";
        else cout<<s.top()<<"\n";
        clear();
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    commands["NUM"] = 0;
    commands["POP"] = 1;
    commands["INV"] = 2;
    commands["DUP"] = 3;
    commands["SWP"] = 4;
    commands["ADD"] = 5;
    commands["SUB"] = 6;
    commands["MUL"] = 7;
    commands["DIV"] = 8;
    commands["MOD"] = 9;
    commands["END"] = 10;

    while(program()) cout<<"\n";
    return 0;
}