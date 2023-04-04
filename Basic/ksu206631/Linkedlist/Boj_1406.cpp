#include <iostream>
#include <string>
#include<algorithm>
#include <list>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >>s;
    int m;
    cin >> m;
    list<char> l;
    for(auto c: s) l.push_back(c);
    auto cursor = l.end();
    for(int i = 0; i<m; i++){
        char op;
        cin >> op;
        if(op=='L'){
            if(cursor!=l.begin()) cursor--;
        }
        else if(op=='D'){
            if(cursor!=l.end()) cursor++;
        }
        else if(op=='B'){
            if(cursor!=l.begin()){
                
                cursor--;
                cursor = l.erase(cursor);
            }
        }
        else if(op=='P'){
            char add;
            cin >> add;
            l.insert(cursor, add);
        }
    }
    for(auto c : l) cout << c;
   
}
