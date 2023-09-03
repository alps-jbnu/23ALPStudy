//
// Created by 김우식 on 2023/03/12.
//
#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    if(a>=90 && a<=100)
        cout << 'A';
    else if(a>=80)
        cout << 'B';
    else if(a>=70)
        cout << 'C';
    else if(a>=60)
        cout << 'D';
    else
        cout << 'F';
}