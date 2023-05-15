#include<iostream>
using namespace std;
int N,ans;
bool isused1[15],isused2[30],isused3[30];
void cntCase(int cur){
    if(cur==N){
        ans++;
        return;
    }
    for(int i=0;i<N;i++){
        if(!isused1[i]&&!isused2[cur+i]&&!isused3[cur-i+N-1]){
            isused1[i]=isused2[cur+i]=isused3[cur-i+N-1]=1;
            cntCase(cur+1);
            isused1[i]=isused2[cur+i]=isused3[cur-i+N-1]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cntCase(0);
    cout<<ans;
}