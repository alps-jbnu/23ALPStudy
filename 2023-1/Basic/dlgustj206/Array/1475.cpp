#include<iostream>
using namespace std;

int s[10];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int max=0;
    while(n>0){
        s[n%10]++;
        n/=10;
    }
    if(s[6]>0||s[9]>0){
        s[9]+=s[6];
        s[6]=0;
        if(s[9]%2==0)
            s[9]/=2;
        else
            s[9]=(s[9]+1)/2;
    }
    for(int i=0; i<10; i++){
        if(s[i]>max)
            max=s[i];
    }
    cout<<max;
}