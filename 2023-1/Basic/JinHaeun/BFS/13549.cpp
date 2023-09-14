#include <iostream>
#include <deque>
#include <stdio.h>
#include <iostream>
 
using namespace std;
 
#define MAX_SIZE 100000+1
 
int N, K;
int visited[MAX_SIZE];
 
int bfs() {
    deque<int> dq;
    dq.push_back(N);
    visited[N] = 1;
    while (!dq.empty()) {
         // 덱의 앞의 요소들부터 꺼내기
        int pos_x = dq.front();
        dq.pop_front();
 
        if(pos_x == K) return visited[K] - 1;
 
        // 순간이동 덱 앞쪽에 넣음
        if (pos_x * 2 < MAX_SIZE && !visited[pos_x * 2]) {
            dq.push_front(pos_x * 2);
            visited[pos_x * 2] = visited[pos_x];
        }
 
        // 걷는이동 덱 뒤쪽에 넣음
        if (pos_x + 1 < MAX_SIZE && !visited[pos_x + 1]) {
            dq.push_back(pos_x + 1);
            visited[pos_x + 1] = visited[pos_x] + 1;
        }
        if (pos_x - 1 >= 0 && !visited[pos_x - 1]) {
            dq.push_back(pos_x - 1);
            visited[pos_x - 1] = visited[pos_x] + 1;
        }
    }
}
 
int main() {
    cin >> N >> K;
    cout << bfs() << '\n';
    return 0;
}
