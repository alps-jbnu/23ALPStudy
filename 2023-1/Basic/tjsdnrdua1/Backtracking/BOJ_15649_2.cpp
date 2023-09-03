#include<iostream>
#include<algorithm>
using namespace std;
int n,m,arr[10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;  //5 3
    for(int i=0;i<n;i++)
        arr[i]=i+1;
    do{
        for(int i=0;i<m;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        //`12`345 --reverse()--> 12543 --next_perm()--> `13`245
        reverse(arr+m,arr+n);
    }while(next_permutation(arr,arr+n));
}