#include <iostream>
#include <string.h>
using namespace std;

char map[65][65];
void func(int n, int x, int y){
    int size = n/2;
    int check_x, check_y;
    char check;
    int flag = 0;

    if(n==0) return;
    cout << "(";
    for(int i=0; i<4; i++){
        if(i==0){
            //left_top
            check_x = x;
            check_y = y;
        }
        else if(i==1){
            //right_top
            check_x = x;
            check_y = y+size;
        }
        else if(i==2){
            //left_bottom
            check_x = x+size;
            check_y = y;
        }
        else if(i==3){
            //right_bottom
            check_x = x + size;
            check_y = y + size;
        }
        
        flag = 0;
        check = map[check_x][check_y];
        for(int j=0; j<size; j++){
            for(int k=0; k<size; k++){
                if(check != map[check_x+j][check_y+k]){
                    func(size, check_x, check_y);
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) break;
        }
        if(flag == 0) cout << check;
    }
    cout << ")";

}
int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++) cin >> map[i];

    int flag = 0;
    char check = map[0][0];
    for(int j=0; j<N; j++){
        for(int k=0; k<N; k++){
            if(check!= map[j][k]){
                flag = 1;
                break;
            }
        }
        if(flag == 1) break;
    }
    if(flag == 0) cout << check;
    else func(N,0,0);
    cout << "\n";
}
