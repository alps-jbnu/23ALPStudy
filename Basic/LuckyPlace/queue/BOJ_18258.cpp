#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	queue<int> Q;
	int N;
	cin >> N;
	
	while (N--)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			int a;
			cin >> a;
			Q.push(a);
		}
		else if (str == "pop")
		{
			if (Q.empty())
				cout << -1 << '\n';
			else
			{
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if (str == "size")
			cout << Q.size() << '\n';
		else if (str == "empty")
			cout << Q.empty() << '\n';
		else if (str == "front")
		{
			if (Q.empty())
				cout << -1 << '\n';
			else
				cout << Q.front() << '\n';
		}
		else if(str == "back")
		{
			if (Q.empty())
				cout << -1 << '\n';
			else
				cout << Q.back() << '\n';
		}
	}
	return 0;
}
// 시간초과
//int front = 1;
//int rear = 1;
//int queue[2000005];

//int main(void)
//{
//	cin.tie(0);
//	ios::sync_with_stdio(0);
//	int N;
//	cin >> N;
//	while (N--)
//	{
//		string str;
//		cin >> str;
//		if (str == "push")
//		{
//			int input;
//			cin >> input;
//			queue[rear] = input;
//			rear++;
//		}
//		else if (str == "pop")
//		{
//			if (rear == front)
//				cout << -1 << '\n';
//			else
//			{
//				cout << queue[front] << '\n';
//			}
//		}
//		else if (str == "size")
//		{
//			cout << rear - front << '\n';
//		}
//		else if (str == "front")
//		{
//			if (rear == front)
//				cout << -1 << '\n';
//			else
//				cout << queue[front] << '\n';
//		}
//		else if (str == "back")
//		{
//			if (rear == front)
//				cout << -1 << '\n';
//			else
//				cout << queue[rear-1] << '\n';
//		}
//		else
//		{
//			if (rear == front)
//				cout << 1 << '\n';
//			else
//				cout << 0 << '\n';
//		}
//	}
//	return 0;
//}