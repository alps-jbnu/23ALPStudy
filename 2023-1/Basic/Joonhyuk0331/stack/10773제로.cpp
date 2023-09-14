#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int result = 0;
	int k = 0;
	cin >> k;
	//stack<int> s; 굳이 스택 안써도 될듯?
	vector<int> v;

	for (int i = 0; i < k; i++) {
		int a = 0;
		cin >> a;
		if (a != 0)
			v.push_back(a);
		else
			v.pop_back();
	}
	for (int i = 0; i < v.size(); i++) {
		result += v[i];
	}
	cout << result << '\n';
}
