#define MAX 1001
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, M, T;
vector<int> circles[51];

void print() {
    for(int i{1}; i<=N; i++) {
        for(int j{}; j<circles[i].size(); j++) {
            cout<<circles[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void rotate(int x, int d, int k) {
    auto tmp{circles[x]};
    if(d==0) {
        for(int i{}; i<M; i++) {
            circles[x][(i+k)%M] = tmp[i];
        }
    }
    else {
        for(int i{}; i<M; i++) {
            circles[x][(i-k+51*M)%M] = tmp[i];
        }
    }
}

bool vis[51][51];
void check_same_adj(int num, int level, int idx, int cnt) {
    if(vis[level][idx]) return;
    vis[level][idx] = true;
    if(circles[level][(idx+1)%M]==num) check_same_adj(num, level, (idx+1)%M, cnt+1);
    if(circles[level][(idx-1+M)%M]==num) check_same_adj(num, level, (idx-1+M)%M, cnt+1);
    if(level<N && circles[level+1][idx]==num) check_same_adj(num, level+1, idx, cnt+1);
    if(level>1 && circles[level-1][idx]==num) check_same_adj(num, level-1, idx, cnt+1);
}

pair<int, int> cal_sum_num() {
    pair<int, int> ret{0,0};
    for(int i{1}; i<=N; i++) {
        for(int j{}; j<M; j++) {
            if(circles[i][j]==0) continue;
            ret.first+=circles[i][j];
            ret.second+=1;
        }
    }
    return ret;
}

void change(double avg) {
    for(int i{1}; i<=N; i++) {
        for(int j{}; j<M; j++) {
            if(circles[i][j]==0) continue;
            if(circles[i][j]<avg) circles[i][j]++;
            else if(circles[i][j]>avg) circles[i][j]--;
        }
    }
}

bool find_adj(int find_num, int level, int idx, int find_cnt) {
    check_same_adj(find_num, level, idx, find_cnt);
    int cnt{};
    pair<int, int> chk;
    int num;
    for(int i{1}; i<=N; i++) {
        for(int j{}; j<M; j++) {
            if(vis[i][j]) {
                if(cnt==0) chk = {i, j};
                num = circles[i][j];
                circles[i][j] = 0;
                cnt++;
            }
        }
    }
    if(cnt==1) {
        circles[chk.first][chk.second] = num;
        return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M>>T;
    for(int i{1}; i<=N; i++) {
        for(int j{}; j<M; j++) {
            int num;
            cin>>num;
            circles[i].push_back(num);
        }
    }
    for(int t{}; t<T; t++) {
        int x, d, k;
        cin>>x>>d>>k;
        for(int i{x}; i<=N; i+=x) {
            rotate(i, d, k);
        }
        bool flag{true};
        for(int i{1}; i<=N; i++) {
            for(int j{}; j<M; j++) {
                if(circles[i][j] == 0) continue;
                memset(vis, false, sizeof(vis));
                if(find_adj(circles[i][j], i, j, 1)) flag = false;
            }
        }
        if(flag) {
            pair<int, int> sn{cal_sum_num()};
            change((double)sn.first/(double)sn.second);
        }
    }
    cout<<cal_sum_num().first<<"\n";

    return 0;
}