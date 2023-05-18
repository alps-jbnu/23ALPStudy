#include<iostream>
#include<algorithm>
using namespace std;

int n,m;

int p[9];
int check[9];
int nlist[9];

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
	
	for(i=0;i<n;i++)
	{
		if(check[i]==0)
		{
			check[i]=1;
			p[pos]=nlist[i];
			f(pos+1);
			check[i]=0;
		}
	}
}

int main(void)
{
	int i;
	cin>>n;
	cin>>m;
	
	for(i=0;i<n;i++)
	{
		cin>>nlist[i];
	}
	
	sort(nlist, nlist+n);
	
	f(0);
	
	return 0;
}
