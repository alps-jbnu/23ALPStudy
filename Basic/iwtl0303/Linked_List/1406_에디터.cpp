#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string word;
    char cmd, c;
    int m,len;
    list<char> L;
    cin >> word ;
    len = word.length();
    for (int i=0; i<len; i++) {
        L.push_back(word[i]);
    }
    auto t = L.end();
    cin >> m;

    for(int i=0;i<m;i++){
        cin >> cmd;
        if (cmd == 'L') {
            if (t != L.begin()) t--;
        }
        else if (cmd == 'D') {
            if (t != L.end()) t++;
        }
        else if (cmd == 'B') {
            if(t!=L.begin()) {
                t--;
                t=L.erase(t);
                len--;
                }
        }
        else {
            cin >> c;
            L.insert(t, c);
            len++;
        }
    }
    t=L.begin();
    for(int i=0;i<len;i++) {
        cout << *t;
        t++;
    }
    return 0;
}
