//1863 스카이라인 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int N;
int X, Y;
stack<int> st;
int cnt = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        
        while(!st.empty() && st.top() > Y) {
            // 스카이 라인의 높이 낮아질때만 생각
            cnt++;
            st.pop();
        }
        if (!st.empty() && st.top() == Y) continue;
        // 이전 스카이라인 높이와 현재 라인의 높이가 같다면 삽입하지 않고 그냥 넘어감
      
        st.push(Y);
    }
    while (!st.empty()) {
        if (st.top() != 0) {
            //스카이라인의 높이가 0인 경우는 카운트 하지 않음
            cnt++;
        }
        st.pop();
    }
    cout << cnt;
}

