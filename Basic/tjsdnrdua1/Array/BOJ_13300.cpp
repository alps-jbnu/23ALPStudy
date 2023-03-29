#include <iostream>
using namespace std;
int stu[12];
int	main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	while (N--) {
		int S, G;
		cin >> S >> G;
		if (S == 0 && G == 1) stu[0]++;
		else if (S == 1 && G == 1)stu[1]++;
		else if (S == 0 && G == 2)stu[2]++;
		else if (S == 1 && G == 2)stu[3]++;
		else if (S == 0 && G == 3)stu[4]++;
		else if (S == 1 && G == 3)stu[5]++;
		else if (S == 0 && G == 4)stu[6]++;
		else if (S == 1 && G == 4)stu[7]++;
		else if (S == 0 && G == 5)stu[8]++;
		else if (S == 1 && G == 5)stu[9]++;
		else if (S == 0 && G == 6)stu[10]++;
		else if (S == 1 && G == 6)stu[11]++;
	}
	int room = 0;
	for (int i = 0; i < 12; i++) {
		room += (stu[i] + K - 1) / K;
	}
	cout << room;
}
