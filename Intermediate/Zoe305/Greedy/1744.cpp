#include <bits/stdc++.h>
using namespace std;

long long ans;
vector<int> seqP, seqN;
int N, t;

void seqSum(vector<int> v){
  while (1 < v.size()){
    ans += *(v.end() - 1) * *(v.end() - 2);
    v.pop_back();
    v.pop_back();
  }
  if (v.size())
    ans += v[0];
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> t;
    if (t == 1) ans++;
    else if (0 < t)
      seqP.push_back(t);
    else
      seqN.push_back(t);
  }
  sort(seqP.begin(), seqP.end());
  sort(seqN.begin(), seqN.end(), greater<>());
  seqSum(seqP);
  seqSum(seqN);

  cout << ans;
}

/*
숫자가 1이면 그냥 더하고
음수인 거 양수인 거 따로 배열을 만들어 정렬함
끝에서부터 두 개씩 곱하고 팝 시키기
*/