#include "bits/stdc++.h"
using namespace std;

int main(){
    int arr[9],k,n=0;
    for(int i = 0; i <9;i++){
        cin >> arr[i];
        if(n<=arr[i]){
            n=arr[i];
            k=i;
        }
    }
    cout << n << "\n" << k+1;
}