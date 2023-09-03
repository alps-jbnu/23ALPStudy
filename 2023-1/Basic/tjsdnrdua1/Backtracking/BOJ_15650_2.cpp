#include<iostream>
#include<algorithm>
using namespace std;
int n,m,seq[10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        if(i<m) seq[i]=0;
        else seq[i]=1;
    }
    do{
        for(int i=0;i<n;i++){
            if(seq[i]==0)
                cout<<i+1<<' ';
        }
        cout<<'\n';
    }while(next_permutation(seq,seq+n));
}