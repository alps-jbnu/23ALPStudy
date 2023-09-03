#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, num, size;
	int i;
	
	cin >> n;
	
	priority_queue< int, vector<int>, less<int> > max;
	priority_queue<int, vector<int>, greater<int> > min;
	
	for(i=0;i<n;i++)
	{
		cin >> num;
		if(max.size() == min.size())
		{
			max.push(num);
		}
		else
		{
			min.push(num);
		}
		
		if(!max.empty() && !min.empty())
		{
			if(max.top() > min.top())
			{
				int max_val = max.top();
				int min_val = min.top();
				
				max.pop();
				min.pop();
				max.push(min_val);
				min.push(max_val);
			}
		}
		
		cout << max.top() << "\n";
	}
	
	return 0;
}
