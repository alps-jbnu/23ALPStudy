#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

int N;
int chain[500005];
deque<int> dq;
int ans = 0;

int main() {
    
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> chain[i];
    }

    sort(chain, chain + N);

    for (int i = 0; i < N; i++) {
        dq.push_back(chain[i]);
    }
    int key = dq.front(); dq.pop_front();
    
    while (dq.size() != 1) {
        if (key == 0) {
            key = dq.front(); dq.pop_front();
        }
        
        key--;
        ans++;

        for (int i = 0; i < 1; i++) {
            if (!dq.empty()) {
                dq.pop_back();
            }
        }
    }

    if (key != 0) {
        cout << ans + 1;
    }
    else {
        cout << ans;
    }
}

// (체인의 길이가 낮은 것부터 (코드에서는 해당 체인의 길이를 key라고 함) ) 하나씩 풀어서 다른 두 체인을 연결하는데 사용한다.
// 연결하다가 key 체인을 다 써버리면 다음 체인을 사용한다
// key 체인을 다 사용하지 않았는데도 나머지를 다 연결하는데 성공했다면 key를 마지막으로 붙인다.

