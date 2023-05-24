#include<iostream>
using namespace std;
int N;
string pixel[66];
//같은 색인지 체크
bool check(int n,int x,int y){
    for(int i=x;i<x+n;i++)
        for(int j=y;j<y+n;j++)
            if(pixel[x][y]!=pixel[i][j])
                return false;
    return true;
}
void R(int n,int x,int y){
    if(check(n,x,y)){
        cout<<pixel[x][y];
        return;
    }
    cout<<"(";
    int new_n=n/2;
    //재귀: 4등분(Divide&Conquer)
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++) {
            R(new_n, x + i * new_n, y + j * new_n);
        }
    cout<<")";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>pixel[i];
    R(N,0,0);
}