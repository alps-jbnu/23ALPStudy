#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    int M;
    string s = "";
    string ans = "";

    cin >> s;
    // 연결리스트에 원소 할당
    list<char> li(s.begin(), s.end());

    // 커서위치를 입력된 문자 제일 끝에 위치
    auto cursor = li.end();
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        char cmd, c;
        cin >> cmd;

        if (cmd == 'L')
        {
            if (cursor != li.begin())
                cursor--;
        }
        else if (cmd == 'D')
        {
            if (cursor != li.end())
                cursor++;
        }
        else if (cmd == 'B')
        {
            if (cursor != li.begin()) // 맨 왼쪽이 아니라면
            {
                cursor--;
                cursor = li.erase(cursor); // 삭제
            }
        }
        else if (cmd == 'P')
        {
            cin >> c;
            li.insert(cursor, c); // 문자 c 삽입
        }
    }

    // 연결리스트 출력
    for (cursor = li.begin(); cursor != li.end(); cursor++)
        cout << *cursor;
}
