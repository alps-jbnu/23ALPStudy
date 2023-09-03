#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second
const int MX=105;
string reg[MX];
bool parseReg[MX][MX];   //parse region: R,G=true, B=false
bool hVis[MX][MX],cVis[MX][MX]; //isHumanVisited...
int dx[]={1,0,-1,0}; int dy[]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> hQ;
    queue<pair<int,int>> cQ;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>reg[i];
        for(int j=0;j<n;j++){
            if(reg[i][j]=='R'||reg[i][j]=='G')  parseReg[i][j]=true;
            else if(reg[i][j]=='B') parseReg[i][j]=false;
        }
    }
    int hReg=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if (hVis[i][j])continue;
            hVis[i][j]=0; hQ.push({i,j});
            while (!hQ.empty()) {
                auto cur = hQ.front();
                hQ.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
                    if (hVis[nx][ny])continue;
                    if (reg[nx][ny] != reg[cur.X][cur.Y])continue;
                    hVis[nx][ny] = true;
                    hQ.push({nx, ny});
                }
            }
            hReg++;
        }
    }
    int cReg=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if (cVis[i][j])continue;
            cVis[i][j]=0; cQ.push({i,j});
            while (!cQ.empty()) {
                auto cur = cQ.front();
                cQ.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
                    if (cVis[nx][ny])continue;
                    //xor operator: skip if color's different by Cow's view
                    if (parseReg[nx][ny]^parseReg[cur.X][cur.Y])continue;
                    cVis[nx][ny] = true;
                    cQ.push({nx, ny});
                }
            }
            cReg++;
        }
    }
    cout<<hReg<<" "<<cReg;
}