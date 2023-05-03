#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

	int n;
	cin >> n;
    
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

	int en=0, st=0;
    long long ans =0; // 중복 없는 수열일 때 100,000 * (100,000 + 1) / 2 => long long

    map<int, int> m; // st~en까지 수열에 포함된 수가 등장하는 횟수 저장
    m[a[st]] = 1;

	while(true){
        while(en < n-1 && m[a[en+1]] == 0){ // a[en+1]이 기존 수열에 포함 되지 않은 경우
            en++;
            m[a[en]]++; // en길이 늘려주고, a[en]을 수열에 포함 시킴
        }
        if(st >= n || en >= n) break;

        ans += en - st + 1;
        m[a[st]]--;
        st++;
    }

	cout << ans;
	
}
