#include<iostream>
using namespace std;
int n,m,seq[10];
void func(int cur){
    if(cur==m){
        for(int i=0;i<m;i++)
            cout<<seq[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(seq[cur-1]<=i) {
            seq[cur] = i;
            func(cur + 1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    func(0);
}