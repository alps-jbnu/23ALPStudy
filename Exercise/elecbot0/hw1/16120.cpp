#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string text; cin >> text;
    int p_cnt = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 'P') {
            p_cnt += 1;
            continue;
        }
        if (p_cnt >= 2 && text[i + 1] == 'P') {
            p_cnt -= 1;
            i++;
        } else {
            cout << "NP";
            return 0;
        }
    }
    if (p_cnt == 1) cout << "PPAP";
    else cout << "NP";
    return 0;
}
