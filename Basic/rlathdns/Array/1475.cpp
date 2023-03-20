#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(void) {
    string number;
    cin >> number;
    int arr[10] = {};
    for(int i = 0; i< number.size(); i++ ){
            arr[number[i] - '0'] ++;//string으로 받은 문자열을 숫자로 변환해 받아주기
    }
    int m = 0;
    for(int i = 0; i<10; i++){
        if(i!=9 && i!=6)m = max(m,arr[i]);//i가 9가 아니거나 6이 아닐경우 최댓값은 arr[i]의 값임
    }
    cout << max(m,(arr[6] + arr[9] +1)/2);
    return 0;
}
