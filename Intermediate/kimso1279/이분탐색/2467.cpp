#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, arr[100005];
    cin >> n;

    for(int i=0; i<n; i++) cin >> arr[i];
    
    // 양쪽에서 다가오기
    int left = 0;
    int right = n-1;
    
    //결과값 초기화
    long long result = abs(arr[left]+arr[right]);
    long long resultA = arr[left];
    long long resultB = arr[right];

    while(left < right){
        int tmp = arr[left] + arr[right];
        if(abs(tmp) < result){
            result = abs(tmp);
            resultA = arr[left];
            resultB = arr[right];
        }

        if(tmp < 0){
            left++;
        } 
        else{
            right--;
        } 
    }

    cout << resultA << " " << resultB << "\n";

}
