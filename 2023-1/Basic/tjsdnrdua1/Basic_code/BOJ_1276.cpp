#include<iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int sumY = 0;
	int sumM = 0;

	int dur = 0;
	for (int i = 0; i < N; i++) {
		cin >> dur;
		sumY += (dur / 30 + 1) * 10;
		sumM += (dur / 60 + 1) * 15;
	}
	if (sumY < sumM) {
		cout << "Y " << sumY;
	}
	else if (sumY > sumM) {
		cout << "M " << sumM;
	}
	else
		cout << "Y M " << sumY;
}
