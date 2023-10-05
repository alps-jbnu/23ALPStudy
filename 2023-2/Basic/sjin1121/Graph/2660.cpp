#include <iostream>
#include <vector>
#define INF 10000000
using namespace std;
long long arr[51][51] = {INF};
long long dist[51][51] = {};
int main() {
	long long n, num=INF,val=0;
	long long maxi = -1;
	cin >> n;
	vector<long long>rank;
	vector<long long>candidate;
	for (long long i = 1; i <= n; i++)
		for (long long j = 1; j <= n; j++) {
			if (j == i) arr[i][j] = 0;
			else arr[i][j] = INF;
		}
	while (true) {
		long long a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (long long i = 1; i <= n; i++)
		for (long long j = 1; j <= n; j++)
			dist[i][j] = arr[i][j];
	for (long long k = 1; k <= n; k++) {
		for (long long j = 1; j <= n; j++) {
			for (long long i = 1; i <= n; i++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			if (maxi < dist[i][j])
				maxi = dist[i][j];
		}
		rank.push_back(maxi);
		maxi = -1;
	}	
	for (long long i = 0; i < rank.size(); i++) {
		if (num > rank[i])
		{
			num = rank[i];
			val = 0;
			candidate.clear();
		}
		if (num == rank[i])
		{
			val++;
			candidate.push_back(i + 1);
		}
	}
	cout << num << " " << val << "\n";
	for (long long i = 0; i < candidate.size(); i++) {
		cout << candidate[i] << " ";
	}
	

}
