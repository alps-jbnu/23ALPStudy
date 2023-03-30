#include <iostream>
#include <string>
using namespace std;

int main()
{
	int result = 0;
	string aaa, bbb;
	int alpha_a[26] = {}, alpha_b[26] = {};

	cin >> aaa >> bbb;
	for (int i = 0; i < aaa.length(); i++)
		alpha_a[aaa[i] - 'a']++;
	for (int i = 0; i < bbb.length(); i++)
		alpha_b[bbb[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		result += abs(alpha_a[i] - alpha_b[i]);

	cout << result;
}
