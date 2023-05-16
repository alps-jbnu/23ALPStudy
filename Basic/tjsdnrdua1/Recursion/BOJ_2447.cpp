#include<iostream>
using namespace std;
int N;
char ast[2200][2200];   //init. as NULL
void R(int n,int x,int y){
    if(n==1){
        ast[x][y]='*';
        return;
    }
    int new_n=n/3;
    //9개 영역으로 분할 -> 정복
    //정중앙: skip, 나머지 영역: 재귀 호출
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(i==1&&j==1)continue;
            R(new_n,x+i*new_n,y+j*new_n);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    //init. all ast[][] element as ' ' blank
    for(int i=0;i<N;i++)
        fill(ast[i],ast[i]+N,' ');
    R(N,0,0);
    for(int i=0;i<N;i++)
        cout<<ast[i]<<'\n'; //if(ast[i]`[j]`==NULL) cout<<'\n';
}