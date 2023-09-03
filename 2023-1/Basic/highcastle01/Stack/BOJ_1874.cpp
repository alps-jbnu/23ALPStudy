#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string answer;
	stack<int> tmp;
	stack<int> st;
	int i, n, x, cnt = 1;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		cin >> x;
		while(cnt <= x)
		{
			tmp.push(cnt);
			cnt += 1;
			answer += "+";
		}
		if(tmp.top() == x)
		{
			answer += "-";
			tmp.pop();
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	
	for(i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}
	return 0;
}
