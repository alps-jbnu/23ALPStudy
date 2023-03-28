#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int M, N, L;
int x[100'005];
int y[100'005];
int launch[100'005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> M >> N >> L;

    for (int i = 0; i < M; i++) {
        cin >> launch[i];
    }
    sort(launch, launch + M); //사대의 위치를 삽입하고 정렬

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }  // 동물의 위치를 삽입 

    int ans = 0;

    for (int i = 0; i < N; i++) {
        int st = 0;
        int en = M - 1;
        
        while (st <= en) {
            int mid = (st + en) / 2;

            if (abs(launch[mid] - x[i]) + y[i] <= L) {
                //문제에 나온대로 동물이 여러 사대들을 기준으로 하나의 사대로부터 사정거리안에 있다면 +1 해주고 넘어간다  
                ans++;
                break;
            }

            if (x[i] > launch[mid]) {

                //현재 동물의 x좌표가 mid 인덱스를 지닌 사대보다 더 크다면 위치를 조정한다. 
                st = mid + 1;
                //( 다시 mid를 설정하고 해당 인덱스를 지닌 사대로 넘어간다)
            }
            else {
                en = mid - 1;
            }

        }
    }

    cout << ans;
}

