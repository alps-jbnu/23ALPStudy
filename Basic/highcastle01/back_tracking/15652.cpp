#include<iostream>
using namespace std;

int n,m;

int p[9];
int check[9];

void f(int pos,int su)
{
	int i;
	
	if(pos==m)
	{
		for(i=0;i<m;i++)
		{
			cout<<p[i]<<" ";
		}
		cout<<"\n";
		
		return;
	}
	
	for(i=su;i<=n;i++)
	{
		check[i]=1;
		p[pos]=i;
		f(pos+1,i);
		check[i]=0;
	}
}

int main(void)
{
	cin>>n;
	cin>>m;
	
	f(0,1);
	
	return 0;
}
