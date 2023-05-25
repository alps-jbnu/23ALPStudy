#include<iostream>
using namespace std;

int n,m;

int p[9];
int check[9];

void f(int pos)
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
	
	for(i=1;i<=n;i++)
	{
		check[i]=1;
		p[pos]=i;
		f(pos+1);
		check[i]=0;
	}
}

int main(void)
{
  ios::syn_with_stdio(0);
	cin.tie(0);
	cin>>n;
	cin>>m;
	
	f(0);
	
	return 0;
}
