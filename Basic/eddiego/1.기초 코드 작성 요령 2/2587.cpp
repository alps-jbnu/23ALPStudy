//
// Created by 김우식 on 2023/03/13.
//
#include "bits/stdc++.h"
using namespace std;

int a[5],sum;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<5;i++)
        cin >> a[i];
    for(int i=0;i<5;i++)
        sum += a[i];
    cout << sum/5 << "\n";

    sort(a,a+5);
    cout << a[2];
}