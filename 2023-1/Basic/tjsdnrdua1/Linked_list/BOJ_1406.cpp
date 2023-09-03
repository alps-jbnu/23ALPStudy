#include <bits/stdc++.h>
using namespace std;
const int MX = 600005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;
void insert(char num,int& idx) {
    dat[unused] = num;
    pre[unused] = idx;
    nxt[unused] = nxt[idx];

    if (nxt[idx] != -1)
        pre[nxt[idx]] = unused;
    nxt[idx] = unused;
    unused++; idx = nxt[idx];
}
void erase(int& idx) {
    nxt[pre[idx]] = nxt[idx];
    if (nxt[idx] != -1)
        pre[nxt[idx]] = pre[idx];
    idx = pre[idx];
}
void traverse() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur];
        cur = nxt[cur];
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

    string ch;
    cin >> ch;
    int curs = 0;
    for (int i = 0; ch[i]!=NULL; i++) {
        dat[i+1] = ch[i];
        pre[i+1] = i;
        nxt[i] = i+1;
        curs++; unused++;
    }
    int cnt;
    cin >> cnt;
    char cmd, Pval;
    while (cnt--) {
        cin >> cmd;
        if (cmd == 'P') {
            cin >> Pval;
            insert(Pval,curs);
        }
        else if (cmd == 'L') {
            if (pre[curs] != -1)                //if(curs != 1)이라고 함..
                curs = pre[curs];
        }
        else if (cmd == 'D') {
            if (nxt[curs] != -1)
                curs = nxt[curs];
        }
        else {
            if (pre[curs] != -1)
                erase(curs);
        }
    }
    traverse();
}
