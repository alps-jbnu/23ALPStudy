#include<iostream>
using namespace std;
int n,s[10],w[10];
int ans;
void func(int cur){
    if(cur==n){//base condition: leaf node in State-Space_Tree
        int cur_ans=0;
        for(int i=0;i<n;i++)
            if(s[i]<1)cur_ans++;
        ans=max(ans,cur_ans);//계란을 최대한 많이 깨야 함.
        return;
    }
    for(int i=0;i<n;i++){
        if(i==cur) continue;//자기 자신 제외
        if(s[cur]>0){//case1: 손에 쥔 계란 멀쩡
            if(s[i]>0){//1-1: 보고 있는 것도 멀쩡
                s[cur]-=w[i];   s[i]-=w[cur];
                func(cur+1);
                s[cur]+=w[i];   s[i]+=w[cur];
            }else{//1-2(s[i]<=0): 보고 있는 건 깨짐
                //1-2-1: 다른 계란들이 모두 깨진 경우
                if(i==n-1||(cur==n-1&&i==n-2))
                    func(cur+1);
                //1-2-2: 다음 계란 보기
                else continue;
            }
        }else//case2:손에 쥔 것부터 깨짐
            func(cur+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i]>>w[i];
    func(0);
    cout<<ans;
}