#include <iostream>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> L;

    string w;
    cin >>w;

    for(auto c: w){
        L.push_back(c);
    }
    auto t = L.end();//커서

    int m;
    cin >> m;
    
    for(int i=0; i<m; i++){
        char b;
        cin >>b;
        if(b=='P'){
            char c;
            cin >> c;
            L.insert(t,c);
        }
        else if(b=='L'){
            if(t!= L.begin()){
                t--;
            }
        }
        else if(b=='D'){
            if(t!=L.end()){
                t++;
            }

        }
        else if(b=='B'){
            if(t != L.begin()){
                t--;
                t = L.erase(t);
            }
        }
    }

    for(auto i : L) cout <<i;
    cout<<'\n';

    return 0;

}