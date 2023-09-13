#include <iostream>
#include <deque>
#include <vector>
#include <string> 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    string s, t;
    cin >> a;
    for (int j = 0; j < a; j++) {
        deque <int> d, v2;
        vector <char> v1;
        cin >> s >> b >> t;

        for (int i = 0;i < s.size();i++) {
            char c = s[i];
            v1.push_back(c);
        }

        string numStr = "";
        for (int i = 0;i < t.size();i++) {
            char c = t[i];
            if (isdigit(c)) { 
                numStr += c; 
            }
            else if (!numStr.empty()) { 
                v2.push_back(stoi(numStr));
                numStr = ""; 
            }
        }
        if (!numStr.empty()) {
            v2.push_back(stoi(numStr));
        }
        //입력끝
        int e = 0, x = 0;
        for (int i = 0;i < v1.size();i++) {
            if (v1[i] == 'R') {
                if (e == 0) {
                    e = 1;
                }
                else {
                    e = 0;
                }
            }
            else if (v1[i] == 'D') {
                if (v2.empty()) {
                    cout << "error\n";
                    x = 1;
                    break;
                }
                if (e == 0) {
                    //cout << v2.front() << "삭제\n";
                    v2.pop_front();
                }
                else {
                    //cout << v2.back() << "삭제\n";
                    v2.pop_back();
                }
            }
        }
        if (x == 1) {
            continue;
        }

        cout << "[";
        if (e == 1) {
            for (int i = 0;i < v2.size();i++) {
                cout << v2[v2.size()-1-i];
                if (i != v2.size() - 1) {
                    cout << ",";
                }
            }
        }
        else {
            for (int i = 0;i < v2.size();i++) {
                cout << v2[i];
                if (i!=v2.size()-1) {
                    cout << ",";
                }
            }
        }
        cout << "]\n";
        v1.clear();
        v2.clear();
    }
}
