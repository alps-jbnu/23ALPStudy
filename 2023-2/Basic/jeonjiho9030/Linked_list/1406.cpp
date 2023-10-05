#include <bits/stdc++.h>
using namespace std;
					//STL list를 사용
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string init;
  cin >> init;
  list<char> L;
  for (auto c : init) L.push_back(c);		//리스트에 문자열 삽입
  auto cursor = L.end();			//처음 커서는 끝에 놓음
  int q;
  cin >> q;
  while (q--) {
    char op;
    cin >> op;				//명령어 입력
    if (op == 'P') {				//P가 입력되면
      char add;
      cin >> add;
      L.insert(cursor, add);			//문자열 커서 위치에 삽입
    }
    else if (op == 'L') {			//L이 입력됐을 때
      if (cursor != L.begin()) cursor--;		//커서의 위치가 맨 앞이 아니라면 왼쪽으로 커서 이동
    }
    else if (op == 'D') {			//D가 입력됐을 때
      if (cursor != L.end()) cursor++;		//커서의 위치가 맨 뒤가 아니라면 오른쪽으로 커서 이동
    }
    else { 					//B가 입력됐을 때
      if (cursor != L.begin()) {			//커서의 위치가 맨 앞이 아니라면
        cursor--;				//커서를 왼쪽으로 이동하고
        cursor = L.erase(cursor);		//리스트에서 삭제
      }
    }
  }
  for (auto c : L) cout << c;
}
