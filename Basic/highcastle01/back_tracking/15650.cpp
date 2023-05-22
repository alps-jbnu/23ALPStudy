#include<iostream>
using namespace std;

int n;
int m;
int p[9];
int check[9];

void sun(int pos, int x)
{
    int i;
    if(pos==m)
    {
        for(i=0;i<m;i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<"\n";
    }
    
    for(i=x;i<=n;i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            p[pos]=i;
            sun(pos+1, i+1);
            check[i]=0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin>>n;
    cin>>m;
    sun(0, 1);
    return 0;
}
