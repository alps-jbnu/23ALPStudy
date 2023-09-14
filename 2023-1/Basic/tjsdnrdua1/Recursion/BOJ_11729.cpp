#include<iostream>
using namespace std;
int n;
int k(int s,int t,int x){
    if(x==0) return 0;
    int c=k(s,6-s-t,x-1);
    return 2*c+1;
}
void dis(int s,int t,int x){
    if(x==0) return;
    dis(s,6-s-t,x-1);
    cout<<s<<" "<<t<<'\n';
    dis(6-s-t,t,x-1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cout<<k(1,3,n)<<'\n';
    dis(1,3,n);
}