#include <iostream>
using namespace std;

bool tf[100][100];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tf[i][j];
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (tf[i][k] && tf[k][j])
					tf[i][j] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << tf[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
