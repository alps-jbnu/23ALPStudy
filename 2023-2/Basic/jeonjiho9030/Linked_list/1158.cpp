#include <iostream>
#include <string>
using namespace std;

int dat[5005];			//1부터 n까지 저장되는 배열
int nxt[5005];			//다음 주소를 나타내는 배열

int main(void) {
    int n, k;
    cin >> n >> k;
    fill(dat, dat + 5005, -1);
    fill(nxt, nxt + 5005, -1);
    dat[0] = 0;
    nxt[0] = 1;
    for (int i = 1; i <= n; i++) {
        dat[i] = i;			//배열에 1부터 n까지 저장
        if (i != n) nxt[i] = i + 1;	//배열의 끝이 아닐 경우 다음 값인 i+1을 nxt에 저장
        else nxt[i] = 1;		//배열의 끝인 경우 첫번째 노드를 가리키도록 함
    }
    cout << "<";
    int idx = 0;
    int p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {	//k번 만큼
            p = idx;
            idx = nxt[idx];		//다음 주소로 이동
        }
        cout << dat[idx];		//출력
        nxt[p] = nxt[idx];
        if (i != n - 1) cout << ", ";
        else cout << ">";
        
    }
}
