#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  deque<int> DQ;
  int N,M,num,cnt=0;

  cin>>N>>M;
  for (int i=1;i<=N;i++){
    DQ.push_back(i);
  }
  for(int i=0;i<M;i++){
    cin>>num;
    int idx = find(DQ.begin(),DQ.end(),num) - DQ.begin();  //함수의 존재를 몰랐음
                                                           //DQ.begin()을 빼는 이유는 find의 반환형은 iterator인데 int로 바꾸기 위함으로 추정
    while(num != DQ.front()) {
      if (idx < DQ.size()-idx){
        DQ.push_back(DQ.front());
        DQ.pop_front();
      } 
      else {
        DQ.push_front(DQ.back());
        DQ.pop_back();
      }
      cnt++;
    }
    DQ.pop_front();
  }
  cout << cnt;
}
