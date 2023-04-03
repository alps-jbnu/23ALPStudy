#define MAX 201
#include <iostream>
#include <queue>
using namespace std;

class Virus {
    public:
    int num;
    int x;
    int y;
    Virus(int num, int x, int y) {
        this->num = num;
        this->x = x;
        this->y = y;
    }
};

int N, K;
int grid[MAX][MAX];
bool isProliferated[MAX][MAX];
int S, X, Y;

struct cmp {
    bool operator()(Virus a, Virus b){
        return a.num>b.num;
    }
};


void proliferate() {
    priority_queue<Virus, vector<Virus>, cmp> PQ;
    for(int i{}; i<N; i++) {
        for(int j{}; j<N; j++) {
            if(isProliferated[i][j]) continue;
            if(grid[i][j]!=0) {
                PQ.push(Virus(grid[i][j], i, j));
                isProliferated[i][j] = true;
            }
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    while(!PQ.empty()) {
        auto cur = PQ.top();
        PQ.pop();
        for(int i{}; i<4; i++) {
            auto nxt = cur;
            nxt.x += dx[i];
            nxt.y += dy[i];
            if(nxt.x<0 || nxt.x>=N) continue;
            if(nxt.y<0 || nxt.y>=N) continue;
            if(grid[nxt.x][nxt.y] != 0) continue;
            grid[nxt.x][nxt.y] = nxt.num;
        }
    }
}

void printGrid() {
     cout<<"\n";
    for(int i{}; i<N; i++) {
        for(int j{}; j<N; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
     cout<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>K;
    for(int i{}; i<N; i++) {
        for(int j{}; j<N; j++) {
            cin>>grid[i][j];
        }
    }
    cin>>S>>X>>Y;
    for(int i{}; i<S; i++) {
        if(grid[X-1][Y-1] != 0) break;
        proliferate();
        // printGrid();
    }
    cout<<grid[X-1][Y-1];

    return 0;
}