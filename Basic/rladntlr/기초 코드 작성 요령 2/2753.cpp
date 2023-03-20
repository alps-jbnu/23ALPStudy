//
// Created by 김우식 on 2023/03/12.
//
#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    cin >> a;
    if(a%4==0)
        if(a%100!=0 || a%400==0)
            cout << 1;
        else
            cout <<0;
    else
        cout<<0;
}