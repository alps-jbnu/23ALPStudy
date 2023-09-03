#include<iostream>
using namespace std;
int N;
int paper[2200][2200];
int ans[3];
bool check(int n,int x,int y){
    for(int i=x;i<x+n;i++)
        for(int j=y;j<y+n;j++)
            if(paper[x][y]!=paper[i][j])
                return false;
    return true;
}
void recur(int n,int x,int y){
    if(check(n,x,y)){
        ans[paper[x][y]+1]+=1;
        return;
    }
    int new_n=n/3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            recur(new_n,x+i*new_n,y+j*new_n);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>paper[i][j];
    recur(N,0,0);   //(0,0)에서 시작
    for(int e:ans)cout<<e<<'\n';
}