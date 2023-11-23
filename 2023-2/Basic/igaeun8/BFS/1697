#include <iostream>
#include <queue>
using namespace std;
int n, k;
bool visit[100001];
void bfs(int a){
    queue<pair<int, int>> q;
    q.push(make_pair(a, 0));
    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(x==k){
            cout << cnt;
            break;
        }
        if(x+1 >=0 && x+1<100001){
            if(!visit[x+1] ){
                visit[x + 1] = true;
                q.push(make_pair(x + 1, cnt + 1));
            }
        }
        if(x-1 >=0 && x-1<100001){
            if(!visit[x-1]){
                visit[x - 1] = true;
                q.push(make_pair(x - 1, cnt + 1));
            }
        }
        if(2*x >=0 && 2*x<100001){
            if(!visit[2*x]){
                visit[2*x] = true;
                q.push(make_pair(2 * x, cnt + 1));
            }
        } // 각 다음 좌표마다 q에 넣어준다.
    }
}
int main(){
    cin >> n >> k;
    visit[n] = true;
    bfs(n);
    return 0;
}
