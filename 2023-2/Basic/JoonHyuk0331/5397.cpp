#include <iostream>
#include <string>
#include <list>
using namespace std;

void key_loger(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;//문자열입력받기(list에 넣을)

    list<char> L;
    auto cursor = L.begin();//리스트 초기화 밑 커서 배치

    //for (auto c : init) L.push_back(c); 하나씩 집어넣는거라 필요없음
    
    for (int i = 0; i < str.length(); i++) 
    {
        if (str[i] == '<') {
            if (cursor != L.begin()) cursor--;
        }
        else if (str[i] == '>') {
            if (cursor != L.end()) cursor++;
        }
        else if (str[i] == '-') {
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
                /*erase(literlator) 리터레이터가 가리키는 원소 삭제
                이후 제거된 원소의 다음값이 리턴됨*/
            }
        }
        else{//그냥 영어대소문자 입력
            L.insert(cursor, str[i]);
        }
    }

    for (auto c : L) cout << c;
    cout << '\n';   
}

int main(void) {
    int i = 0;
    cin >> i;
    for (int k = 0; k < i; k++) {
        key_loger();
    }
}
