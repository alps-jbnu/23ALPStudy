#include<iostream>
using namespace std;

int ans;
int cp[7];

int ReLU(int num) {
    if(num>0) return num;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ans += cp[6];

    ans += cp[5];
    cp[1] -= cp[5] * 11;
    cp[1] = ReLU(cp[1]);

    ans += cp[4];
    cp[2] -= cp[4] * 5;
    if(cp[2] < 0) {
        cp[1] += cp[2] * 4;
        cp[1] = ReLU(cp[1]);
    }
    cp[2] = ReLU(cp[2]);

    ans += (cp[3] / 4);
    cp[3] %= 4;
    if(cp[3] == 1) {
        ans += 1;
        cp[2] -= 5;
        if(cp[2] < 0) {
            cp[1] += cp[2] * 4;
            cp[1] = ReLU(cp[1]);
        }
        cp[2] = ReLU(cp[2]);
    }
    else if(cp[3] == 2) {
        ans += 1;
        cp[2] -= 3;
        if(cp[2] < 0) {
            cp[1] += cp[2] * 4;
            cp[1] = ReLU(cp[1]);
        }
        cp[2] = ReLU(cp[2]);
    }
    else if(cp[3] == 3) {
        ans += 1;
        cp[2] -= 1;
        if(cp[2] < 0) {
            cp[1] += cp[2] * 4;
            cp[1] = ReLU(cp[1]);
        }
        cp[2] = ReLU(cp[2]);
    }

    ans += (cp[2] / 9);
    cp[2] %= 9;
    if(cp[2] > 0) {
        ans += 1;
        cp[1] -= 36 - (cp[2] * 4);
        cp[1] = ReLU(cp[1]);
    }

    
    

    return 0;
}