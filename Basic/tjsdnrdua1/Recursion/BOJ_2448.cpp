//source
//https://ssu-gongdoli.tistory.com/79
#include<iostream>
using namespace std;
int N;
char base[][6]={
"  *  ",
" * * ",
"*****"
};
char map[3210][6543];
void R(int n,int x,int y){
    if(n==1){
        for(int i=0;i<3;i++)
            for(int j=0;j<5;j++)
                map[x+i][y+j]=base[i][j];
        return;
    }
    R(n/2,x,y+3*n/2);
    R(n/2,x+3*n/2,y);
    R(n/2,x+3*n/2,y+3*n);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    R(N/3,0,0);
    for(int i=0;i<N;i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            cout << ((map[i][j] == '*') ? '*' : ' ');
        }
        cout<<'\n';
    }
}