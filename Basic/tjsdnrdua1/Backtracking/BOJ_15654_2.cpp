#include<iostream>
#include<algorithm>
using namespace std;
int n,m,seq[9];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>seq[i];
    sort(seq,seq+n);
    do{
        for(int i=0;i<m;i++){
            cout<<seq[i]<<' ';
        }cout<<'\n';
        reverse(seq+m,seq+n);
    }while(next_permutation(seq,seq+n));
}