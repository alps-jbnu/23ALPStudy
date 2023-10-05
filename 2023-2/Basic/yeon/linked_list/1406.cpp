#include <iostream>
#include <list> //STL list 사용

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    list <char> v; //벡터 생성

    for(auto i: str) v.push_back(i);
    auto cur = v.end();

    int t;
    cin >> t;

    while(t--){
        char c;
        cin >> c;
        
        if(c == 'L'){
            //커서를 왼쪽으로 한 칸 옮김(커서가 문장의 맨 앞이면 무시)
            if(cur != v.begin()) cur--;
        } else if(c == 'D'){
            //커서를 오른쪽으로
            if(cur != v.end()) cur++;
        } else if(c == 'P'){
            char add;
            cin >> add; //add라는 문자 추가
            v.insert(cur, add);
        } else{
            //'B' - 커서 왼쪽에 있는 문자 삭제(커서가 문장의 맨 앞이면 무시)
            if(cur != v.begin()){
                cur--; //커서 위치 이동
                cur = v.erase(cur);
            }
        }
        
    }

    for(auto j: v) cout << j;

    return 0;

}
