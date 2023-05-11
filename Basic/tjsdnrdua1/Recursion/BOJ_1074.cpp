#include<iostream>
using namespace std;
int N,r,c;
int Z(int n,int x,int y){
    if(n==0)return 0;
    int half=1<<(n-1);  //side/2=2^(n-1)
    if(x<half&&y<half)return Z(n-1,x,y);
    else if(x<half&&y>=half)return half*half+Z(n-1,x,y-half);
    else if(x>=half&&y<half)return 2*half*half+Z(n-1,x-half,y);
    return 3*half*half+Z(n-1,x-half,y-half);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>r>>c;
    cout<<Z(N,r,c);
}