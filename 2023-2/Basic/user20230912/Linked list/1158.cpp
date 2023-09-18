#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> array,solution;

	int n, k, s = 0;
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		array.push_back(i);
	}

	while (array.size() != 1) {
		if ((s + k) <= (array.size() - 1)) {
			s = s + k;
			solution.push_back(array[s]);
			vector<int>::iterator a = array.begin();
			array.erase(a + s);
			s--;
		}
		else {
			while ((s + k) > (array.size() - 1)) {
				s -= (array.size() - 1);
			}
		}
	}
	cout << '<';
	for (int a = 0; a < solution.size(); a++) {
		cout << solution[a];
		if(a != (solution.size()-1))
			cout << ',' << ' ';
		else
			cout << '>';
	}
}
