#include <iostream>
using namespace std;

int main(void)
{
	int score;
	cin >> score;
	if (score > 100 || score < 0)
		return 0;
	if (score >= 90 && score <= 100)
		cout << "A" << endl;
	else if (score >= 80 && score <= 89)
		cout << "B" << endl;
	else if (score >= 70 && score <= 79)
		cout << "C" << endl;
	else if (score >= 60 && score <= 69)
		cout << "D" << endl;
	else
		cout << "F" << endl;
	return 0;
}