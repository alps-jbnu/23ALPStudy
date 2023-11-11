#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >>n;
    
    int a[1000001] = {}; //빈배열 생성
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin>>m;

    bool num[2000001];
    int cnt=0;
    for(int i=0;i<n;i++){
        if(m-a[i]>0 && num[m-a[i]]){cnt++;} 
        num[a[i]] = true;
    }

    cout<<cnt<<endl;

    return 0;
}