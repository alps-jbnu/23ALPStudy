#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a,a+n);

	int en=0, mn = 0x7fffffff; // 0x7ffffff로 하니 오답 => mn을 엄청 큰 값으로 설정 해야한다.

	for(int st=0; st<n; st++){
		while(en<n && a[en]-a[st] < m) en++; // en-st가 m이상이 될 때 까지 en증가
		if(en==n) break; // en이 범위 밖을 벗어날 시 종료
		mn = min(mn, a[en]-a[st]); // m이상이 되면 mn 값 갱신
	}
	cout << mn;
}
