// long long 이용 문제
#include<iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long i, A, B, cnt, tmp;
	
	cin >> A >> B;
	
	if(A == B)
	{
		cnt = 0;
	}
	else
	{
		if(A > B)
		{
			tmp = A;
			A = B;
			B = tmp;
		}
		cnt = B - (A+1);
	}
	
	if(cnt != 0)
	{
		cout << cnt << "\n";
		
		for(i = 1; i < cnt + 1; i++)
		{
			cout << A + i << " ";
		}
	}
	else
	{
		cout << cnt;
	}
	
	return 0;
}
