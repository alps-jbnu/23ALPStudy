#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,ans,freq[10]={0, };
    cin>>a>>b>>c;
    ans = a*b*c;
    while(ans/10!=0){
        freq[ans%10]++;
        ans/=10;
    }
    freq[ans%10]++;
    for (int i=0;i<10;i++){
        cout<<freq[i]<<'\n';
    }
    return 0;
}
