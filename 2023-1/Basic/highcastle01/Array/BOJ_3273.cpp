#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int nlist[1000000];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, i, x;
	
	cin >> n;
	
	int sum, cnt = 0, posa = 0, posb = n - 1;
	
	for(i = 0; i < n; i++)
	{
		cin >> nlist[i];
	}
	
	cin >> x;
	
	sort(nlist, nlist + n);
	
	while(posa < posb)
	{
		sum = nlist[posa] + nlist[posb];
		if(sum > x)
		{
			posb--;
		}
		else if(sum < x)
		{
			posa++;
		}
		else
		{
			cnt++;
			posa++;
			posb--;
		}
	}
	
	cout << cnt;
	return 0;
}

// 벡터로 했다가 배열로 고쳐서 풀었더니 맞았다. 벡터의 성질에 대해 더 알아봐야겠다.
