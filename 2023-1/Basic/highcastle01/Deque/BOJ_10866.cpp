#include<bits/stdc++.h>

using namespace std;

int MAX = 10001;
int dat[20003];
int head = MAX, tail = MAX;

void push_front(int x)
{
	dat[--head] = x;
}

void push_back(int x)
{
	dat[tail++] = x;
}

int pop_front()
{
	return dat[head++];
}

int pop_back()
{
	return dat[--tail];
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

int front()
{
	if(empty() == 1)
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
	if(empty() == 1)
	{
		return -1;
	}
	else
	{
		return dat[tail-1];
	}
}

int size()
{
	return (MAX-head) + (tail - MAX);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, i, x;
	string oder;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		cin >> oder;
		if(oder == "push_front")
		{
			cin >> x;
			push_front(x);
		}
		else if(oder == "push_back")
		{
			cin >> x;
			push_back(x);
		}
		else if(oder == "pop_front")
		{
			if(empty() == 1)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << pop_front() << "\n";
			}
		}
		else if(oder == "pop_back")
		{
			if(empty() == 1)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << pop_back() << "\n";
			}
		}
		else if(oder == "size")
		{
			cout << size() << "\n";
		}
		else if(oder == "front")
		{
			cout << front() << "\n";
		}
		else if(oder == "back")
		{
			cout << back() << "\n";
		}
		else if(oder == "empty")
		{
			cout << empty() << "\n";
		}
	}
	return 0;
}
