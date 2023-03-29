#include <bits/stdc++.h>
using namespace std;

int s[10];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin>>a>>b>>c;
    int mul=a*b*c;
    while(mul>0){
        s[mul%10]++;
        mul/=10;
    }
    for(int i=0; i<10; i++) cout<<s[i]<<'\n';
}