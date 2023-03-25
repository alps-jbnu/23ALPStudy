#include <iostream>

int main()
{
	int num1, num2, num3, reward, max,same;
	std::cin >> num1 >> num2 >> num3;
	if (num1 == num2 &&num1 == num3 &&num2==num3)
	{
		reward = 10000 + num1 * 1000;
	}
	else if (num1 != num2 &&num1 != num3 && num2 != num3)
	{
		max = (num1 > num2) ? num1:num2;
		max = (max > num3) ? max : num3;
		reward = max * 100;
	}
	else
	{
		if (num1 == num2)
		{
			same = num1;
		}
		else if (num1 == num3)
		{
			same = num1;
		}
		else
		{
			same = num2;
		}
		reward = 1000 + same * 100;
	}
	std::cout << reward;
	return 0;
}
