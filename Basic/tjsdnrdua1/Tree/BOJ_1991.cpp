#include<iostream>
using namespace std;
int n;
char c,l,r;
int lc[30],rc[30];
void pre(int cur){
    cout<<char(cur+'A'-1);
    if(lc[cur]!=0)pre(lc[cur]);
    if(rc[cur]!=0)pre(rc[cur]);
}
void in(int cur){
    if(lc[cur]!=0)in(lc[cur]);
    cout<<char(cur+'A'-1);
    if(rc[cur]!=0)in(rc[cur]);
}
void post(int cur){
    if(lc[cur]!=0)post(lc[cur]);
    if(rc[cur]!=0)post(rc[cur]);
    cout<<char(cur+'A'-1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c>>l>>r;
        if(l!='.')lc[c-'A'+1]=l-'A'+1;
        if(r!='.')rc[c-'A'+1]=r-'A'+1;
    }
    pre(1);cout<<'\n';
    in(1);cout<<'\n';
    post(1);
}