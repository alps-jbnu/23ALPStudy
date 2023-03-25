//
// Created by 김우식 on 2023/03/12.
//
#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin>>a>>b>>c;
    if(a==b&&b==c) cout << 10000 + a*1000;
    else if(a==b||a==c) cout << 1000 + a*100;
    else if(b==c) cout << 1000 + b*100;
    else cout << max({a,b,c}) * 100;
}