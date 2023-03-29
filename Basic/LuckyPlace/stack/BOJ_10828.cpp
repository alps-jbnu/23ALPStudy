#include <iostream>
using namespace std;
const int index = 100005;
int stack[index];
int dat = 0;

void push(int x)
{
	stack[dat] = x;
	dat++;
}

void top()
{
	if (dat > 0)
		cout << stack[dat-1] << endl;
	else
		cout << -1 << endl;
}

void pop()
{
	if (dat > 0)
	{
		cout << stack[dat-1] << endl;
		dat--;
	}
	else
		cout << -1 << endl;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	string str;
	int N;								// ¸í·É È½¼ö
	int input;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> input;
			push(input);
		}
		else if (str == "pop")
		{
			pop();
		}
		else if (str == "top")
		{
			top();
		}
		else if (str == "size")
		{
			cout << dat << endl;
		}
		else if (str == "empty")
		{
			if (dat == 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
	return 0;
}