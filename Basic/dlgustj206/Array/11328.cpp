#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s1, s2;
    cin>>n;
    while(n--){
        bool isPossible=true;
        cin>>s1>>s2;
        if(s1.length()!=s2.length()){
            cout<<"Impossible\n";
            continue;
        }
        int alphabet[26]={0};
        for(int i=0; i<s1.length(); i++){
            alphabet[s1[i]-'a']++;
            alphabet[s2[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(alphabet[i]!=0){
                isPossible=false;
                break;
            }
        }
        if(isPossible)
            cout<<"Possible\n";
        else
            cout<<"Impossible\n";
    }
}