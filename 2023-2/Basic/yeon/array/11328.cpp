#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        
        string s1, s2;
        int arr[26] = {}; //문자 개수 저장

        cin >> s1 >> s2;

        //s1 문자 개수 저장 후 s2 문자의 개수를 빼내고 0이 아닌 arr이 존재할 경우 im 출력
        //0일 경우 strfry가 가능

        for(auto i: s1) arr[i-'a']++;
        for(auto j: s2) arr[j-'a']--;

        bool res = true;
        for(int i: arr){
            if(i != 0) res = false; //strfry가 불가능
        }

        if(res) cout << "Possible" << '\n';
        else cout << "Impossible" << '\n';
    }
    return 0;
}
