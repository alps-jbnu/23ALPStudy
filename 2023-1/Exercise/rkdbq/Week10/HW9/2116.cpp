#include <iostream>
using namespace std;

int n;
int dices[10001][6];
int ans;

pair<int, int> seq[6]{{0, 5}, {2, 4}, {1, 3}, {5, 0}, {4, 2}, {3, 1}};

int eye_num(int top, int bottom, int level, int cur_eye_num) {
    if(level>=n) return cur_eye_num;
    int nxt_top{}, nxt_bottom{};
    for(int i{}; i<6; i++) {
        if(dices[level][i]==top) {
            nxt_bottom = dices[level][i];
            switch (i)
            {
            case 0:
                nxt_top = dices[level][5];
                break;
            case 1:
                nxt_top = dices[level][3];
                break;
            case 2:
                nxt_top = dices[level][4];
                break;
            case 3:
                nxt_top = dices[level][1];
                break;
            case 4:
                nxt_top = dices[level][2];
                break;
            case 5:
                nxt_top = dices[level][0];
                break;
            default:
                break;
            }
        }
    }
    int nxt_eye_num{};
    for(int i{}; i<6; i++) {
        if(dices[level][i]==nxt_top) continue;
        if(dices[level][i]==nxt_bottom) continue;
        nxt_eye_num = max(nxt_eye_num, dices[level][i]+cur_eye_num);
    }
    return eye_num(nxt_top, nxt_bottom, level+1, nxt_eye_num);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i{}; i<n; i++) {
        for(int j{}; j<6; j++) {
            cin>>dices[i][j];
        }
    }
    int ans{};
    for(int i{}; i<6; i++) {
        int cur_eye_num{};
        for(int j{}; j<6; j++) {
            if(j==seq[i].first || j==seq[i].second) continue;
            cur_eye_num = max(cur_eye_num, dices[0][j]);
        }
        ans = max(ans, eye_num(dices[0][seq[i].first], dices[0][seq[i].second], 1, cur_eye_num));
    }
    cout<<ans<<"\n";

    return 0;
}