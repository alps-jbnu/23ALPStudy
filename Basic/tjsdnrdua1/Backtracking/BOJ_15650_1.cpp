#include<iostream>
using namespace std;
int n,m,seq[10];
bool isused[10];
void func(int cur){
    if(cur==m){
        for(int i=0;i<m;i++)
            cout<<seq[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        //중복 피하기 위해 seq[] 오름차순
        if(!isused[i]&&seq[cur-1]<=i){
            seq[cur]=i; isused[i]=1;
            func(cur+1);
            isused[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    func(0);
}