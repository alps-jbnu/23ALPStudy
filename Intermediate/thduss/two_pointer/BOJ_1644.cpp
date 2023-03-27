#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

	int n;
	cin >> n;
	vector<bool> v(n+1,1);

	//에라토스테네스의 체
	for(int i=2; i*i <= n; i++){
		if(v[i] == 0) continue;
		for(int j=i*2; j<=n; j+=i){
			v[j] = 0;
		}
	}
	// v[i]가 1인 값만 prime 백터에 추가해 집합 생성
	vector<int> prime;
	for(int i=2; i<=n; i++){
		if(v[i]) prime.push_back(i);
	}

	// step1. 구간 합이 n보다 크면 st 위치에 있는 수 빼기
	// step2. 구간 합이 n보다 작으면 현재 en 위치 수 더하기
	// step3. 구간 합이 n과 같으면 ans++
	int st=0, en=0 , sum=0, ans=0;

	while(true){
		if(sum > n) sum -= prime[st++];
		else if(en == prime.size()) break; // en이 범위 내 마지막 소수라면
		else sum += prime[en++];

		if(sum == n) ans++;
	}

	cout << ans;
	
}
