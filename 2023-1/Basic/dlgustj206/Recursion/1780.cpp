#include <iostream>
using namespace std;

int n;
int arr[2187][2187];
int count_m1=0, count_0=0, count_1 =0;
 
void returnnum(int, int, int, int);
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    returnnum(0,n,0,n);

    cout<<count_m1<<'\n';
    cout<<count_0<<'\n';
    cout<<count_1<<'\n';
}

void returnnum(int sx, int ex, int sy, int ey){
    int rn=arr[sx][sy];
    int dx=ex-sx;
    int dy=ey-sy;

    for(int i=sx; i<ex; i++){
        for(int j=sy; j<ey; j++){
            int temp=arr[i][j];
            if(rn!=temp){
                returnnum(sx,sx+dx/3,sy,sy+dy/3);
                returnnum(sx,sx+dx/3,sy+dy/3,sy+dy*2/3);
                returnnum(sx,sx+dx/3,sy+dy*2/3,sy+dy);
                returnnum(sx+dx/3,sx+dx*2/3,sy,sy+dy/3);
                returnnum(sx+dx/3,sx+dx*2/3,sy+dy/3,sy+dy*2/3);
                returnnum(sx+dx/3,sx+dx*2/3,sy+dy*2/3,sy+dy);
                returnnum(sx+dx*2/3,sx+dx,sy,sy+dy/3);
                returnnum(sx+dx*2/3,sx+dx,sy+dy/3,sy+dy*2/3);
                returnnum(sx+dx*2/3,sx+dx,sy+dy*2/3,sy+dy);
                return;
 
            }
        }
    }
    if(rn==-1)
        count_m1++;
    else if (rn==0)
        count_0++;
    else if (rn==1)
        count_1++;
}