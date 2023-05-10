#include<iostream>
using namespace std;
typedef long long ll;
ll foo(ll a,ll b,ll c){
    if(b==1) return a%c;
    //a^b%c = ((a^(b/2))*(a^(b/2)))%c
//    else if(b%2==0) return foo(a,b/2,c)*foo(a,b/2,c)%c; //overflow
    else if(b%2==0) return (foo(a,b/2,c)*foo(a,b/2,c))%c;

    //a^b%c = ((a*(a^((b-1)/2)*(a^((b-1)/2))%c = (a*(a^((b-1)/2)*(a^((b-1)/2)`%c`))%c //3개 곱하면 overflow --> mod op
//    else return (a%c)*foo(a,(b-1)/2,c)%c*foo(a,(b-1)/2,c)%c;    //overflow
    else return ((a%c)*foo(a,(b-1)/2,c)%c*foo(a,(b-1)/2,c))%c;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b,c;   //a^b mod c
    cin>>a>>b>>c;
    cout<<foo(a,b,c);
    return 0;
}
