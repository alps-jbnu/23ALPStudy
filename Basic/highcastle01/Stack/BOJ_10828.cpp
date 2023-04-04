#include<bits/stdc++.h>

using namespace std;

class Stack
{
	int data[100000];
	int idx;
	
public:
	Stack() { idx = 0;}
	~Stack(){}
	
	void push(int x)
	{
		data[idx++] = x;
	}
	
	void pop()
	{
		idx--;
	}
	
	int top()
	{
		return data[idx-1];
	}
	
	int empty()
	{
		if(idx == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	int size()
	{
		return idx;
	}	
};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i, n, x;
	string str;
	Stack st;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		cin >> str;
		if(str == "push")
		{
			cin >> x;
			st.push(x);
		}
		else if(str == "pop")
		{
			if(st.empty() == 1)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if(str == "size")
		{
			cout << st.size() << "\n";
		}
		else if(str == "empty")
		{
			cout << st.empty() << "\n";
		}
		else if(str == "top")
		{
			if(st.empty() == 1)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << st.top() << "\n";
			}
		}
	}
	
	return 0;
}
