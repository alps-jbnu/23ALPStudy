#include <bits/stdc++.h>
using namespace std;
int arr[100001];

int main(void)
{
	int n = 0;
	cin >> n;
	vector<char> result;
	stack<int> origin;
	stack<int> s;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	for (int i = n; i > 0; i--) {
		origin.push(i);
	}

	s.push(-1);
	int k = 1;
	while (k<=n)
	{
		if (s.top() == arr[k]) {
			s.pop();
			//cout << "-"<<'\n';
			result.push_back('-');
			k++;
		}
		else if (origin.empty() == true) {
			cout << "NO";
			return 0;
		}
		else {
			s.push(origin.top());
			origin.pop();
			//cout << "+"<< '\n';
			result.push_back('+');
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}
}
