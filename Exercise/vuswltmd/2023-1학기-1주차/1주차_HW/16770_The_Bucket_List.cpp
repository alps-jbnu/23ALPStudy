#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int Time[1005]; // 시간 별 필요한 양동이
int N;

//3번 소   ----2개----
//1번 소       ------1개------
//2번 소               -------3개-------
//시간     1 2 3 4 5 6 7 8 9 10 11 12 13

bool compare(tuple<int, int, int> &A, tuple<int, int, int> &B) {
	if (get<0>(A) < get<0>(B)) {
		return true;
	}
	else if (get<0>(A) == get<0>(B)) {
		if (get<1>(A) < get<1>(B)) {
			return true;
		}
		else if (get<1>(A) == get<1>(B)) {
			if (get<2>(A) < get<2>(B)) {
				return true;
			}
			else{
				return false;
			}
		}
		else {
			false;
		}
	}
	else {
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<tuple<int, int, int>> vec;
	
	while (N--) {
		int s, t, b;
		cin >> s >> t>> b;
		vec.push_back({ s, t, b });
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < vec.size(); i++) {
		int a, b, c;
		tie(a, b, c) = vec[i];

		for (int i = a - 1; i < b - 1; i++) {
			Time[i] += c;
		}
	}
	int Mx = Time[0];
	for (int i = 0; i < 1005; i++) {
		Mx = max(Mx, Time[i]);
	}

	cout << Mx;
}
