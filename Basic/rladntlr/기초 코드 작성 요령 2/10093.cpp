//
// Created by 김우식 on 2023/03/13.
//
#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    if(a>b) swap(a,b);
    if(a==b||b-a==1) cout << 0;
    else{
        cout << b-a-1 << "\n";
        for(long long i=a+1;i<b;i++)
            cout <<i << " ";
    }
}