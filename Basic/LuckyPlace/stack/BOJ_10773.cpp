#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	int N;				// �ݺ� Ƚ��
	cin >> N;

	int input;
	int total = 0;
	stack<int> account;
	for (int i = 0; i < N; i++)
	{
	cin >> input;
		if (input == 0)
			account.pop();
		else
			account.push(input);
	}
	int num = account.size();		// for�� ���� acoount.size()�� �������� �����ϸ� pop()�� �� �ǽð����� ũ�Ⱑ �پ� �ݺ�����
	for (int i = 0; i < num; i++)	// ���������� ������� �ʴ´�.
	{
		total += account.top();
		account.pop();
	}
	cout << total;

	return 0;
}
