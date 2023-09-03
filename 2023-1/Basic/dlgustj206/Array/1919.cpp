#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int alphabet1[26];
int alphabet2[26];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt=0;
    string s1, s2;
    cin>>s1>>s2;
    //두 문자열의 길이가 다를 수도 있다는 거 생각하기!!
    for(int i=0; i<s1.length(); i++) alphabet1[s1[i]-'a']++;
    for(int i=0; i<s2.length(); i++) alphabet2[s2[i]-'a']++;
    for(int i=0; i<26; i++){
        if(alphabet1[i]!=alphabet2[i])
            cnt+=abs(alphabet1[i]-alphabet2[i]);
    }
    cout<<cnt;
}