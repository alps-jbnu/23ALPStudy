// baekjoon - 2339번 석판자르기

#include <iostream>
using namespace std;

int board[21][21];
int n,imp,jew;

int func(int startx, int starty, int endx, int endy, bool slice) { //slice 참 가로로자름
    int impurities = 0;
    int jewel = 0;
    for(int i=starty;i<endy; i++){
        for(int j=startx;j<endx;j++){
            if(board[i][j] == 2){ //보석있음
                jewel++;
            }
            else if(board[i][j] == 1){ //불순물있음
                impurities++;
            }
        }
    }
    if(jewel == 1 && impurities == 0){ //불순물없고 보석있음 - 진행가능
        return 1;
    }
    else if(jewel == 1 && impurities == 1){ //불순물과 보석이 1개씩이므로 - 자를수없음
        return 0;
    }
    else if(jewel == 0){ //자를수없음
        return 0;
    }
    else if(jewel > 2 && impurities == 0){ //자를수없음
        return 0;
    }
    
    int result = 0;
    for(int i=starty;i<endy; i++){
        for(int j=startx;j<endx;j++){
            if(board[i][j] == 1) { //불순물이면
                if(slice) {  //slice가 참이니깐 이전에 가로로 자른거임 다음은 세로로 자를수 있는가?
                    if(j != startx && j != endx-1) {  //맨앞과 맨끝이 아니여야함
                        bool check = true;
                        for(int k = starty; k<endy; k++) {
                            if(board[k][j] == 2){ //세로에 보석이 있어서 불가능
                                check = false;
                                break;
                            }
                        }
                        if(check) {
                            result = result + func(startx, starty, j, endy, false)*func(j+1, starty, endx, endy, false);
                        }
                    }

                }

                else { //이전에 세로로 잘랐기 때문에 그다음은 가로만 가능
                    if(i!=starty && i != endy-1) {
                        bool check = true;
                        for(int k = startx; k<endx; k++) {
                            if(board[i][k] == 2) { //가로에 보석 
                                check = false;
                                break;
                            }
                        }
                        if(check) {
                            result = result + func(startx, starty, endx, i, true)*func(startx, i+1, endx, endy, true);
                        }

                    }

                }
            }
            
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) { //보석이면
                jew++;
            }
            else if(board[i][j] == 1) { // 불순물이면
                imp++;
            }
        }
    }
    if(imp== 0 && jew == 1) {  //불순물이 없고 보석만 하나면 경우의 수 1
        cout << 1;
    }
    else {
        int resultA = func(0,0,n,n,true);  //가로로 자르기
        int resultB = func(0,0,n,n,false); //세로로 자르기
        if(resultA + resultB == 0) {
            cout << -1;
        }
        else {
            cout << resultA + resultB;
        }
    }
    return 0;

}