//hint) 원소가 n인 집합의 부분집합 개수: 2^n
#include<iostream>
using namespace std;
int N,S,seq[22];
int ans;
void func(int cur_item,int cur_sum){
    if(cur_item==N){
        if(cur_sum==S)
            ans++;
        return;
    }//case1: 현재 원소 추가x
    func(cur_item+1,cur_sum);
    //case2: 현재 원소 추가o
    func(cur_item+1,cur_sum+seq[cur_item]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>S;
    for(int i=0;i<N;i++)
        cin>>seq[i];
    func(0,0);
    if(S==0)    ans--;
    cout<<ans;
}
