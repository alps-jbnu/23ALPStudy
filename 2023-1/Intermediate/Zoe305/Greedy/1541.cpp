#include <bits/stdc++.h>
using namespace std;

int tmp, ans;
int sign = 1;
string input;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> input;

    for(char c: input){
        if(c == '+' || c == '-'){
            ans += tmp * sign;
            if(c == '-') sign = -1;
            tmp = 0;
        }else{
            tmp *= 10;
            tmp += c - '0';
        }
    }
    ans += tmp * sign;
    cout << ans;
}

/*
-가 나오면 그 뒤로는 다 빼버리자는 아이디어는 생각해 냄.
문자열을 정수형으로 바꾸는 부분을 까먹어서 해설 봄.
*/