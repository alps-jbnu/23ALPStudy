#include <iostream>
#include <list>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        list <char> L = {};
        auto s = L.begin();

        string str;
        cin >> str;

        for(auto i: str){ //문자 탐색
            if(i == '<'){ //왼쪽으로 1만큼 움직일 것
                if(s != L.begin()) s--;
            } else if(i == '>'){ //오른쪽으로 1만큼
                if(s != L.end()) s++;
            } else if(i == '-'){ //왼쪽에 있는 문자 erase
                if(s != L.begin()){
                    s--;
                    s = L.erase(s);
                }
            } else{
                L.insert(s, i); //그렇지 않을 경우 해당하는 s 위치에 i 추가 ((list에 추가
            }
        }

        for(auto j: L) cout << j;
        cout << '\n';
    }

    return 0;
}
