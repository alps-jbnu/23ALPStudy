#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
 
int arr[301][301];   //최소이동횟수 담을배열  
bool checked[301][301];
 
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
 
int I;//체스판의 한 변의 길이
queue<pair<int, int>> q;
int srcX, srcY, dstX, dstY;
 
void bfs(int a, int b){
    q.push(make_pair(a, b));
    checked[a][b] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == dstX && y == dstY){
            cout << arr[x][y] << '\n';
            
            while(!q.empty()){
                q.pop();
            }
            break;
        }
        
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < I && ny >= 0 && ny < I){
                if(checked[nx][ny] == false){
                    checked[nx][ny] = true;
                    arr[nx][ny] = arr[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
 
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
 
    for(int i = 0; i < T; i++){
        cin >> I;
        cin >> srcX >> srcY >> dstX >> dstY;
        bfs(srcX, srcY);
        memset(arr, 0, sizeof(arr));
        memset(checked, false, sizeof(checked));
    }
    return 0;
}
