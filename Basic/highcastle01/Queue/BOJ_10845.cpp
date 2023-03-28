#include<bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x)
{
	dat[tail++] = x;
}

int pop()
{
	return dat[head++];
}

int front()
{
	if(head == tail)
	{
		return -1;
	}
	else
	{
		return dat[head];
	}
}

int back()
{
	if(head == tail)
	{
		return -1;
	}
	else
	{
		return dat[tail-1];
	}
}

int empty()
{
	if(head == tail)
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
	return tail - head;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i, n, x;
	string oder;
	
	cin >> n;
	for(i = 0;i < n; i++)
	{
		cin >> oder;
		if(oder == "push")
		{
			cin >> x;
			push(x);
		}
		else if(oder == "pop")
		{
			if(empty() == 1)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << pop() << "\n";
			}
		}
		else if(oder == "size")
		{
			cout << size() << "\n";
		}
		else if(oder == "empty")
		{
			if(empty() == 1)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if(oder == "back")
		{
			cout << back() << "\n";
		}
		else if(oder == "front")
		{
			cout << front() << "\n";
		}
	}
	
	return 0;
}
