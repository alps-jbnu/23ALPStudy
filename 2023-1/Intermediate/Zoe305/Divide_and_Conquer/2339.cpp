#include <bits/stdc++.h>
using namespace std;
 
int map[21][21];
 
int func(int x0, int y0, int xi, int yi, bool slice){
    int impurities=0, jewel=0;
    for(int y=y0;y<yi;y++){
        for(int x=x0;x<xi;x++){
            if(map[y][x] == 2){
                jewel++;
            }
            else if(map[y][x] == 1){
                impurities++;
            }
        }
    }
    
    if(jewel == 1 && impurities == 0){
        return 1;
    }
    else if(jewel == 1 && impurities == 1){
        return 0;
    }
    else if(jewel == 0){
        return 0;
    }
    else if(jewel > 2 && impurities == 0){
        return 0;
    }

    int result = 0;
    for(int y=y0;y<yi;y++){
        for(int x=x0;x<xi;x++){
            if(map[y][x] == 1){
                if(slice){
                    if(x!=x0 && x!=xi-1){
                        bool check = true;
                        for(int i=y0;i<yi;i++){
                            if(map[i][x] == 2){
                                check = false;
                                break;
                            }
                        }
                        if(check){
                            result = result + func(x0, y0, x, yi, false)*func(x+1, y0, xi, yi, false);
                        }
                    }
                }
                else{
                    
                    if(y!=y0 && y!=y-1){
                        bool check = true;
                        for(int i=x0;i<xi;i++){
                            if(map[y][i] == 2){
                                check = false;
                                break;
                            }
                        }
                        if(check){
                            result = result + func(x0, y0, xi, y, true)*func(x0, y+1, xi, yi, true);
                        }
                    }
                }
            }
        }
    }
    return result;
}
 
int main(void){
    int N,imp=0,jew=0;
    cin >> N;
    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            cin >> map[y][x];
            if(map[y][x] == 2){
                jew++;
            }
            else if(map[y][x] == 1){
                imp++;
            }
        }
    }
    if(imp==0 && jew == 1){
        cout << 1;
    }
    else{
        int resultA = func(0,0,N,N,true);
        int resultB = func(0,0,N,N,false);
        if(resultA + resultB == 0){
            cout << -1;
        }
        else{
            cout << resultA + resultB;
        }
    }
    return 0;
}