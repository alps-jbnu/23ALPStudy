#include <bits/stdc++.h>

using namespace std;

string text;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> text;
    vector<char> min_v, max_v;
    int M_cnt = 0;
    for (char c : text) {
        if (c == 'M') {
            M_cnt += 1;
        } else if (c == 'K') {
            for (int j = 0; j < M_cnt; j++) {
                if (j == 0) min_v.push_back('1');
                else min_v.push_back('0');
            }
            min_v.push_back('5');
            for (int j = 0; j < M_cnt + 1; j++) {
                if (j == 0) max_v.push_back('5');
                else max_v.push_back('0');
            }
            M_cnt = 0;
        }
    }
    if (M_cnt > 0) {
        for (int j = 0; j < M_cnt; j++) {
            if (j == 0) {
                min_v.push_back('1');
                max_v.push_back('1');
            } else {
                min_v.push_back('0');
                max_v.push_back('1');
            }
        }
    }
    for (char c : max_v) {
        cout << c;
    }
    cout << "\n";
    for (char c : min_v) {
        cout << c;
    }
    return 0;
}
