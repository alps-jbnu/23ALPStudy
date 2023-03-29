#include <iostream>
#include <string>
#include<algorithm>
#include <list>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n;
    list<char> l;
    cin >> n;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        l.clear();
        auto cursor = l.begin();
        
        for(int j = 0; j<s.length(); j++){
            if(s[j]=='-'&&cursor!=l.begin()){
                cursor = l.erase(--cursor);
                    
            }
            else if(s[j]=='<'){
                if(cursor != l.begin()) cursor--;
                
            }
            else if(s[j]=='>'){
                if(cursor!=l.end()) cursor ++;
                
            }
            else if(s[j] != '<' && s[j] != '>' && s[j] != '-'){
                l.insert(cursor,s[j]);
            }
        }
        for(cursor = l.begin(); cursor != l.end(); cursor++) cout << *cursor;
        cout << "\n";
    }
}

