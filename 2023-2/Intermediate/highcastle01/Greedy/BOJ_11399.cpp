#include<bits/stdc++.h>
using namespace std;

int nlist[1001];
int mlist[1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n, i, m, sum = 0;
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		cin >> nlist[i];
	}
	
	sort(nlist, nlist + n);
	
	mlist[0] = nlist[0];
	
	for(i = 1; i < n; i++)
	{
		mlist[i] = mlist[i-1] + nlist[i];
	}
	
	for(i = 0; i < n; i++)
	{
		sum += mlist[i];
	}
	
	cout << sum;
    
    return 0;
}
