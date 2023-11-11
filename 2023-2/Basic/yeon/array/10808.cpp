#include <iostream>

using namespace std;

int main()
{
    string str;
    int arr[26] = {0}; //알파벳 담을 것
    
    cin >> str;
    
    for(int i=0; i<str.size(); i++){
        arr[str[i]-'a']++; //알파벳이 해당되는 인덱스 증가
    }
    for(int i=0; i<26; i++){
        cout << arr[i] << ' ';
    }

    return 0;
}

///////////////////

//freq 배열 사용

/*
int freq[26];
int main(){
    string str;
    cin >> str;
    for(auto c: str) freq[c-'a']++;
    for(int i=0; i<26; i++) cout << freq[i] << ' ';
}
*/


/////////////

/*정답 코드

#include <bits/stdc++.h>
using namespace std;

int freq[26];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for(auto c : s)
    freq[c-'a']++;
  for(int i = 0; i < 26; i++)
    cout << freq[i] << ' ';
}

*/
