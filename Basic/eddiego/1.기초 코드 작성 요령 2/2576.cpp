//
// Created by 김우식 on 2023/03/12.
//
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,sum=0,odd=0,min=100;

    for(int i=0;i<7;i++){
        cin >> n;

        if(n%2==1) {
            sum += n;
            odd += 1;


            if (n < min)
                min = n;
        }
    }
    if(odd) cout << sum << "\n" << min;
    else cout << "-1";
}