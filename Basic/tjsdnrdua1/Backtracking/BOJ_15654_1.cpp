#include<iostream>
#include<algorithm>
using namespace std;
int n,m,seq[9],ans[9];
bool isused[9];
void func(int cur){
    if(cur==m){
        for(int i=0;i<m;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(!isused[i]){
            ans[cur]=seq[i]; isused[i]=1;
            func(cur+1);
            isused[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>seq[i];
    sort(seq,seq+n);
    func(0);
}