#include <iostream>
#include <stack>

struct stru3 {
	long long value;
	int node;
	int degener;
};

int i_n;

long long maxarea;

std::stack<int> st;

std::stack<stru3> q;

void calculate1();

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int d;
	while (1) {
		maxarea = 0;
		std::cin >> i_n;
		if (i_n == 0)
			break;
		for (int i = 0; i < i_n; i++) {
			std::cin >> d;
			st.push(d);
		}

		calculate1();

		std::cout << maxarea << '\n';

	}

}


void calculate1() {
	int a = i_n - 1, b = 0;
	long long d = 0; int degener;

	b = a; maxarea;
	stru3 ds;
	for (int i = 0; i < i_n; i++) {
		degener = 0;
		ds = { st.top(), b };
		while(q.size() != 0){
			
			if (q.top().value > ds.value) {
				degener += q.top().degener + 1;
				d = (q.top().value) * (q.top().node - b);
				if (d > maxarea)
					maxarea = d;
				q.pop();
			}
			else
				break;

		}
		ds = { st.top(),b + degener,degener };
		q.push(ds);
		st.pop();

		b--;
	}

	if (q.size() != 0)
		while (q.size() != 0) {
			
			d = (q.top().value) * (q.top().node + 1);
			if (d > maxarea)
				maxarea = d;
			q.pop();
	}

}
