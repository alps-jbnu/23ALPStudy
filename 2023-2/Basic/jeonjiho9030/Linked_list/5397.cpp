#include <iostream>
#include <string>
using namespace std;

char dat[1000005];
int nxt[1000005], pre[1000005];
int cursor=0;
int unused=1;
int len=0;

void insert(int addr, char c) {				//문자 삽입하는 함수
    dat[unused] = c;				//사용되지 않은 노드에 문자 넣고
    nxt[unused] = nxt[addr];				//새 원소의 다음 주소를 현재 노드의 다음 주소로 하고
    pre[unused] = addr;				//새 원소의 이전 주소를 현재 노드로 함
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;		//끝에 추가하는게 아닐경우 현재 노드 다음 노드의 이전 주소를 새 노드로 함
    nxt[addr] = unused;				//현재 노드의 다음 주소를 새 주소로 함
    cursor = unused;				//커서를 새 노드로 옮김
    unused++;					//사용되지 않은 노드 주소 증가
    len++;					//문자열 길이 증가
}

void erase(int addr) {				//문자 삭제하는 함수
    cursor = pre[addr];				//커서 위치의 앞 문자를 삭제 -> 커서를 한칸 앞으로 이동
    nxt[pre[addr]] = nxt[addr];			//이전 노드의 다음 주소를 현재 노드의 다음 노드로 변경
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];	//끝에 있는 노드가 아닐 경우 다음 노드의 이전 주소를 현재 노드의 이전 주소로 변경
    len--;						//문자열 길이 줄이기
}

void traverse() {					//순회하는 함수
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << "\n";
}

void clear() {
    fill(dat, dat + 1000005, -1);
    unused = 1;
    cursor = 0;
    len = 0;
}

int main(void) {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        fill(pre, pre + 1000005, -1);
        fill(nxt, nxt + 1000005, -1);
        string str;
        getline(cin, str);
        for (char c : str) {
            if (c == '<') {
                if(cursor != 0) cursor = pre[cursor];
            }
            else if (c == '>') {
                if(nxt[cursor] != -1) cursor = nxt[cursor];
            }
            else if (c == '-') {
                if (cursor != 0) {
                    erase(cursor);
                }
            }
            else {
                insert(cursor, c);
            }
        }
        traverse();
        clear();
    }
}
