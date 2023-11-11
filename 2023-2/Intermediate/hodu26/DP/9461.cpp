#include <iostream>
#include <cstring>

using namespace std;

long long int pado_sequence[103] = {1,1,1,2,2};

long long int pado_sequence_over_5th(int N) {
	if (pado_sequence[N-5] == 0) {
		pado_sequence_over_5th(N-5);
	}
	
	if (pado_sequence[N-1] == 0) {
		pado_sequence_over_5th(N-1);
	}

	return pado_sequence[N] = pado_sequence[N-5] + pado_sequence[N-1];
}

int main() {
	int T, N, i;
	scanf("%d", &T);
	for (i=0;i<T;i++) {
		scanf("%d", &N);

		if (N > 5) {
			pado_sequence_over_5th(N-1);
		}
		printf("%lld\n", pado_sequence[N-1]);
	}
	return 0;
}
