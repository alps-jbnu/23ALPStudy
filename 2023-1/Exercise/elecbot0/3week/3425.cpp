#include <bits/stdc++.h>

#define MAX_NUM 1000000000

using namespace std;

stack<long long> s;

// true: 정상 실행, false: error
bool com_handler(pair<string, long long> com_pair) {
    if (com_pair.first == "NUM") {
        s.emplace(com_pair.second);
    } else if (com_pair.first == "POP") {
        if (s.empty()) return false;
        s.pop();
    } else if (com_pair.first == "INV") {
        if (s.empty()) return false;
        long long x = s.top(); s.pop();
        s.emplace(-1 * x);
    } else if (com_pair.first == "DUP") {
        if (s.empty()) return false;
        s.emplace(s.top());
    } else if (com_pair.first == "SWP") {
        if (s.size() < 2) return false;
        long long x1 = s.top(); s.pop();
        long long x2 = s.top(); s.pop();
        s.emplace(x1);
        s.emplace(x2);
    } else if (com_pair.first == "ADD") {
        if (s.size() < 2) return false;
        long long x2 = s.top(); s.pop();
        long long x1 = s.top(); s.pop();
        if (abs(x1 + x2) > MAX_NUM) return false;
        s.emplace(x1 + x2);
    } else if (com_pair.first == "SUB") {
        if (s.size() < 2) return false;
        long long x2 = s.top(); s.pop();
        long long x1 = s.top(); s.pop();
        if (abs(x1 - x2) > MAX_NUM) return false;
        s.emplace(x1 - x2);
    } else if (com_pair.first == "MUL") {
        if (s.size() < 2) return false;
        long long x2 = s.top(); s.pop();
        long long x1 = s.top(); s.pop();
        if (abs(x1 * x2) > MAX_NUM) return false;
        s.emplace(x1 * x2);
    } else if (com_pair.first == "DIV") {
        if (s.size() < 2) return false;
        long long x2 = s.top(); s.pop();
        long long x1 = s.top(); s.pop();
        if (x2 == 0) return false;
        if (abs(x1 / x2) > MAX_NUM) return false;
        s.emplace(x1 / x2);
    } else if (com_pair.first == "MOD") {
        if (s.size() < 2) return false;
        long long x2 = s.top(); s.pop();
        long long x1 = s.top(); s.pop();
        if (x2 == 0) return false;
        if (abs(x1 % x2) > MAX_NUM) return false;
        s.emplace(x1 % x2);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        vector<pair<string, long long>> com_v;
        while (true) {
            string com; cin >> com;
            if (com == "QUIT") return 0;
            if (com == "END") break;
            int num = 0;
            if (com == "NUM") {
                cin >> num;
            }
            com_v.emplace_back(com, num);
        }
        int N; cin >> N;
        while (N--) {
            long long num; cin >> num;
            s.emplace(num);
            bool error = false;
            for (auto com_pair : com_v) {
                error = !com_handler(com_pair);
                if (error) break;
            }
            if (error || s.size() != 1) cout << "ERROR\n";
            else cout << s.top() << "\n";
            while (!s.empty()) s.pop();
        }
        cout << "\n";
    }
    return 0;
}
