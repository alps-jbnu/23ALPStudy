#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> cow;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		
		int c, m;
		cin >> c >> m;

		cow.push_back({ c, m });
	}

	int count = 0;

	while (1) {
		for (int i = 1; i <= 3; i++) {
			if (count == 100) {
				cout << cow[0].second << '\n';
				cout << cow[1].second << '\n';
				cout << cow[2].second << '\n';

				return 0;
			}

			if(i!=3) {
				if (cow[i].second < cow[i].first) {
					if (cow[i - 1].second > 0) {
						if (cow[i - 1].second + cow[i].second > cow[i].first) {
							int temp = (cow[i-1].second + cow[i].second) - (cow[i].first);
							cow[i].second = cow[i].first;
							cow[i - 1].second =  temp;
						}
						else if (cow[i - 1].second + cow[i].second <= cow[i].first) {
							cow[i].second = cow[i - 1].second + cow[i].second;
							cow[i - 1].second = 0;
						}
					}
				}
				count++;
			}
			else if (i == 3) {
				if (cow[2].second > 0) {
					if (cow[2].second + cow[0].second > cow[0].first) {
						int temp = (cow[0].second + cow[2].second) - (cow[0].first);
						cow[0].second = cow[0].first;
						cow[2].second = temp;
					}
					else if (cow[2].second + cow[0].second <= cow[0].first) {
						cow[0].second = cow[2].second + cow[0].second;
						cow[2].second = 0;
					}
				}

				count++;
			}
	}
	


		
	}
}
